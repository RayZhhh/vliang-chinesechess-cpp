//
// Created by 张睿 on 2022/5/24.
//

#include "../include/tree_search.h"

CTSL::HashMap<int, TableMsg*> TreeSearch::tran_table_max;

CTSL::HashMap<int, TableMsg*> TreeSearch::tran_table_min;


void TreeSearch::update_lo_bound(int lo_bound, int color_sign, int depth) {
    int ch_hash = this->chessboard.get_hash();

    TableMsg *msg;
    bool find_ch;

    if (color_sign == MAX_LAYER_SIGN) {
        find_ch = tran_table_max.find(ch_hash, msg);
    } else {
        find_ch = tran_table_min.find(ch_hash, msg);
    }

    // 如果能找到当前盘面
    if (find_ch) {
        if (depth > msg->loDepth) {
            msg->lowerBound = lo_bound;
            msg->loDepth = depth;
        } else if (depth == msg->loDepth) {
            msg->lowerBound = msg->lowerBound > lo_bound ? msg->lowerBound : lo_bound;
        }
    } else {
        auto tmp = new TableMsg;
        tmp->lowerBound = lo_bound;
        tmp->loDepth = depth;
        if (color_sign == MAX_LAYER_SIGN) {
            tran_table_max.insert(ch_hash, tmp);
        } else {
            tran_table_min.insert(ch_hash, tmp);
        }
    }
}


void TreeSearch::update_up_bound(int up_bound, int color_sign, int depth) {
    int ch_hash = this->chessboard.get_hash();
    TableMsg *msg;
    bool find_ch;

    if (color_sign == MAX_LAYER_SIGN) {
        find_ch = tran_table_max.find(ch_hash, msg);
    } else {
        find_ch = tran_table_min.find(ch_hash, msg);
    }

    // 如果能找到当前盘面
    if (find_ch) {
        if (depth > msg->upDepth) {
            msg->upperBound = up_bound;
            msg->upDepth = depth;
        } else if (depth == msg->upDepth) {
            msg->upperBound = msg->upperBound > up_bound ? msg->upperBound : up_bound;
        }
    } else {
        auto tmp = new TableMsg;
        tmp->upperBound = up_bound;
        tmp->upDepth = depth;
        if (color_sign == MAX_LAYER_SIGN) {
            tran_table_max.insert(ch_hash, tmp);
        } else {
            tran_table_min.insert(ch_hash, tmp);
        }
    }
}
