//
// Created by 张睿 on 2022/5/25.
//

#ifndef VLIANG_CHINESE_CHESS_EVALUATOR_H
#define VLIANG_CHINESE_CHESS_EVALUATOR_H

#include "tree_search.h"
#include "tree_creator.hpp"
#include <thread>
#include <ctime>
#include <iomanip>
#include "path_filter.h"


//class SingleThreadEvaluator {
//public:
//
//    TreeType tree_type;
//    Chessboard board;
//    int depth;
//    int color_sign;
//    bool print_res = true;
//
//    int alpha = TreeSearchBase::ALPHA_INIT_VAL;
//    int beta = TreeSearchBase::BETA_INIT_VAL;
//
//    SingleThreadEvaluator(Chessboard chessboard, int depth, TreeType tree_type) {
//        this->board = chessboard;
//        this->depth = depth;
//        this->tree_type = tree_type;
//        this->color_sign = TreeSearchBase::MAX_LAYER_SIGN;
//    }
//
//    SingleThreadEvaluator(Chessboard chessboard, int depth, TreeType tree_type, int color_sign) {
//        this->board = chessboard;
//        this->depth = depth;
//        this->tree_type = tree_type;
//        this->color_sign = color_sign;
//    }
//
//    virtual ChessPath get_best_path() = 0;
//};


class MultiThreadEvaluator {
public:

    /**
     * 采用的搜索树的类型
     */
    TreeType tree_type;

    /**
     * 需要搜索的棋盘
     */
    Chessboard board;

    /**
     * 搜索深度
     */
    int depth;

    /**
     * 搜索的棋子颜色
     */
    int color_sign;

    /**
     * 是否打印结果
     */
    bool print_res = true;

    /**
     * 在控制台打印的结果数量（最大数量）
     * 如果 print_res 为 true，那么这个变量有效
     */
    int print_res_num = 14;

    MultiThreadEvaluator(Chessboard chessboard, int depth, TreeType tree_type) {
        this->board = chessboard;
        this->depth = depth;
        this->tree_type = tree_type;
        this->color_sign = TreeSearchBase::MAX_LAYER_SIGN;
    }

    MultiThreadEvaluator(Chessboard chessboard, int depth, TreeType tree_type, int color_sign) {
        this->board = chessboard;
        this->depth = depth;
        this->tree_type = tree_type;
        this->color_sign = color_sign;
    }

    virtual ChessPath get_best_path();

    virtual paths_t get_all_evaluated_path();

protected:
    paths_t all_paths;

    virtual void evaluate_all_path();
};


class DeepeningMultiThreadEvaluator : public MultiThreadEvaluator {
public:
    DeepeningMultiThreadEvaluator(Chessboard chessboard, int depth, TreeType tree_type)
            : MultiThreadEvaluator(chessboard, depth, tree_type) {}

    DeepeningMultiThreadEvaluator(Chessboard chessboard, int depth, TreeType tree_type, int color_sign)
            : MultiThreadEvaluator(chessboard, depth, tree_type, color_sign) {}

    /**
     * 如果在当前深度下评估时长小于这个值，那么每次深度+2
     * 增加深度后会再进行一次评估，直到超过了时间要求
     *
     * 每个设备都应该调整合适的 time_threshold_in_second
     * 这个值太小会导致中后盘评估深度不太够，太大可能会导致每次评估都进行深度增加，导致非常耗时
     * 我的CPU型号为：Core i9-9880h @2.3GHz，这个值在0.8左右还不错
     */
    float time_threshold_in_second = 0.8f;

    ChessPath get_best_path() override;

    paths_t get_all_evaluated_path() override;

protected:
    void evaluate_all_path() override;
};


#endif //VLIANG_CHINESE_CHESS_EVALUATOR_H
