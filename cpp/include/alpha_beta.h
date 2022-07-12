//
// Created by 张睿 on 2022/5/24.
//

#ifndef VLIANG_CHINESE_CHESS_ALPHA_BETA_H
#define VLIANG_CHINESE_CHESS_ALPHA_BETA_H

#include "tree_search.h"

class AlphaBeta : public TreeSearch {
public:
    explicit AlphaBeta(Chessboard &chessboard) : TreeSearch(chessboard) {
    }

    int eval_path_val(const ChessPath &path, int depth) override;

    int eval_path_val(const ChessPath &path, int depth, int color_sign) override;

    int alpha_beta_eval(ChessPath &path, int alpha, int beta, int depth, int colorSign);
};


class AlphaBetaWithMemory : public TreeSearch {
public:
    explicit AlphaBetaWithMemory(Chessboard &chessboard) : TreeSearch(chessboard) {
    }

    int eval_path_val(const ChessPath &path, int depth) override;

    int eval_path_val(const ChessPath &path, int depth, int color_sign) override;

    int alpha_beta_with_memory_eval(ChessPath &path, int alpha, int beta, int depth, int colorSign);
};


#endif //VLIANG_CHINESE_CHESS_ALPHA_BETA_H
