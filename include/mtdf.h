//
// Created by 张睿 on 2022/5/27.
//

#ifndef VLIANG_CHINESE_CHESS_MTDF_H
#define VLIANG_CHINESE_CHESS_MTDF_H

#include "tree_search.h"
#include "alpha_beta.h"
#include "quiescence.h"


class MTDF_Searching : public AlphaBetaWithMemory {
public:
    explicit MTDF_Searching(Chessboard &board) : AlphaBetaWithMemory(board) {}

    int mtdf_search(ChessPath &chess_path, int beta, int depth, int color_sign) {
        int val = beta;
        int upperBound = MAX_EVAL_VAL;
        int lowerBound = MIN_EVAL_VAL;
        while (lowerBound < upperBound) {
            if (val == lowerBound) {
                beta = val + 1;
            } else {
                beta = val;
            }
            // 进行一个以 [beta - 1, beta] 为零窗口的记忆化搜索
            val = alpha_beta_with_memory_eval(chess_path, beta - 1, beta, depth, color_sign);
            if (val < beta) {
                upperBound = val;
            } else {
                lowerBound = val;
            }
        }
        return val;
    }

    int eval_path_val(const ChessPath &path, int depth) override {
        this->search_depth = depth;
        return this->mtdf_search(const_cast<ChessPath &>(path), 0, depth, MIN_LAYER_SIGN);
    }
};


class MTDF_Quiescence_Searching : public Quiescence {
public:
    explicit MTDF_Quiescence_Searching(Chessboard &board) : Quiescence(board) {}

    int mtdf_quiescence_search(ChessPath &chess_path, int beta, int depth, int color_sign) {
        int val = beta;
        int upperBound = MAX_EVAL_VAL;
        int lowerBound = MIN_EVAL_VAL;
        while (lowerBound < upperBound) {
            if (val == lowerBound) {
                beta = val + 1;
            } else {
                beta = val;
            }
            // 进行一个以 [beta - 1, beta] 为零窗口的记忆化搜索
            val = quiescence_with_memory_eval(chess_path, beta - 1, beta, depth, color_sign);
            if (val < beta) {
                upperBound = val;
            } else {
                lowerBound = val;
            }
        }
        return val;
    }

    int eval_path_val(const ChessPath &path, int depth) override {
        this->search_depth = depth;
        return this->mtdf_quiescence_search(const_cast<ChessPath &>(path), 0, depth, MIN_LAYER_SIGN);
    }
};


#endif //VLIANG_CHINESE_CHESS_MTDF_H
