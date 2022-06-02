//
// Created by 张睿 on 2022/5/25.
//

#ifndef VLIANG_CHINESE_CHESS_MULTI_THREAD_EVALUATOR_H
#define VLIANG_CHINESE_CHESS_MULTI_THREAD_EVALUATOR_H

#include "tree_search.h"
#include "tree_creator.h"
#include <thread>
#include <ctime>


class MultiThreadEvaluator {
public:

    TreeType tree_type;
    Chessboard board;
    int depth;
    int color_sign;

    bool print_res =  true;

    MultiThreadEvaluator(Chessboard chessboard, int depth, TreeType tree_type) {
        this->board = chessboard;
        this->depth = depth;
        this->tree_type = tree_type;
        this->color_sign=TreeSearch::MIN_LAYER_SIGN;
    }

    MultiThreadEvaluator(Chessboard chessboard, int depth, TreeType tree_type, int color_sign) {
        this->board = chessboard;
        this->depth = depth;
        this->tree_type = tree_type;
        this->color_sign=color_sign;
    }

    ChessPath get_best_path();
};


#endif //VLIANG_CHINESE_CHESS_MULTI_THREAD_EVALUATOR_H
