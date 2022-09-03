//
// Created by 张睿 on 2022/5/27.
//

#ifndef VLIANG_CHINESE_CHESS_MTDF_H
#define VLIANG_CHINESE_CHESS_MTDF_H

#include "tree_search.h"
#include "alpha_beta.h"
#include "quiescence.h"


class MTDF_Searching : public AlphaBetaWithMemory {

public:
    /**
     * beta变量的初始值，这个值越接近真实值，计算时间越快
     */
    int mtdf_init_value = 0;

    /**
     * 是否估计beta变量的初始值
     */
    bool estimate_MTDF_init_value = true;

    explicit MTDF_Searching(Chessboard &board) : AlphaBetaWithMemory(board) {}

    /**
     * 估计beta变量的初始值
     *
     * 采用的方式是降低深度进行一轮搜索，得到的值作为估计值
     * @param chess_path
     * @param depth
     * @param color_sign
     */
    void estimate_init_value(ChessPath &chess_path, int depth, int color_sign);

    int mtdf_eval(ChessPath &chess_path, int beta, int depth, int color_sign);

    int eval_path_val(const ChessPath &path, int depth) override;

    int eval_path_val(const ChessPath &path, int depth, int color_sign) override;
};


class MTDF_Quiescence_Searching : public Quiescence {

public:

    /**
     * beta变量的初始值，这个值越接近真实值，计算时间越快
     */
    int mtdf_init_value;

    /**
     * 是否估计beta变量的初始值
     */
    bool estimate_MTDF_init_value = true;

    explicit MTDF_Quiescence_Searching(Chessboard &board) : Quiescence(board) {}

    /**
     * 估计beta变量的初始值
     *
     * 采用的方式是降低深度进行一轮搜索，得到的值作为估计值
     * @param chess_path
     * @param depth
     * @param color_sign
     */
    void estimate_init_value(ChessPath &chess_path, int depth, int color_sign);

    int mtdf_quiescence_eval(ChessPath &chess_path, int beta, int depth, int color_sign);

    int eval_path_val(const ChessPath &path, int depth) override;

    int eval_path_val(const ChessPath &path, int depth, int color_sign) override;
};


class IterDeepening : public MTDF_Searching {
public:
    explicit IterDeepening(Chessboard &board) : MTDF_Searching(board) {}

    int iter_deepening_eval(ChessPath &path, int depth, int color_sign);

    int eval_path_val(const ChessPath &path, int depth) override;
};

#endif //VLIANG_CHINESE_CHESS_MTDF_H