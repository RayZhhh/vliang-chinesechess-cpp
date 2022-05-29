//
// Created by 张睿 on 2022/5/29.
//

#ifndef VLIANG_CHINESE_CHESS_QUIESCENCE_H
#define VLIANG_CHINESE_CHESS_QUIESCENCE_H

#include "tree_search.h"


class Quiescence : public TreeSearch {
public:
    explicit Quiescence(Chessboard &board) : TreeSearch(board) {}

    int quiescence(ChessPath &path, int alpha, int beta, int depth, int colorSign);

    int quiescence_with_memory_eval(ChessPath &path, int alpha, int beta, int depth, int colorSign);

    int eval_path_val(const ChessPath &path, int depth) override;
};

#endif //VLIANG_CHINESE_CHESS_QUIESCENCE_H
