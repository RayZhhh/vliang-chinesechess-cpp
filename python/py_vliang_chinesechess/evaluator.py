import subprocess
import time

from python.py_vliang_chinesechess.chessboard import Chessboard
from python.py_vliang_chinesechess.path import ChessPath


class TreeType:
    ALPHA_BETA = "ALPHA_BETA"
    ALPHA_BETA_WITH_MEMORY = "ALPHA_BETA_WITH_MEMORY"
    MTDF = "MTDF"
    QUIE = "QUIE"
    ITER_DEEP = "ITER_DEEP"
    MTDF_QUIE = "MTDF_QUIE"


class MultiThreadEvaluator:
    """
    --Invoke [vliang_py_interface.exe] as the interface.
    --The cpp implementation of [vliang_py_interface.exe] locates at https://github.com/RayZhhh/vliang-chinesechess-cpp.
    --Support for multi-threaded evaluation.
    """

    def __init__(self, interface_path, chessboard, tree_type, depth, color_sign, res_path='.res.txt'):
        self.interface_path = interface_path
        self.chessboard = chessboard
        self.tree_type = tree_type
        self.depth = depth
        self.res_path = res_path
        self.color_sign = color_sign

    def get_best_path(self):
        board_str = self.chessboard.parse_to_interface_str()
        subprocess.run(
            [self.interface_path, board_str, self.tree_type, str(self.depth), self.color_sign, self.res_path])
        fin = open(self.res_path, 'r')
        path_res = fin.readline()
        res_arr = path_res.split(",")
        return ChessPath(int(res_arr[0]), int(res_arr[1]), int(res_arr[2]), int(res_arr[3]), int(res_arr[4]))


class DeepeningMultiThreadEvaluator(MultiThreadEvaluator):
    """
    --The search depth will be automatically added while evaluating
    """

    def __init__(self, interface_path, chessboard, tree_type, depth, color_sign, res_path):
        super(DeepeningMultiThreadEvaluator, self).__init__(interface_path, chessboard, tree_type, depth, color_sign,
                                                            res_path)
        self.time_threshold_in_second = 0.8

    def get_best_path(self):
        real_search_depth = self.depth
        while True:
            beg = time.time()
            path = MultiThreadEvaluator.get_best_path(self)
            if time.time() - beg > self.time_threshold_in_second or \
                    (self.color_sign == Chessboard.MIN_LAYER_SIGN and path.value >= 7000) or \
                    (self.color_sign == Chessboard.MAX_LAYER_SIGN and path.value <= -7000):
                break
            else:
                self.depth += 2
        self.depth = real_search_depth
        return path


if __name__ == '__main__':
    board = Chessboard()
    board.move_chess(ChessPath(2, 1, 2, 4))
    board.print_chessboard()
    evaluator = MultiThreadEvaluator("../bin/vliang_py_interface", board, TreeType.MTDF, 8, Chessboard.MAX_LAYER_SIGN,
                                     ".res.txt")
    print(evaluator.get_best_path())
