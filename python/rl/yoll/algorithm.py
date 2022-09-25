import math
import random
from typing import Tuple

from layers.net import PolicyNet
from .dicts import _path_id_dict
from .chess import *
from torch import Tensor, softmax


class PolicyNetEvaluator:

    def __init__(self, policy_net: PolicyNet):
        self.policy_net = policy_net
        self.chessboard: Chessboard = ...
        self.all_legal_paths: List[ChessPath] = ...

    def predict(self) -> Tuple[Tensor, ChessPath]:
        ...

    def sample(self) -> Tuple[Tensor, ChessPath]:
        """抽样获得动作
        return：
            Tuple[Tensor, ChessPath]: 路径对应的 onehot, 路径
        """
        path_probs = [path.value for path in self.all_legal_paths]
        ret_path = random.choices(population=self.all_legal_paths, weights=path_probs)[0]
        return ret_path.one_hot(), ret_path

    def observe_and_sample(self, obs_chessboard: Chessboard) -> Tuple[Tensor, ChessPath]:
        """观察棋盘，并获得抽样动作"""
        self._observe_chessboard(obs_chessboard=obs_chessboard)
        return self.sample()

    def _observe_chessboard(self, obs_chessboard: Chessboard) -> None:
        """观察棋盘
        args:
            chessboard: 棋盘
        return：
            None
        """
        self.chessboard = obs_chessboard
        self.all_legal_paths = obs_chessboard.get_all_paths(Chessboard.POSITIVE_SIDE)
        self._get_legal_path_prob()
        self._soft_max_legal_path()

    # def learn(self, obs: Tensor, action: Tensor, reward: int, optimizer):
    #     """进行策略梯度学习
    #     args:
    #         obs: observations，观察值，即棋盘
    #         action: 动作
    #         reward: 奖励
    #         optimizer: 优化器
    #     """
    #     act_prob = self.policy_net(obs)
    #     log_prob =

    def _get_legal_path_prob(self):
        """获得所有合法路径的概率
        由于策略网络的输出包含所有可能动作，因此将合法的动作筛选出来。
        output = policy_net(input)
        """
        # board_input = self.chessboard.to_tensor().view(1, 14, 10, 9)
        board_input = torch.unsqueeze(self.chessboard.to_tensor(), dim=0)
        with torch.no_grad():
            output = self.policy_net(board_input)
            paths_prob = softmax(output, dim=1)

        for path in self.all_legal_paths:
            path_id = _path_id_dict[str(path)]
            path.value = float(paths_prob[0][path_id])

    def _soft_max_legal_path(self):
        sum_exp_value = 0
        for path in self.all_legal_paths:
            path.value = math.exp(path.value)
            sum_exp_value += path.value

        for path in self.all_legal_paths:
            path.value /= sum_exp_value


class MCTSSearcher:
    pass
