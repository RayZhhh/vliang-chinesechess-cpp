//
// Created by 张睿 on 2022/5/24.
//

#include "../include/tree_search.h"


void TreeSearch::update_lo_bound(int lo_bound, int color_sign, int depth) {
    int ch_hash = this->chessboard.get_hash();
    int ch_ver = this->chessboard.get_verify();

    TableMsg *msg;

    if (color_sign == MAX_LAYER_SIGN) {
        msg = tran_table_max.get_table(ch_hash, ch_ver);
    } else {
        msg = tran_table_min.get_table(ch_hash, ch_ver);
    }

    // 如果能找到当前盘面
    if (msg != nullptr) {
        // 当前局面搜索更深
        if (depth > msg->lo_depth) {
            msg->lo_bound = lo_bound;
            msg->lo_depth = depth;
        } else if (depth == msg->lo_depth) {
            msg->lo_bound = msg->lo_bound > lo_bound ? msg->lo_bound : lo_bound;
        }
    } else {
        auto tmp = new TableMsg();
        tmp->lo_bound = lo_bound;
        tmp->lo_depth = depth;
        if (color_sign == MAX_LAYER_SIGN) {
            tran_table_max.add_table(tmp, ch_hash, ch_ver);
        } else {
            tran_table_min.add_table(tmp, ch_hash, ch_ver);
        }
    }
}


void TreeSearch::update_up_bound(int up_bound, int color_sign, int depth) {
    int ch_hash = this->chessboard.get_hash();
    int ch_ver = this->chessboard.get_verify();

    TableMsg *msg;

    if (color_sign == MAX_LAYER_SIGN) {
        msg = tran_table_max.get_table(ch_hash, ch_ver);
    } else {
        msg = tran_table_min.get_table(ch_hash, ch_ver);
    }

    // 如果能找到当前盘面
    if (msg != nullptr) {
        // 当前局面搜索更深
        if (depth > msg->up_depth) {
            msg->up_bound = up_bound;
            msg->up_depth = depth;
        } else if (depth == msg->up_depth) {
            msg->up_bound = msg->up_bound > up_bound ? msg->up_bound : up_bound;
        }
    } else {
        auto tmp = new TableMsg();
        tmp->up_bound = up_bound;
        tmp->up_depth = depth;
        if (color_sign == MAX_LAYER_SIGN) {
            tran_table_max.add_table(tmp, ch_hash, ch_ver);
        } else {
            tran_table_min.add_table(tmp, ch_hash, ch_ver);
        }
    }
}

