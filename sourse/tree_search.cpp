//
// Created by 张睿 on 2022/5/24.
//

#include "../include/tree_search.h"

CTSL::HashMap<double, TableMsg> TreeSearch::tran_table_max;

CTSL::HashMap<double, TableMsg> TreeSearch::tran_table_min;


void TreeSearch::update_lo_bound(int lo_bound, int color_sign, int depth) {
    double ch_hash = this->chessboard.get_hash();

    TableMsg msg;
    bool find_ch;

    if (color_sign == MAX_LAYER_SIGN) {
        find_ch = tran_table_max.find(ch_hash, msg);
    } else {
        find_ch = tran_table_min.find(ch_hash, msg);
    }

    // 如果能找到当前盘面
    if (find_ch) {
        if (depth > msg.lo_depth) {
            msg.lower_bound = lo_bound;
            msg.lo_depth = depth;
        } else if (depth == msg.lo_depth) {
            msg.lower_bound = msg.lower_bound > lo_bound ? msg.lower_bound : lo_bound;
        }
    } else {
        TableMsg tmp;
        tmp.lower_bound = lo_bound;
        tmp.lo_depth = depth;
        if (color_sign == MAX_LAYER_SIGN) {
            tran_table_max.insert(ch_hash, tmp);
        } else {
            tran_table_min.insert(ch_hash, tmp);
        }
    }
}


void TreeSearch::update_up_bound(int up_bound, int color_sign, int depth) {
    double ch_hash = this->chessboard.get_hash();

    TableMsg msg;
    bool find_ch;

    if (color_sign == MAX_LAYER_SIGN) {
        find_ch = tran_table_max.find(ch_hash, msg);
    } else {
        find_ch = tran_table_min.find(ch_hash, msg);
    }

    // 如果能找到当前盘面
    if (find_ch) {
        if (depth > msg.up_depth) {
            msg.upper_bound = up_bound;
            msg.up_depth = depth;
        } else if (depth == msg.up_depth) {
            msg.upper_bound = msg.upper_bound > up_bound ? msg.upper_bound : up_bound;
        }
    } else {
        TableMsg tmp;
        tmp.upper_bound = up_bound;
        tmp.up_depth = depth;
        if (color_sign == MAX_LAYER_SIGN) {
            tran_table_max.insert(ch_hash, tmp);
        } else {
            tran_table_min.insert(ch_hash, tmp);
        }
    }
}
