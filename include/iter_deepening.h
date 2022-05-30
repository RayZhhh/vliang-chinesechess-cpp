//
// Created by 张睿 on 2022/5/30.
//

#ifndef VLIANG_CHINESE_CHESS_ITER_DEEPENING_H
#define VLIANG_CHINESE_CHESS_ITER_DEEPENING_H

#include "mtdf.h"

class IterDeepening : public MTDF_Searching {
public:

    int iter_deepening_eval(const ChessPath &path, int depth, int color_sign) {
        int beta_init_val = 0;
        this->estimate_MTDF_init_value = false;
        for (int i = 2; i < depth; i++) {
            beta_init_val = this->mtdf_eval(path, beta_init_val, i, color_sign);
        }
        return beta_init_val;
    }

    int eval_path_val(const ChessPath &path, int depth) override {
        return iter_deepening_eval(path, depth, MIN_LAYER_SIGN);
    }

};

#endif //VLIANG_CHINESE_CHESS_ITER_DEEPENING_H
