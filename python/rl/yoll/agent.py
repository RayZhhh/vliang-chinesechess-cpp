import math
import random
from typing import Tuple

from layers.net import PolicyNet
from .dicts import _path_id_dict
from .chess import *
from .algorithm import PolicyNetEvaluator


class Step:
    def __init__(self, chessboard, action, reward):

        # 以 Tensor 形式保存棋盘
        if isinstance(chessboard, Chessboard):
            self.chessboard = chessboard.to_tensor()
        else:
            self.chessboard = chessboard

        # 以 one-hot 形式保存action
        if isinstance(action, ChessPath):
            self.action = action.one_hot()
        else:
            self.action = action

        # 回报，类型为 int
        self.reward = reward


class Episode:
    def __init__(self):
        self._observation = []
        self._action = []
        self._reward = []

    def __getitem__(self, item):
        return self._observation[item], self._action[item], self._reward[item]

    def append_step(self, chessboard, action, reward):
        # 以 Tensor 形式保存棋盘
        if isinstance(chessboard, Chessboard):
            self._observation.append(chessboard.to_tensor())
        else:
            self._observation.append(chessboard)

        # 以 one-hot 形式保存action
        if isinstance(action, ChessPath):
            self._action.append(action.one_hot())
        else:
            self._action.append(action)

        # 回报，类型为 int
        self._reward.append(reward)

    def clear(self):
        self.__init__()


class Agent:

    def __init__(self, policy_net_evaluator: PolicyNetEvaluator):
        self.policy_net_evaluator = policy_net_evaluator

    def learn(self, obs: Tensor, action: Tensor, reward: int, optimizer):
        """进行策略梯度学习
        args:
            obs: observations，观察值，即棋盘
            action: 动作
            reward: 奖励
            optimizer: 优化器
        """
        act_prob = self.policy_net(obs)
        log_prob =