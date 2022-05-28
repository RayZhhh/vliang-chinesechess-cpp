//
// Created by 张睿 on 2022/5/27.
//

#ifndef VLIANG_CHINESE_CHESS_MTDF_H
#define VLIANG_CHINESE_CHESS_MTDF_H

#include "tree_search.h"


class MTDF : public AlphaBeta {
public:

    explicit MTDF(Chessboard &board) : AlphaBeta(board) {}


    int mtdf_search(ChessPath &chessPath, int beta, int depth, int colorSign) {
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
            val = alpha_beta_eval(chessPath, beta - 1, beta, depth, colorSign);
            if (val < beta) {
                upperBound = val;
            } else {
                lowerBound = val;
            }
        }
        return val;
    }


    int eval_path_val(const ChessPath &path, int depth) override {
        return this->mtdf_search(const_cast<ChessPath &>(path), 0, depth, MIN_LAYER_SIGN);
    }
};

#endif //VLIANG_CHINESE_CHESS_MTDF_H
