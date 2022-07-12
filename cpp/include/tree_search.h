//
// Created by 张睿 on 2022/5/24.
//

#ifndef VLIANG_CHINESE_CHESS_TREE_SEARCH_H
#define VLIANG_CHINESE_CHESS_TREE_SEARCH_H

#include "chessboard.h"
#include "transition_table.hpp"

class TableMsg;

class TreeSearch;


class TreeSearch {
public:
    const static int ALPHA_INIT_VAL = -9999;
    const static int BETA_INIT_VAL = 9999;

    const static int MAX_EVAL_VAL = 8888;
    const static int MIN_EVAL_VAL = -8888;

    const static int MIN_LAYER_SIGN = 1;
    const static int MAX_LAYER_SIGN = -1;

    const static int QUIESCENCE_MAX_DEPTH = 8;

    Chessboard chessboard;

    int search_depth{};

    explicit TreeSearch(Chessboard &chessboard) {
        for (int i = 0; i < CHESSBOARD_ROWS; i++) {
            for (int j = 0; j < CHESSBOARD_COLS; ++j) {
                this->chessboard.board[i][j] = chessboard.board[i][j];
            }
        }
    }

    virtual int eval_path_val(const ChessPath &path, int depth) { return 0; }

    virtual int eval_path_val(const ChessPath &path, int depth, int color_sign) { return 0; }

    TranTable<TableMsg> tran_table_max;
    TranTable<TableMsg> tran_table_min;

    void update_lo_bound(TableMsg *msg, int lo_bound, int color_sign, int depth, int hash, int ver, ChessPath &path);

    void update_up_bound(TableMsg *msg, int up_bound, int color_sign, int depth, int hash, int ver, ChessPath &path);
};


class TableMsg {
public:
    TableMsg() : up_bound(TreeSearch::BETA_INIT_VAL), lo_bound(TreeSearch::ALPHA_INIT_VAL), up_depth(0), lo_depth(0) {
    }

    int up_bound = TreeSearch::BETA_INIT_VAL;
    int lo_bound = TreeSearch::ALPHA_INIT_VAL;
    int up_depth = 0;
    int lo_depth = 0;

    ChessPath best_path;
};


#endif //VLIANG_CHINESE_CHESS_TREE_SEARCH_H
