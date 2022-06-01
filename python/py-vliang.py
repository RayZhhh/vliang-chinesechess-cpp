import subprocess


class TreeType:
    ALPHA_BETA = "ALPHA_BETA"
    ALPHA_BETA_WITH_MEMORY = "ALPHA_BETA_WITH_MEMORY"
    MTDF = "MTDF"
    QUIE = "QUIE"


class ChessPath:
    def __init__(self, from_x=0, from_y=0, to_x=0, to_y=0, eat=0):
        self.from_x = from_x
        self.from_y = from_y
        self.to_x = to_x
        self.to_y = to_y
        self.eat = eat
        self.value = 0

    def __str__(self):
        return "ChessPath { <" + str(self.from_x) + ", " + str(self.from_y) + "> to <" + str(self.to_x) + ", " + str(
            self.to_y) + "> eat " + str(self.eat) + "}"


def num2char(chess_id):
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


class Chessboard:
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
            print("%6s" % num2char(i), end="")
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


class MultiThreadEvaluator:
    """
    --Invoke [vliang_py_interface.exe] as the interface.
    --The cpp implementation of [vliang_py_interface.exe] locates at https://github.com/RayZhhh/vliang-chinesechess-cpp.
    --Support for multi-threaded evaluation.
    """

    def __init__(self, interface_path: str, chessboard: Chessboard, tree_type, depth: int, res_path: str):
        self.interface_path = interface_path
        self.chessboard = chessboard
        self.tree_type = tree_type
        self.depth = depth
        self.res_path = res_path

    def get_best_path(self):
        board_str = self.chessboard.parse_to_interface_str()
        subprocess.run([self.interface_path, board_str, self.tree_type, str(self.depth), self.res_path])
        fin = open(self.res_path, 'r')
        path_res = fin.readline()
        res_arr = path_res.split(",")
        return ChessPath(int(res_arr[0]), int(res_arr[1]), int(res_arr[2]), int(res_arr[3]), int(res_arr[4]))


if __name__ == '__main__':
    board = Chessboard()
    board.move_chess(ChessPath(2, 1, 2, 4))
    board.print_chessboard()
    evaluator = MultiThreadEvaluator("bin/vliang_py_interface", board, TreeType.MTDF, 8, "res.txt")
    print(evaluator.get_best_path())

