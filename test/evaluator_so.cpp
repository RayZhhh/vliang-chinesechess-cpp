//
// Created by 张睿 on 2022/8/9.
//


#include <iostream>
#include <cstring>
#include "../cpp/include/evaluator.h"

extern "C"
void test() {
    Chessboard chessboard;
    ChessPath path = ChessPath(2, 1, 2, 4, 0);
    chessboard.move_chess(path);

    auto eva = MultiThreadEvaluator(chessboard, 8, TreeType::MTDF);
    eva.get_best_path();
}