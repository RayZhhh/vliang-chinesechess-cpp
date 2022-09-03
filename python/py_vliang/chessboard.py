import subprocess

from .path import ChessPath


class Chessboard:
    MIN_LAYER_SIGN = "MIN_LAYER_SIGN"
    MAX_LAYER_SIGN = "MAX_LAYER_SIGN"

    def __init__(self):
        self.board = [
            [-1, -2, -3, -4, -5, -4, -3, -2, -1],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, -6, 0, 0, 0, 0, 0, -6, 0],
            [-7, 0, -7, 0, -7, 0, -7, 0, -7],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [7, 0, 7, 0, 7, 0, 7, 0, 7],
            [0, 6, 0, 0, 0, 0, 0, 6, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [1, 2, 3, 4, 5, 4, 3, 2, 1]]

    def parse_to_interface_str(self):
        ret = ""
        for row in self.board:
            for i in row:
                ret += str(i + 20)
        return ret

    def move_chess(self, path: ChessPath):
        self.board[path.to_x][path.to_y] = self.board[path.from_x][path.from_y]
        self.board[path.from_x][path.from_y] = 0

    def undo_move_chess(self, path: ChessPath):
        self.board[path.from_x][path.from_y] = self.board[path.to_x][path.to_y]
        self.board[path.to_x][path.to_y] = path.eat

    def print_chessboard(self):
        print("%6s" % "", end="")
        for i in range(0, 9):
            print("%6d" % i, end="")
        print("")
        print("     --------------------------------------------------------\n")
        for i in range(0, 10):
            print("%6s" % self.num2char(i), end="")
            for j in range(0, 9):
                if self.board[i][j] == 0:
                    print("%6c" % '.', end="")
                else:
                    print("%6d" % self.board[i][j], end="")
            print("\n")
        print("\n")

    def clear_board(self):
        self.board = [
            [-1, -2, -3, -4, -5, -4, -3, -2, -1],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, -6, 0, 0, 0, 0, 0, -6, 0],
            [-7, 0, -7, 0, -7, 0, -7, 0, -7],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [7, 0, 7, 0, 7, 0, 7, 0, 7],
            [0, 6, 0, 0, 0, 0, 0, 6, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [1, 2, 3, 4, 5, 4, 3, 2, 1]]

    def num2char(self, chess_id: int):
        if chess_id == 0:
            return "零"
        elif chess_id == 1:
            return "一"
        elif chess_id == 2:
            return "二"
        elif chess_id == 3:
            return "三"
        elif chess_id == 4:
            return "四"
        elif chess_id == 5:
            return "五"
        elif chess_id == 6:
            return "六"
        elif chess_id == 7:
            return "七"
        elif chess_id == 8:
            return "八"
        elif chess_id == 9:
            return "九"

    def who_wins(self) -> (bool, int):
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
