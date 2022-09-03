//
// Created by 张睿 on 2022/7/27.
//

#include "../include/mtdf.h"

int MTDF_Searching::mtdf_eval(ChessPath &chess_path, int beta, int depth, int color_sign) {
    if (this->estimate_MTDF_init_value) {
        estimate_init_value(chess_path, depth, color_sign);
    }

    int val = this->mtdf_init_value;

    int upperBound = MAX_EVAL_VAL;
    int lowerBound = MIN_EVAL_VAL;

    while (lowerBound < upperBound) {
        if (val == lowerBound) {
            beta = val + 1;
        } else {
            beta = val;
        }
        // 进行一个以 [beta - 1, beta] 为零窗口的记忆化搜索
        val = alpha_beta_with_memory_eval(chess_path, beta - 1, beta, depth, color_sign);
        if (val < beta) {
            upperBound = val;
        } else {
            lowerBound = val;
        }
    }

    return val;
}

int MTDF_Searching::eval_path_val(const ChessPath &path, int depth) {
    this->search_depth = depth;
    return this->mtdf_eval(const_cast<ChessPath &>(path), 0, depth, MIN_LAYER_SIGN);
}

int MTDF_Searching::eval_path_val(const ChessPath &path, int depth, int color_sign) {
    this->search_depth = depth;
    return this->mtdf_eval(const_cast<ChessPath &>(path), 0, depth, color_sign);
}

void MTDF_Searching::estimate_init_value(ChessPath &chess_path, int depth, int color_sign) {
    this->mtdf_init_value = alpha_beta_with_memory_eval(chess_path, ALPHA_INIT_VAL, BETA_INIT_VAL, depth - 2,
                                                        color_sign);
}


// ========================================= MTDF_Quiescence_Searching 实现 =========================================


int MTDF_Quiescence_Searching::mtdf_quiescence_eval(ChessPath &chess_path, int beta, int depth, int color_sign) {
    if (this->estimate_MTDF_init_value) {
        estimate_init_value(chess_path, depth, color_sign);
    }

    // 获取 beta 的初始值
    int val = MTDF_Quiescence_Searching::mtdf_init_value;

    int upperBound = MAX_EVAL_VAL;
    int lowerBound = MIN_EVAL_VAL;

    while (lowerBound < upperBound) {
        if (val == lowerBound) {
            beta = val + 1;
        } else {
            beta = val;
        }
        // 进行一个以 [beta - 1, beta] 为零窗口的记忆化搜索
        val = alpha_beta_quiescence_with_memory_eval(chess_path, beta - 1, beta, depth, color_sign);
        if (val < beta) {
            upperBound = val;
        } else {
            lowerBound = val;
        }
    }

    return val;
}

int MTDF_Quiescence_Searching::eval_path_val(const ChessPath &path, int depth) {
    this->search_depth = depth;
    return this->mtdf_quiescence_eval(const_cast<ChessPath &>(path), 0, depth, MIN_LAYER_SIGN);
}

int MTDF_Quiescence_Searching::eval_path_val(const ChessPath &path, int depth, int color_sign) {
    this->search_depth = depth;
    return this->mtdf_quiescence_eval(const_cast<ChessPath &>(path), 0, depth, color_sign);
}

void MTDF_Quiescence_Searching::estimate_init_value(ChessPath &chess_path, int depth, int color_sign) {
    this->mtdf_init_value = alpha_beta_eval(chess_path, ALPHA_INIT_VAL, BETA_INIT_VAL,
                                            depth - 2, color_sign);
}

int IterDeepening::iter_deepening_eval(ChessPath &path, int depth, int color_sign) {
    int beta_init_val = 0;
    this->estimate_MTDF_init_value = false;
    for (int i = 2; i < depth; i++) {
        beta_init_val = this->mtdf_eval(path, beta_init_val, i, color_sign);
    }
    return beta_init_val;
}

int IterDeepening::eval_path_val(const ChessPath &path, int depth) {
    return iter_deepening_eval(const_cast<ChessPath &>(path), depth, MIN_LAYER_SIGN);
}
