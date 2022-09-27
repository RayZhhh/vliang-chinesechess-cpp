import math
import random
from typing import Tuple

import torch

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
        self._observation: List[Tensor] = []
        self._action : List[Tensor]= []
        self._value: List[float] = []
        self.step_num = 0

    def __getitem__(self, item):
        return self._observation[item], self._action[item], self._value[item]

    def __len__(self):
        assert self.step_num == len(self._action)
        return self.step_num

    def append_step(self, chessboard, action, value=0):
        """添加步骤"""
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
        self._value.append(value)
        self.step_num += 1

    def clear(self):
        self.__init__()

    def set_value(self, reward):
        """对每个step，将最终的到的reward
        """
        for i in range(0, self.step_num):
            self._value[i] = reward

    def to_tensor(self) -> Tuple[Tensor, Tensor, List[float]]:
        """将当前 episode 的内容转化成 Tensor"""
        if self.step_num == 0:
            raise RuntimeError('No step in episode.')

        obs_tensors = [torch.unsqueeze(i, dim=0) for i in self._observation]
        act_tensors = [torch.unsqueeze(i, dim=0) for i in self._action]
        return torch.cat(obs_tensors, dim=0), torch.cat(act_tensors, dim=0), self._value

class PolicyGradiant:

    def __init__(self, trained_policy_net: PolicyNet, opponent_net: PolicyNet, max_step=60, max_step_reward=0,):
        """
        PolicyGradiant 初始化
        :param trained_policy_net: 被训练的网络。
        :param opponent_net:       对手网络，不会被训练，会和被训练网络进行下棋对战。
        :param max_step:           最大的步数，如果超过这个步数会停止对弈，相应的 reward 由 max_step_reward 定义。
        :param max_step_reward:    如果对弈超过最大步数 max_step 定义的 reward
        """
        self.trained_policy_net = trained_policy_net
        self.opponent_net = opponent_net
        self.trained_evaluator = PolicyNetEvaluator(policy_net=trained_policy_net)
        self.oppo_evaluator = PolicyNetEvaluator(policy_net=opponent_net)
        self.max_step = max_step
        self.max_step_reward = max_step_reward

    def _gen_an_episode(self) -> Episode:
        episode = Episode()
        board = Chessboard()
        step_count = 0

        while True:
            # 由被训练的网络生成的路径
            _, path1 = self.trained_policy_net.sample()

            # 将 observation，action 加入 episode
            episode.append_step(chessboard=board, action=path1)

            # 落子
            board.move_chess(path1)
            step_count += 1

            # 判断胜负
            sb_wins, who = board.who_wins()
            if sb_wins:
                reward = 1
                break

            # 另一方网络生成的路径
            _, path2 = self.oppo_evaluator.sample()
            board.move_chess(path2)
            step_count += 1

            # 判断胜负
            sb_wins, who = board.who_wins()
            if sb_wins:
                reward = -1
                break

            # 如果超过定义的最大步数，那么停止对弈
            if step_count >= self.max_step:
                reward = self.max_step_reward
                break

        episode.set_value(reward=reward)
        return episode

    def learn_from_episode(self, obs: Tensor, action: Tensor, reward: int, optimizer):
        """进行策略梯度学习
        args:
            obs: observations，观察值，即棋盘
            action: 动作
            reward: 奖励
            optimizer: 优化器
        """
        # act_prob = self.policy_net(obs)
        # log_prob =
        pass