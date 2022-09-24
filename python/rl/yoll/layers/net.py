from . import blocks

import torch
import torch.nn as nn


class PolicyNet(nn.Module):
    """PolicyNet -- 策略网络"""

    def __init__(self, from_file=None, residual_num=9, feature_cloning=True):
        super(PolicyNet, self).__init__()
        self.conv_block = blocks.ConvBlock()
        self.residual_tower = blocks.ResidualTower(block_num=residual_num)
        self.policy_head = blocks.PolicyHead()
        self.feature_cloning = feature_cloning

    def forward(self, x):
        x = self.conv_block(x)
        x = self.residual_tower(x)
        x = self.policy_head(x)
        return x
        # if self.feature_cloning:
        #     return x
        # else:
        #     # output = G * log(pi(a|s;w)) * (-1)
        #     x = torch.log(x)
        #     return -x

    def init_weights(self):
        """初始化卷积层，全连接层的权重。
        这些权重在首次训练时作为预训练权重。
        """
        for module in self.modules():
            # 初始化卷积层
            if isinstance(module, nn.Conv2d):
                torch.nn.init.xavier_normal_(module.weight.data)  # Xavier 正态分布

            # 初始化 batch norm 层
            if isinstance(module, nn.BatchNorm2d):
                module.weight.data.fill_(1)
                module.bias.data.zero_()


class ValueNet(nn.Module):
    pass
