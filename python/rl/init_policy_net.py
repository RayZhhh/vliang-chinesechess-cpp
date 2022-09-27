# 使用 behavior-cloning 初始化 PolicyNet
# 将棋谱作为输入，让 PolicyNet 具有基本的决策能力
#
# 参数的更新将不使用策略梯度方法，而是用分类问题的方法训练 PolicyNet，本质上是监督学习


from datetime import datetime

from typing import List, Tuple

from yoll.layers.net import PolicyNet
from yoll.dicts import *
from yoll.chess import *
from yoll.evaluator import *

import torch.nn as nn
from torch.utils.data import Dataset, DataLoader
import torch.optim.lr_scheduler
from torch import optim

TRAIN_BATCH = 32
TEST_BATCH = 100
LR_INIT = 0.001
EPOCH_IN_THIS_RUN = 80
DEVICE = ...
SAVE_FILE_BASE = './weights/yoll_policy_9_epoch_'


def select_device():
    global DEVICE
    if torch.cuda.is_available():  # 如果 cuda 设备可以使用
        DEVICE = torch.device('cuda:0')
    elif torch.backends.mps.is_available():  # 如果基于 metal 的设备可以使用
        DEVICE = torch.device('mps')
    else:  # 使用 cpu
        DEVICE = torch.device('cpu')


select_device()


def get_weight_path(epoch_num: int) -> str:
    return SAVE_FILE_BASE + str(epoch_num) + '.pkl'


# ================================================ 数据集准备 ================================================
class PolicyNetInitDataset(Dataset):

    def __init__(self, txt_path):
        super(PolicyNetInitDataset, self).__init__()
        board_path: List[Tuple[str, str]] = []

        with open(txt_path, 'r') as dataf:
            for line in dataf:
                line.strip('\n')
                board_str, path_str = line.split('#')[0], line.split('#')[1]
                board_path.append((board_str, path_str))

        self.board_path = board_path

    def __getitem__(self, index):
        board_str, path_str = self.board_path[index]
        board = Chessboard(board_seq=board_str)
        path = ChessPath(path_str=path_str)
        return board.to_tensor(), path.one_hot()

    def __len__(self):
        return len(self.board_path)


# ============================================== 数据集 测试集 ==============================================
train_data = PolicyNetInitDataset(txt_path='data/cchess_data.txt')
train_loader = DataLoader(dataset=train_data, batch_size=TRAIN_BATCH, shuffle=True)

test_data = PolicyNetInitDataset(txt_path='data/cchess_data.txt')
test_loader = DataLoader(dataset=test_data, batch_size=TEST_BATCH, shuffle=False)
# =========================================================================================================


# ================================================ 网络 ================================================
policy_net = PolicyNet(residual_num=9)
policy_net.init_weights()
policy_net.to(device=DEVICE)
# =====================================================================================================


# ================================================ 微调学习率 ================================================
# policy_net 中所有全连接层的参数的 id
fc_params_in_policy_net = [id(i) for i in policy_net.policy_head.linear.parameters()]

# 在所有网络权重中，排除上面的全连接层的权重，剩下的作为 base_params
# base_params = [p for p in policy_net.parameters() if id(p) not in fc_params_id_in_policy_net]
base_params = filter(lambda p: id(p) not in fc_params_in_policy_net, policy_net.parameters())

optimizer = optim.SGD(
    [{'params': base_params},
     {'params': policy_net.policy_head.linear.parameters(), 'lr': 0.005}],
    lr=0.005, momentum=0.9, weight_decay=1e-4)
# ===========================================================================================================


criterion = nn.CrossEntropyLoss()
scheduler = torch.optim.lr_scheduler.StepLR(optimizer, step_size=50, gamma=0.1)


def train(epoch):
    """训练一个epoch"""
    loss_sigma = 0.0  # 统计一定训练量的总损失，在打印训练结果时进行平均处理
    scheduler.step()  # 更新学习率

    for i, data in enumerate(train_loader):

        # 棋盘作为输入，路径的 one hot 作为lables
        inputs, labels = data
        inputs, labels = inputs.to(DEVICE), labels.to(DEVICE)

        # 梯度清零，前向传播，反向传播
        optimizer.zero_grad()
        outputs = policy_net(inputs)
        loss = criterion(outputs, labels)
        loss.backward()
        optimizer.step()

        # 累加 loss
        loss_sigma += loss.item()

        # 打印训练信息
        if i % 10 == 9:
            loss_avg = loss_sigma / 10
            loss_sigma = 0

            print('Training: Epoch[{:0>3}/{:0>3}] Iteration[{:0>3}/{:0>3}] Loss: {:.4f}'.format(
                epoch + 1, EPOCH_IN_THIS_RUN, i + 1, len(train_loader), loss_avg))


# def test():
#     for i, data in enumerate(test_loader):
#         board, path = data
#
#         with torch.no_grad():
#             outputs = policy_net(board)


def save_state(epoch):
    path_backup = get_weight_path(epoch_num=epoch)
    state = {'net': policy_net.state_dict(),
             'epoch': epoch,
             'optimizer': optimizer.state_dict()
             }
    torch.save(state, path_backup)
    path = 'weights/yoll_policy_9_net.pkl'
    torch.save(state, path)


FIRST_TRAIN = True

if __name__ == '__main__':
    if FIRST_TRAIN:
        # 第一次训练
        train(epoch=0)
        save_state(epoch=0)

    checkpoints = torch.load('weights/yoll_policy_9_net.pkl')
    policy_net.load_state_dict(checkpoints['net'])
    optimizer.load_state_dict(checkpoints['optimizer'])
    epoch = checkpoints['epoch']

    for cur_epoch in range(EPOCH_IN_THIS_RUN):
        epoch += 1
        train(epoch=epoch)
        if cur_epoch % 10 == 0:
            save_state(epoch=epoch)

    # net = PolicyNet()
    # net.load_state_dict(torch.load('weights/yoll_policy_9_epoch_80.pkl')['net'])
    # board = Chessboard()
    # board.print_chessboard()
    #
    # while True:
    #     pathstr = input('input path')
    #     board.move_chess(ChessPath(path_str=pathstr))
    #     board.print_chessboard()
    #
    #     # out = net(board.to_tensor().view(1, 14, 10, 9))
    #     # _, pid = torch.max(out.data, dim=1)
    #     # pid = pid[0].data
    #     # print(ChessPath(path_num=int(pid)))
    #     path = PolicyNetEvaluator(policy_net=net, chessboard=board).get_path(choice='sample')
    #     # path = ChessPath(path_num=int(pid))
    #     board.move_chess(path)
    #     board.print_chessboard()
