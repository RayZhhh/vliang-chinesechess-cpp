//
// Created by 张睿 on 2022/5/24.
//

#ifndef VLIANG_CHINESE_CHESS_TREE_SEARCH_H
#define VLIANG_CHINESE_CHESS_TREE_SEARCH_H

#include "chessboard.h"
#include "../hashmap/HashMap.h"

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

    Chessboard chessboard;

    int depth;

    TreeSearch(Chessboard &chessboard) {
        for (int i = 0; i < CHESSBOARD_ROWS; i++) {
            for (int j = 0; j < CHESSBOARD_COLS; ++j) {
                this->chessboard.board[i][j] = chessboard.board[i][j];
            }
        }
    }

    virtual int eval_path_val(const ChessPath &path, int depth) { return 0; }

    static CTSL::HashMap<int, TableMsg*> tran_table_max;

    static CTSL::HashMap<int, TableMsg*> tran_table_min;

    void update_lo_bound(int lo_bound, int color_sign, int depth);

    void update_up_bound(int up_bound, int color_sign, int depth);
};


class TableMsg {
public:
    int upperBound = TreeSearch::BETA_INIT_VAL;
    int lowerBound = TreeSearch::ALPHA_INIT_VAL;
    int upDepth;
    int loDepth;
};


#endif //VLIANG_CHINESE_CHESS_TREE_SEARCH_H
