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

    void estimate_init_value(ChessPath &chess_path, int depth, int color_sign) {
        this->mtdf_init_value = alpha_beta_with_memory_eval(chess_path, ALPHA_INIT_VAL, BETA_INIT_VAL, depth - 2,
                                                            color_sign);
    }

    int mtdf_init_value = 0;

    bool estimate_MTDF_init_value = true;

    int mtdf_eval(ChessPath &chess_path, int beta, int depth, int color_sign) {
        if (this->estimate_MTDF_init_value) {
            estimate_init_value(chess_path, depth, color_sign);
        }

        int val = this->mtdf_init_value;

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
        return this->mtdf_eval(const_cast<ChessPath &>(path), 0, depth, MIN_LAYER_SIGN);
    }

    int eval_path_val(const ChessPath &path, int depth, int color_sign) override {
        this->search_depth = depth;
        return this->mtdf_eval(const_cast<ChessPath &>(path), 0, depth, color_sign);
    }
};


class MTDF_Quiescence_Searching : public Quiescence {
public:
    explicit MTDF_Quiescence_Searching(Chessboard &board) : Quiescence(board) {}

    void estimate_init_value(ChessPath &chess_path, int depth, int color_sign) {
        this->mtdf_init_value = alpha_beta_quiescence_with_memory_eval(chess_path, ALPHA_INIT_VAL, BETA_INIT_VAL,
                                                                       depth - 2,
                                                                       color_sign);
    }

    int mtdf_init_value = 0;

    bool estimate_MTDF_init_value = true;

    int mtdf_quiescence_search(ChessPath &chess_path, int beta, int depth, int color_sign) {
        if (this->estimate_MTDF_init_value) {
            estimate_init_value(chess_path, depth, color_sign);
        }

        int val = this->mtdf_init_value;

        int upperBound = MAX_EVAL_VAL;
        int lowerBound = MIN_EVAL_VAL;

        while (lowerBound < upperBound) {
            if (val == lowerBound) {
                beta = val + 1;
            } else {
                beta = val;
            }
            // 进行一个以 [beta - 1, beta] 为零窗口的记忆化搜索
            val = alpha_beta_quiescence_with_memory_eval(chess_path, beta - 1, beta, depth, color_sign);
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

    int eval_path_val(const ChessPath &path, int depth, int color_sign) override {
        this->search_depth = depth;
        return this->mtdf_quiescence_search(const_cast<ChessPath &>(path), 0, depth, color_sign);
    }
};


#endif //VLIANG_CHINESE_CHESS_MTDF_H
