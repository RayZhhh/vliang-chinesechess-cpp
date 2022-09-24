//
// Created by 张睿 on 2022/5/24.
//

#ifndef VLIANG_CHINESE_CHESS_TREE_SEARCH_H
#define VLIANG_CHINESE_CHESS_TREE_SEARCH_H

#include "chessboard.h"
#include "transition_table.hpp"

class TableMsg;

class TreeSearchBase;


class TreeSearchBase {
public:
    /**
     * ALPHA 和 BETA 变量的初始值。
     *
     * 这两个值仅在常规的alpha-beta搜索中会被使用，使用 mtd(f) 方法进行零窗口搜索时 beta = alpha + 1，
     * 且 beta 和 alpha 的初始值可以为任意值。
     */
    const static int ALPHA_INIT_VAL = -9999;
    const static int BETA_INIT_VAL = 9999;

    /**
     * 盘面的最大值和最小值。
     *
     * 如果正数方将被吃，那么将停止搜索，并返回 MAX_EVAL_VALUE
     * 如果负数方将被吃，那么将停止搜索，并返回 MIN_EVAL_VALUE
     * 在一次搜索过程中，评估值在区间 [MIN_EVAL_VAL, MAX_EVAL_VALUE] 上
     */
    const static int MAX_EVAL_VAL = 8888;
    const static int MIN_EVAL_VAL = -8888;

    /**
     * 最大层和最小层的标识。用于在进行极大极小搜索时表明当前层的类型。
     *
     * MIN_LAYER_SIGN: 极小层，如果当前搜索到极小层，那么返回所有搜索结果中评估值最小的那个。
     * MAX_LAYER_SIGN: 极大层，如果当前搜索到极大层，那么返回所有搜索结果中评估值最大的那个。
     */
    const static int MIN_LAYER_SIGN = 1;
    const static int MAX_LAYER_SIGN = -1;

    /**
     * 搜索深度。
     *
     * 搜索在到达这个深度时将会进行棋盘价值评估并返回评估值。
     */
    int search_depth{};

    /**
     * 静态搜索中限制的最大深度。
     *
     * 当达到 search_depth 的常规搜索深度时，如果需要静态搜索且达到静态搜索条件（正在发生吃子），那么将出发静态搜索，
     * 这个变量表示静态搜索附加的额外搜索深度。即实际最大搜索深度为：search_depth + QUIESCENCE_MAX_DEPTH。
     */
    const static int QUIESCENCE_MAX_DEPTH = 8;

    /**
     * 棋盘。
     *
     * 为了方便多线程的进行，每个 TreeSearchBase 对象中含有一个内置棋盘，
     * 对于不同线程负责的搜索不同路径的任务，在进行模拟落子时互相不会干扰。
     */
    Chessboard chessboard;

    explicit TreeSearchBase(Chessboard &chessboard) {
        for (int i = 0; i < CHESSBOARD_ROWS; i++) {
            for (int j = 0; j < CHESSBOARD_COLS; ++j) {
                this->chessboard.board[i][j] = chessboard.board[i][j];
            }
        }
    }

    /**
     * 评估某个路径的价值。棋子颜色默认为 TreeSearchBase.MAX_LAYER_SIGN。在搜索时会为棋盘是正数的一方搜索价值。
     * @param path 路径
     * @param depth 搜索深度
     * @return 这个路径 path 的价值
     */
    virtual int eval_path_val(const ChessPath &path, int depth) { return 0; }

    /**
     * 评估某个路径的价值。可以指定棋子颜色。
     * @param path 路径
     * @param depth 搜索深度
     * @param color_sign 棋子颜色，一般传入 TreeSearchBase.MAX_LAYER_SIGN 或 TreeSearchBase.MIN_LAYER_SIGN
     * @return 这个路径 path 的价值
     */
    virtual int eval_path_val(const ChessPath &path, int depth, int color_sign) { return 0; }

    /**
     * 为不同层准备的置换表。
     *
     * tran_table_max: MAX_LAYER 进行搜索时会查询。
     * tran_table_min: MIN_LAYER 进行搜索时会查询。
     */
    TranTable<TableMsg> tran_table_max;
    TranTable<TableMsg> tran_table_min;

    /**
     * 更新当前置换表的下界。
     * 在触发了某些剪枝条件时会更新当前盘面评估值的下界。缩短下界值和上界值会加快搜索到真实值的速度。
     *
     * @param msg 置换表的指针
     * @param lo_bound 下界值
     * @param color_sign 颜色，TreeSearchBase.MAX_LAYER_SIGN 或 TreeSearchBase.MIN_LAYER_SIGN
     * @param depth 当前搜索深度
     * @param hash 哈希值
     * @param ver 校验值
     * @param path 导致下界变换的路径，下次找到这个置换表后优先搜索这个路径。
     */
    void update_lo_bound(TableMsg *msg, int lo_bound, int color_sign, int depth, int hash, int ver, ChessPath &path);

    /**
     * 更新当前置换表的上界。
     * 在触发了某些剪枝条件时会更新当前盘面评估值的上界。缩短下界值和上界值会加快搜索到真实值的速度。
     *
     * @param msg 置换表的指针
     * @param up_bound 上界值
     * @param color_sign 颜色，TreeSearchBase.MAX_LAYER_SIGN 或 TreeSearchBase.MIN_LAYER_SIGN
     * @param depth 当前搜索深度
     * @param hash 哈希值
     * @param ver 校验值
     * @param path 导致下界变换的路径，下次找到这个置换表后优先搜索这个路径。
     */
    void update_up_bound(TableMsg *msg, int up_bound, int color_sign, int depth, int hash, int ver, ChessPath &path);
};


class TableMsg {
public:
    TableMsg() : up_bound(TreeSearchBase::BETA_INIT_VAL), lo_bound(TreeSearchBase::ALPHA_INIT_VAL), up_depth(0),
                 lo_depth(0) {
    }

    /**
     * 当前局面的上界值和下界值。
     *
     * 如果在进行 alpha-beta 搜索时发生 alpha-beta 剪枝，那么将更新这两个值。
     * 在进行每一步的搜索时先查询置换表，如果查询到表项，那么更新 alpha 和 beta 的值。
     *
     * 由于在进行零窗口搜索时，beta = alpha + 1，因此需要保存棋盘的上下界，而不是保存当前深度下决策的最好值。
     */
    int up_bound;
    int lo_bound;

    /**
     * up_depth: 最后一次更新当前局面上界值时的搜索深度。
     * lo_depth: 最后一次更新当前局面下界值时的搜索深度。
     *
     * 查询到表项，更新 alpha 和 beta 的值的时候，如果置换表中的上界值和下界值的深度 >= 当前搜索深度，
     * 那么进行更新，否则不进行更新。
     */
    int up_depth;
    int lo_depth;

    /**
     * 引发更新的路径。
     *
     * 如果在搜索中查询到
     */
    ChessPath best_path;
};


#endif //VLIANG_CHINESE_CHESS_TREE_SEARCH_H
