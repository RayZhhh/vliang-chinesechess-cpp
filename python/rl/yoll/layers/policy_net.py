import blocks
from blocks import *


class PolicyNet(nn.Module):
    """PolicyNet -- 策略网络"""

    def __init__(self, from_file=None, residual_num=7):
        super(PolicyNet, self).__init__()
        self.conv_block = blocks.ConvBlock()
        self.residual_tower = blocks.ResidualTower(block_num=residual_num)
        self.policy_head = blocks.PolicyHead()

    def forward(self, x):
        x = self.conv_block(x)
        x = self.residual_tower(x)
        x = self.policy_head(x)
        return x

    def init_weights(self):
        """初始化卷积层，全连接层的权重。
        这些权重在首次训练时作为预训练权重。
        """
        for module in self.modules():
            # 初始化卷积层
            if isinstance(module, nn.Conv2d):
                torch.nn.init.xavier_normal_(module.weight.data)

            # 初始化 batch norm 层
            if isinstance(module, nn.BatchNorm2d):
                module.weight.data.fill(1)
                module.bias.data.zero_()

    def init_from_file(self, path: str):
        """从文件中初始化 PolicyNet
        模型文件中需要包含初始化 PolicyNet 的三个 key：'conv_block'，'res_tower'，'policy_head'。
        """
        with torch.load(path) as w_dict:
            if 'conv_block' in w_dict and 'res_tower' in w_dict and 'policy_head' in w_dict:
                self.conv_block.load_state_dict(w_dict['conv_block'])
                self.residual_tower.load_state_dict(w_dict['res_tower'])
                self.policy_head.load_state_dict(w_dict['policy_head'])

            else:
                raise KeyError('Missing key "conv_block" or "res_tower" or "policy_head" in keys')


#     def get_model_state_dict(self) -> collections.OrderedDict:
#         conv_state_dict = self.conv_block.state_dict()
#         res_blocks_state_dict = self.residual_tower.state_dict()
#         policy_head_state_dict = self.policy_head.state_dict()
#         w_dict = OrderedDict()
#         w_dict['conv_block'] = conv_state_dict
#         w_dict['res_blocks'] = res_blocks_state_dict
#         w_dict['policy_head'] = policy_head_state_dict
#         return w_dict
#

#
#
# def save_policy_net(model: PolicyNet, path, first_save=False, **kwargs):
#     with torch.load(path) as w_dict:
#         conv_state_dict = model.conv_block.state_dict()
#         res_blocks_state_dict = model.residual_tower.state_dict()
#         policy_head_state_dict = model.policy_head.state_dict()
#
#         w_dict = OrderedDict()
#         w_dict['conv_block'] = conv_state_dict
#         w_dict['res_blocks'] = res_blocks_state_dict
#         w_dict['policy_head'] = policy_head_state_dict
#
#
#
# print(w_dict is None)
