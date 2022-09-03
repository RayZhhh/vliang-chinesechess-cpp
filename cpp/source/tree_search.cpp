//
// Created by 张睿 on 2022/5/24.
//

#include "../include/tree_search.h"


void TreeSearchBase::update_lo_bound(TableMsg *msg, int lo_bound, int color_sign, int depth, int hash, int ver, ChessPath &path) {
    // 如果能找到当前盘面
    if (msg != nullptr) {

        // 当前局面搜索更深
        if (depth > msg->lo_depth) {
            msg->lo_bound = lo_bound;
            msg->lo_depth = depth;
            msg->best_path = path;
        } else if (depth == msg->lo_depth) {
//            msg->lo_bound = msg->lo_bound > lo_bound ? msg->lo_bound : lo_bound;
//            msg->best_path = path;
            if (msg->lo_bound < lo_bound) {
                msg->lo_bound = lo_bound;
                msg->best_path = path;
            }
        }

    } else { // 没有找到盘面，新建置换表并进行保存

        auto tmp = new TableMsg();
        tmp->lo_bound = lo_bound;
        tmp->lo_depth = depth;
        tmp->best_path = path;

        // 保存到对应搜索层的置换表
        if (color_sign == MAX_LAYER_SIGN) {
            tran_table_max.add_table(tmp, hash, ver);
        } else {
            tran_table_min.add_table(tmp, hash, ver);
        }
    }
}


void TreeSearchBase::update_up_bound(TableMsg *msg, int up_bound, int color_sign, int depth, int hash, int ver, ChessPath &path) {

    // 如果能找到当前盘面
    if (msg != nullptr) {

        // 当前局面搜索更深
        if (depth > msg->up_depth) {
            msg->up_bound = up_bound;
            msg->up_depth = depth;
            msg->best_path = path;
        } else if (depth == msg->up_depth) {
//            msg->up_bound = msg->up_bound > up_bound ? msg->up_bound : up_bound;
//            msg->best_path = path;
            if (msg->up_bound > up_bound) {
                msg->up_bound = up_bound;
                msg->best_path = path;
            }
        }

    } else { // 没有找到盘面，新建置换表并进行保存
        auto tmp = new TableMsg();
        tmp->up_bound = up_bound;
        tmp->up_depth = depth;
        tmp->best_path = path;

        // 保存到对应搜索层的置换表
        if (color_sign == MAX_LAYER_SIGN) {
            tran_table_max.add_table(tmp, hash, ver);
        } else {
            tran_table_min.add_table(tmp, hash, ver);
        }
    }
}

