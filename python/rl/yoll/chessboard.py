import torch
from torch import Tensor
from .dicts import _path_num_dict, _num_path_dict
from .dicts import _num_paths
import copy


class Chess:
    JU = 1  # 车
    MA = 2  # 马
    XIANG = 3  # 象
    SHI = 4  # 士
    JIANG = 5  # 将
    PAO = 6  # 炮
    ZU = 7  # 卒


class ChessPath:

    def __init__(self, from_x=-1, from_y=-1, to_x=-1, to_y=-1, eat=None, value=0, path_num=None, path_str=None):
        self.eat, self.value = None, None

        if path_str is not None:
            self.from_path_str(path_str)

        elif path_num is not None:
            self.from_num_path_dict(path_num)

        else:
            self.from_x, self.from_y, self.to_x, self.to_y = from_x, from_y, to_x, to_y

    def __repr__(self):
        return '(%d, %d) => (%d, %d)\n' % (self.from_x, self.from_y, self.to_x, self.to_y)

    def __str__(self):
        return str(self.from_x) + str(self.from_y) + str(self.to_x) + str(self.to_y)

    def get_path_num(self):
        """获得当前路径的编号"""
        return _path_num_dict[str(self)]

    def symmetry(self):
        """路径左右对称"""
        self.from_y, self.to_y = 8 - self.from_y, 8 - self.to_y

    def side_exchange(self):
        """将当前路径转换为双方交换后的路径"""
        self.from_x, self.from_y, self.to_x, self.to_y = \
            9 - self.from_x, 8 - self.from_y, 9 - self.to_x, 8 - self.to_y

    def one_hot(self) -> Tensor:
        """将路径转化成 one-hot 编码"""
        ret = torch.zeros(_num_paths)
        ret[_path_num_dict[str(self)]] = 1
        return ret

    def from_num_path_dict(self, num):
        """通过编号来初始化 ChessPath 对象"""
        path_str = _num_path_dict[num]
        self.from_x, self.from_y, self.to_x, self.to_y = \
            int(path_str[0]), int(path_str[1]), int(path_str[2]), int(path_str[3])

    def from_path_str(self, path_str):
        """通过路径来初始化 ChessPath 对象"""
        self.from_x, self.from_y, self.to_x, self.to_y = \
            int(path_str[0]), int(path_str[1]), int(path_str[2]), int(path_str[3])


def _num2char(num):
    num2char_dict = {0: '零', 1: '一', 2: '二', 3: '三', 4: '四', 5: '五', 6: '六', 7: '七', 8: '八', 9: '九'}
    return num2char_dict[num]


class Chessboard:

    def __init__(self, board_seq=None):
        self.board = [[0 for j in range(9)] for i in range(10)]

        if board_seq is not None:
            self.load_from_sequence(board_seq=board_seq)
            return

        self.init_chessboard()

    def _get_path_of_1(self, x, y):
        color_sign = 1 if self.board[x][y] > 0 else -1
        ret = []

        # 向上寻找路径
        if x >= 1:
            for i in range(x - 1, -1, -1):
                if self.board[i][y] == 0:
                    ret.append(ChessPath(x, y, i, y))
                elif self.board[i][y] * color_sign > 0:
                    break
                elif self.board[i][y] * color_sign < 0:
                    ret.append(ChessPath(x, y, i, y, self.board[i][y]))
                    break

        # 向下寻找路径
        if x <= 8:
            for i in range(x + 1, 10):
                if self.board[i][y] == 0:
                    ret.append(ChessPath(x, y, i, y))
                elif self.board[i][y] * color_sign > 0:
                    break
                elif self.board[i][y] * color_sign < 0:
                    ret.append(ChessPath(x, y, i, y, self.board[i][y]))
                    break

        # 向左寻找路径
        if y >= 1:
            for i in range(y - 1, -1, -1):
                if self.board[x][i] == 0:
                    ret.append(ChessPath(x, y, x, i))
                elif self.board[x][i] * color_sign > 0:
                    break
                elif self.board[x][i] * color_sign < 0:
                    ret.append(ChessPath(x, y, x, i, self.board[x][i]))
                    break

        # 向右寻找路径
        if y <= 7:
            for i in range(y + 1, 9):
                if self.board[x][i] == 0:
                    ret.append(ChessPath(x, y, x, i))
                elif self.board[x][i] * color_sign > 0:
                    break
                elif self.board[x][i] * color_sign < 0:
                    ret.append(ChessPath(x, y, x, i, self.board[x][i]))
                    break

        return ret

    def _get_path_of_2(self, x, y):
        color_sign = 1 if self.board[x][y] > 0 else -1
        ret = []

        # 左上
        if x >= 2 and y >= 1 and self.board[x - 1][y] == 0:
            if self.board[x - 2][y - 1] * color_sign <= 0:
                ret.append(ChessPath(x, y, x - 2, y - 1, self.board[x - 2][y - 1]))

        if x >= 1 and y >= 2 and self.board[x][y - 1] == 0:
            if self.board[x - 1][y - 2] * color_sign <= 0:
                ret.append(ChessPath(x, y, x - 1, y - 2, self.board[x - 1][y - 2]))

        # 右上方
        if x >= 2 and y <= 7 and self.board[x - 1][y] == 0:
            if self.board[x - 2][y + 1] * color_sign <= 0:
                ret.append(ChessPath(x, y, x - 2, y + 1, self.board[x - 2][y + 1]))

        if x >= 1 and y <= 6 and self.board[x][y + 1] == 0:
            if self.board[x - 1][y + 2] * color_sign <= 0:
                ret.append(ChessPath(x, y, x - 1, y + 2, self.board[x - 1][y + 2]))

        # 左下方
        if x <= 7 and y >= 1 and self.board[x + 1][y] == 0:
            if self.board[x + 2][y - 1] * color_sign <= 0:
                ret.append(ChessPath(x, y, x + 2, y - 1, self.board[x + 2][y - 1]))

        if x <= 8 and y >= 2 and self.board[x][y - 1] == 0:
            if self.board[x + 1][y - 2] * color_sign <= 0:
                ret.append(ChessPath(x, y, x + 1, y - 2, self.board[x + 1][y - 2]))

        # 右下方
        if x <= 7 and y <= 7 and self.board[x + 1][y] == 0:
            if self.board[x + 2][y + 1] * color_sign <= 0:
                ret.append(ChessPath(x, y, x + 2, y + 1, self.board[x + 2][y + 1]))

        if x <= 8 and y <= 6 and self.board[x][y + 1] == 0:
            if self.board[x + 1][y + 2] * color_sign <= 0:
                ret.append(ChessPath(x, y, x + 1, y + 2, self.board[x + 1][y + 2]))

        return ret

    def _get_path_of_3(self, x, y):
        color_sign = 1 if self.board[x][y] > 0 else -1
        ret = []

        if color_sign > 0:
            # 左上
            if (x == 9 and y == 2) or (x == 7 and y == 4) or (x == 9 and y == 6) or (x == 7 and y == 8):
                if self.board[x - 1][y - 1] == 0 and self.board[x - 2][y - 2] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x - 2, y - 2, self.board[x - 2][y - 2]))

            # 右上
            if (x == 7 and y == 0) or (x == 9 and y == 2) or (x == 7 and y == 4) or (x == 9 and y == 6):
                if self.board[x - 1][y + 1] == 0 and self.board[x - 2][y + 2] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x - 2, y + 2, self.board[x - 2][y + 2]))

            # 左下
            if (x == 5 and y == 2) or (x == 7 and y == 4) or (x == 5 and y == 6) or (x == 7 and y == 8):
                if self.board[x + 1][y - 1] == 0 and self.board[x + 2][y - 2] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x + 2, y - 2, self.board[x + 2][y - 2]))

            # 右下
            if (x == 7 and y == 0) or (x == 5 and y == 2) or (x == 7 and y == 4) or (x == 5 and y == 6):
                if self.board[x + 1][y + 1] == 0 and self.board[x + 2][y + 2] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x + 2, y + 2, self.board[x + 2][y + 2]))
        else:
            # 左上
            if (x == 4 and y == 2) or (x == 2 and y == 4) or (x == 2 and y == 8) or (x == 4 and y == 6):
                if self.board[x - 1][y - 1] == 0 and self.board[x - 2][y - 2] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x - 2, y - 2, self.board[x - 2][y - 2]))

            # 右上
            if (x == 4 and y == 2) or (x == 2 and y == 0) or (x == 2 and y == 4) or (x == 4 and y == 6):
                if self.board[x - 1][y + 1] == 0 and self.board[x - 2][y + 2] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x - 2, y + 2, self.board[x - 2][y + 2]))

            # 左下
            if (x == 0 and y == 2) or (x == 2 and y == 4) or (x == 0 and y == 6) or (x == 2 and y == 8):
                if self.board[x + 1][y - 1] == 0 and self.board[x + 2][y - 2] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x + 2, y - 2, self.board[x + 2][y - 2]))

            # 右下
            if (x == 2 and y == 0) or (x == 0 and y == 2) or (x == 2 and y == 4) or (x == 0 and y == 6):
                if self.board[x + 1][y + 1] == 0 and self.board[x + 2][y + 2] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x + 2, y + 2, self.board[x + 2][y + 2]))

        return ret

    def _get_path_of_4(self, x, y):
        color_sign = 1 if self.board[x][y] > 0 else -1
        ret = []

        if color_sign > 0:
            # 左上
            if (x == 8 and y == 4) or (x == 9 and y == 5):
                if self.board[x - 1][y - 1] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x - 1, y - 1, self.board[x - 1][y - 1]))

            # 右上
            if (x == 8 and y == 4) or (x == 9 and y == 3):
                if self.board[x - 1][y + 1] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x - 1, y + 1, self.board[x - 1][y + 1]))

            # 左下
            if (x == 8 and y == 4) or (x == 7 and y == 5):
                if self.board[x + 1][y - 1] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x + 1, y - 1, self.board[x + 1][y - 1]))

            # 右下
            if (x == 8 and y == 4) or (x == 7 and y == 3):
                if self.board[x + 1][y + 1] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x + 1, y + 1, self.board[x + 1][y + 1]))

        else:
            # 左上
            if (x == 1 and y == 4) or (x == 2 and y == 5):
                if self.board[x - 1][y - 1] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x - 1, y - 1, self.board[x - 1][y - 1]))

            # 右上
            if (x == 1 and y == 4) or (x == 2 and y == 3):
                if self.board[x - 1][y + 1] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x - 1, y + 1, self.board[x - 1][y + 1]))

            # 左下
            if (x == 1 and y == 4) or (x == 0 and y == 5):
                if self.board[x + 1][y - 1] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x + 1, y - 1, self.board[x + 1][y - 1]))

            # 右下
            if (x == 1 and y == 4) or (x == 0 and y == 3):
                if self.board[x + 1][y + 1] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x + 1, y + 1, self.board[x + 1][y + 1]))

        return ret

    def _get_path_of_5(self, x, y):
        color_sign = 1 if self.board[x][y] > 0 else -1
        ret = []
        if color_sign > 0:
            # 上
            if x >= 8:
                if self.board[x - 1][y] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x - 1, y, self.board[x - 1][y]))

            # 下
            if x <= 8:
                if self.board[x + 1][y] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x + 1, y, self.board[x + 1][y]))

            # 左
            if y >= 4:
                if self.board[x][y - 1] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x, y - 1, self.board[x][y - 1]))

            # 右
            if y <= 4:
                if self.board[x][y + 1] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x, y + 1, self.board[x][y + 1]))

        else:
            # 上
            if x >= 1:
                if self.board[x - 1][y] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x - 1, y, self.board[x - 1][y]))

            # 下
            if x <= 1:
                if self.board[x + 1][y] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x + 1, y, self.board[x + 1][y]))

            # 左
            if y >= 4:
                if self.board[x][y - 1] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x, y - 1, self.board[x][y - 1]))

            # 右
            if y <= 4:
                if self.board[x][y + 1] * color_sign <= 0:
                    ret.append(ChessPath(x, y, x, y + 1, self.board[x][y + 1]))

        return ret

    def _get_path_of_6(self, x, y):
        color_sign = 1 if self.board[x][y] > 0 else -1
        ret = []
        # 上
        if x >= 1:
            i = x - 1
            while i >= 0:
                if self.board[i][y] == 0:
                    ret.append(ChessPath(x, y, i, y))
                    i -= 1
                else:
                    break

            if i >= 1:
                for j in range(i - 1, -1, -1):
                    if self.board[j][y] != 0:
                        # 对方棋子，可将其吃掉，退出循环
                        if self.board[j][y] * color_sign < 0:
                            ret.append(ChessPath(x, y, j, y, self.board[j][y]))
                            break
                        else:  # 己方棋子，退出循环
                            break

        # 下
        if x <= 8:
            i = x + 1
            while i <= 9:
                if self.board[i][y] == 0:
                    ret.append(ChessPath(x, y, i, y))
                    i += 1
                else:
                    break

            if i <= 8:
                for j in range(i + 1, 10):
                    if self.board[j][y] != 0:
                        # 对方棋子，可将其吃掉，退出循环
                        if self.board[j][y] * color_sign < 0:
                            ret.append(ChessPath(x, y, j, y, self.board[j][y]))
                            break
                        else:  # 己方棋子，退出循环
                            break

        # 左
        if y >= 1:
            i = y - 1
            while i >= 0:
                if self.board[x][i] == 0:
                    ret.append(ChessPath(x, y, x, i))
                    i -= 1
                else:
                    break

            if i >= 1:
                for j in range(i - 1, -1, -1):
                    if self.board[x][j] != 0:
                        if self.board[x][j] * color_sign < 0:
                            ret.append(ChessPath(x, y, x, j, self.board[x][j]))
                            break
                        else:
                            break

        # 右
        if y <= 7:
            i = y + 1
            while i <= 8:
                if self.board[x][i] == 0:
                    ret.append(ChessPath(x, y, x, i))
                    i += 1
                else:
                    break

            if i <= 7:
                for j in range(i + 1, 9):
                    if self.board[x][j] != 0:
                        if self.board[x][j] * color_sign < 0:
                            ret.append(ChessPath(x, y, x, j, self.board[x][j]))
                            break
                        else:
                            break

        return ret

    def _get_path_of_7(self, x, y):
        color_sign = 1 if self.board[x][y] > 0 else -1
        ret = []

        if color_sign > 0:
            # 上
            if x >= 1 and self.board[x - 1][y] * color_sign <= 0:
                ret.append(ChessPath(x, y, x - 1, y, self.board[x - 1][y]))

        else:
            # 下
            if x <= 8 and self.board[x + 1][y] * color_sign <= 0:
                ret.append(ChessPath(x, y, x + 1, y, self.board[x + 1][y]))

        # 过河后可以向左向右
        if (color_sign > 0 and x <= 4) or (color_sign < 0 and x >= 5):
            # 左
            if y >= 1 and self.board[x][y - 1] * color_sign <= 0:
                ret.append(ChessPath(x, y, x, y - 1, self.board[x][y - 1]))

            # 右
            if y <= 7 and self.board[x][y + 1] * color_sign <= 0:
                ret.append(ChessPath(x, y, x, y + 1, self.board[x][y + 1]))

        return ret

    def get_chess_path_of_id(self, x, y):
        func = [self._get_path_of_1, self._get_path_of_2, self._get_path_of_3, self._get_path_of_4,
                self._get_path_of_5, self._get_path_of_6, self._get_path_of_7]
        id = self.board[x][y] if self.board[x][y] > 0 else -self.board[x][y]
        return func[id - 1](x, y)

    def get_all_paths(self, color_sign):
        ret = []
        if color_sign > 0:
            for i in range(0, 10):
                for j in range(0, 9):
                    if self.board[i][j] > 0:
                        ret += self.get_chess_path_of_id(i, j)

        else:
            for i in range(0, 10):
                for j in range(0, 9):
                    if self.board[i][j] < 0:
                        ret += self.get_chess_path_of_id(i, j)

        return ret

    def move_chess(self, path):
        path.eat = self.board[path.to_x][path.to_y]
        self.board[path.to_x][path.to_y] = self.board[path.from_x][path.from_y]
        self.board[path.from_x][path.from_y] = 0

    def undo_move_chess(self, path):
        self.board[path.from_x][path.from_y] = self.board[path.to_x][path.to_y]
        self.board[path.to_x][path.to_y] = path.eat

    def init_chessboard(self):
        # 负数方
        self.board[0][0] = -Chess.JU
        self.board[0][1] = -Chess.MA
        self.board[0][2] = -Chess.XIANG
        self.board[0][3] = -Chess.SHI
        self.board[0][4] = -Chess.JIANG
        self.board[0][5] = -Chess.SHI
        self.board[0][6] = -Chess.XIANG
        self.board[0][7] = -Chess.MA
        self.board[0][8] = -Chess.JU
        self.board[2][1] = -Chess.PAO
        self.board[2][7] = -Chess.PAO
        self.board[3][0] = -Chess.ZU
        self.board[3][2] = -Chess.ZU
        self.board[3][4] = -Chess.ZU
        self.board[3][6] = -Chess.ZU
        self.board[3][8] = -Chess.ZU
        # 正数方
        self.board[9][0] = Chess.JU
        self.board[9][1] = Chess.MA
        self.board[9][2] = Chess.XIANG
        self.board[9][3] = Chess.SHI
        self.board[9][4] = Chess.JIANG
        self.board[9][5] = Chess.SHI
        self.board[9][6] = Chess.XIANG
        self.board[9][7] = Chess.MA
        self.board[9][8] = Chess.JU
        self.board[7][1] = Chess.PAO
        self.board[7][7] = Chess.PAO
        self.board[6][0] = Chess.ZU
        self.board[6][2] = Chess.ZU
        self.board[6][4] = Chess.ZU
        self.board[6][6] = Chess.ZU
        self.board[6][8] = Chess.ZU

    def clear_chessboard(self):
        for i in range(10):
            for j in range(9):
                self.board[i][j] = 0

    def print_chessboard(self):
        print("%6s" % "", end="")
        for i in range(0, 9):
            print("%6d" % i, end="")
        print("")
        print("     --------------------------------------------------------\n")
        for i in range(0, 10):
            print("%6s" % _num2char(i), end="")
            for j in range(0, 9):
                if self.board[i][j] == 0:
                    print("%6c" % '.', end="")
                else:
                    print("%6d" % self.board[i][j], end="")

            print("\n")

        print("\n")

    def is_general_face2face(self):
        """是否发生对将"""
        # 找到将的位置
        for i in range(0, 3):
            for j in range(3, 6):
                if self.board[i][j] == -5:
                    rx = i
                    ry = j

        # 找到将的位置
        for i in range(7, 10):
            for j in range(3, 6):
                if self.board[i][j] == 5:
                    sx = i
                    sy = j

        # 如果红黑双方的将不在一条线上，则肯定不会发生对将情况
        if ry != sy:
            return False

        for i in range(rx + 1, sx + 1):
            if self.board[i][ry] != 0:
                return False

        return True

    def to_tensor(self) -> Tensor:
        """将棋盘转化成 Tensor。
        Tensor 的维度为 [14, 10, 9]。双方的每种类型的棋子占用 Tensor 第1维的每次一层。
        """
        ret = torch.zeros(14, 10, 9)

        # 将每个点存放到 tensor 中
        for i in range(10):
            for j in range(9):
                chess_id = self.board[i][j]

                if chess_id == 0:
                    continue

                dim1 = chess_id + 7 if chess_id < 0 else chess_id + 6
                ret[dim1][i][j] = 1

        return ret

    def who_wins(self) -> (bool, int):
        """是否有人赢得了比赛"""
        is_find = False

        # 找到将的位置
        for i in range(0, 3):
            for j in range(3, 6):
                if self.board[i][j] == -5:
                    is_find = True

        if not is_find:
            return True, -1

        is_find = False

        # 找到将的位置
        for i in range(7, 10):
            for j in range(3, 6):
                if self.board[i][j] == 5:
                    is_find = True
        if not is_find:
            return True, 1

        return False, 0

    def to_board_sequence(self):
        """返回用字符串表示的棋盘
        转换方式：假设一个小棋盘是这样的
        [[0, -1, 2, 3],
         [1, -2, 0, 3]]
        那么输出的字符串为: '0, -1, 2, 3, 1, -2, 0, 3'
        即：按从上到下，从左到右的顺序便利棋盘上的每个位置，依次添加所有棋子，如果没有棋子用 '0' 表示，中间用 ',' 分隔。
        由于棋盘是 10 * 9 大小的中国象棋棋盘，因此序列中共有 90 个值。
        """
        ret = ''
        for i in range(10):
            for j in range(9):
                ret += str(self.board[i][j])
                if i != 9 or j != 8:
                    ret += ','

        return ret

    def load_from_sequence(self, board_seq: str):
        """用棋盘序列初始化棋盘"""
        seq = board_seq.split(',')
        pos = 0
        for i in range(0, 10):
            for j in range(0, 9):
                self.board[i][j] = int(seq[pos])
                pos += 1

    def symmetry(self):
        """将棋盘左右对称变换"""
        board = copy.deepcopy(self.board)
        for i in range(0, 10):
            for j in range(0, 9):
                board[i][j] = self.board[i][8 - j]

        self.board = board

    def side_exchange(self):
        """双方交换"""
        board = copy.deepcopy(self.board)
        for i in range(0, 10):
            for j in range(0, 9):
                board[i][j] = -self.board[9 - i][8 - j]
        self.board = board
