import copy
import math
import random

import torch
from abc import ABCMeta, abstractmethod

from typing import List

from .chess import Chessboard, ChessPath
from .layers.net import PolicyNet
from .dicts import _path_id_dict
from torch.nn.functional import softmax


class EvaluatorBase:
    __metaclass__ = ABCMeta

    def __init__(self, chessboard: Chessboard, side=Chessboard.POSITIVE_SIDE):
        self.chessboard = copy.deepcopy(chessboard)
        self.all_legal_paths = chessboard.get_all_paths(color_sign=Chessboard.POSITIVE_SIDE)
        all_legal_paths_str = [str(path) for path in self.all_legal_paths]
        self.all_legal_paths_set = set(all_legal_paths_str)

    @abstractmethod
    def get_path(self) -> ChessPath:
        pass

    def _is_legal_path(self, path: ChessPath) -> bool:
        return str(path) in self.all_legal_paths_set


class PolicyNetEvaluator(EvaluatorBase):

    def __init__(self, policy_net: PolicyNet, chessboard: Chessboard, side=Chessboard.POSITIVE_SIDE):
        super().__init__(chessboard=chessboard, side=side)
        self.policy_net = policy_net


    def get_path(self, choice='prob') -> ChessPath:
        """利用网络选择路径
        choice: default 'prob', option 'sample'
        """
        # 获取各种路径的概率
        self.__get_legal_path_prob()
        self.__soft_max_legal_path()

        # 返回在策略网络的输出中，概率最大的那个路径
        if choice == 'prob':
            # 按概率从大到小排序
            self.all_legal_paths.sort(key=lambda path: path.value, reverse=True)
            print(self.all_legal_paths)
            return self.all_legal_paths[0]

        # 根据策略网络对路径概率的预测，抽样获得路径
        if choice == 'sample':
            print(self.all_legal_paths)
            path_probs = [path.value for path in self.all_legal_paths]
            return random.choices(population=self.all_legal_paths, weights=path_probs)[0]

    def __get_legal_path_prob(self):
        board_input = self.chessboard.to_tensor().view(1, 14, 10, 9)
        output = self.policy_net(board_input)
        paths_prob = output #softmax(output, dim=1)
        print(paths_prob)

        for path in self.all_legal_paths:
            path_id = _path_id_dict[str(path)]
            path.value = float(paths_prob[0][path_id])

    def __soft_max_legal_path(self):
        sum_exp_value = 0
        for path in self.all_legal_paths:
            path.value = math.exp(path.value)
            sum_exp_value += path.value

        for path in self.all_legal_paths:
            path.value /= sum_exp_value
