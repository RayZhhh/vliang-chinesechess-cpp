import sys

import torch
import torch.nn as nn
from typing import List

INPUT_CHANNEL = 14
INPUT_HEIGHT = 10
INPUT_WIDTH = 9
NUM_PATHS = 2086


class ConvBlock(nn.Module):
    r"""ConvBlock
    input: [B, C=14, H=10, W=9]
    output: [B, C=128, H=10, W=9]
    """

    def __init__(self, in_channels=INPUT_CHANNEL, out_channels=128):
        super(ConvBlock, self).__init__()

        self.in_channels = in_channels
        self.out_channels = out_channels

        self.conv = nn.Conv2d(in_channels=self.in_channels, out_channels=self.out_channels, kernel_size=(3, 3),
                              stride=1, padding='same')
        self.batch_norm = nn.BatchNorm2d(num_features=self.out_channels, eps=1e-5, affine=True)

    def forward(self, x):
        x = self.conv(x)
        x = self.batch_norm(x)
        x = torch.relu(x)
        return x


class ResidualBlock(nn.Module):
    r"""ResidualBLock
    input: [B, C=128 H=10 W=9]
    output: [B, C=128 H=10 W=9]
    """

    def __init__(self, in_channels1=128, out_channels1=128, out_channels2=128):
        super(ResidualBlock, self).__init__()

        self.in_channels1 = in_channels1
        self.out_channels1 = out_channels1
        self.out_channels2 = out_channels2

        self.conv1 = nn.Conv2d(in_channels=self.in_channels1, out_channels=self.out_channels1, kernel_size=(3, 3),
                               padding='same')
        self.batch_norm1 = nn.BatchNorm2d(num_features=out_channels1, eps=1e-5, affine=True)
        self.conv2 = nn.Conv2d(in_channels=self.out_channels1, out_channels=self.out_channels2, kernel_size=(3, 3),
                               padding='same')
        self.batch_norm2 = nn.BatchNorm2d(num_features=out_channels2, eps=1e-5, affine=True)

    def forward(self, x):
        y = self.conv1(x)
        y = self.batch_norm1(y)
        y = torch.relu(y)
        y = self.conv2(y)
        y = self.batch_norm2(y)
        output = x + y
        output = torch.relu(output)
        return output


class ResidualTower(nn.Module):
    r"""ResidualBLocks
    input: [B, C=128 H=10 W=9]
    output: [B, C=128 H=10 W=9]
    """

    def __init__(self, block_num):
        super(ResidualTower, self).__init__()
        self.block_num = block_num
        self.residual_blocks = self._gen_blocks()

    def _gen_blocks(self) -> nn.Sequential:
        r"""每次调用 _gen_blocks 生成一个残差块序列，序列中的残差块个数由 self.block_num 定义"""
        blocks: List[nn.Module] = [ResidualBlock() for _ in range(self.block_num)]
        return nn.Sequential(*blocks)

    def forward(self, x):
        return self.residual_blocks(x)


class PolicyHead(nn.Module):
    r"""PolicyHead
    input: [B, C=128, H=10, W=9]
    output: [B, W=2086]
    """

    def __init__(self, in_channels=128, out_channels=2):
        super(PolicyHead, self).__init__()

        self.in_channels = in_channels
        self.out_channels = out_channels
        self.linear_in_features = self.out_channels * INPUT_WIDTH * INPUT_HEIGHT
        self.linear_out_features = NUM_PATHS

        self.conv = nn.Conv2d(in_channels=self.in_channels, out_channels=self.out_channels, kernel_size=(1, 1),
                              stride=1)
        self.batch_norm = nn.BatchNorm2d(num_features=self.out_channels, eps=1e-5, affine=True)
        self.linear = nn.Linear(in_features=self.linear_in_features, out_features=self.linear_out_features)

    def forward(self, x):
        x = self.conv(x)
        x = self.batch_norm(x)
        x = torch.relu(x)
        x = x.view(-1, self.linear_in_features)
        x = self.linear(x)
        return x


class ValueHead(nn.Module):
    def __init__(self):
        super(ValueHead, self).__init__()
        pass
