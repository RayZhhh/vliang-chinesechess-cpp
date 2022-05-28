//
// Created by 张睿 on 2022/5/25.
//

#include "../include/alpha_beta.h"


int AlphaBeta::alpha_beta_eval(ChessPath &path, int alpha, int beta, int depth, int colorSign) {
    // 判断生死
    if (path.eat == -5) {
        return MAX_EVAL_VAL;
    } else if (path.eat == 5) {
        return MIN_EVAL_VAL;
    }
    // 到达深度
    if (depth == 1) {
        chessboard.move_chess(path);
        int val = chessboard.get_on_board_val();
        chessboard.undo_move_chess(path);
        return val;
    }
    // 落子
    chessboard.move_chess(path);
    // 落子后先判断是否有对将情况
    if (chessboard.is_general_face2face()) {
        if (colorSign == MAX_LAYER_SIGN) {
            chessboard.undo_move_chess(path);
            return MAX_EVAL_VAL + depth;
        } else {
            chessboard.undo_move_chess(path);
            return MIN_EVAL_VAL - depth;
        }
    }
    // max层
    if (colorSign == MAX_LAYER_SIGN) {
        int maxEval = MIN_EVAL_VAL;

        // 对手搜索我方可能的路径
        paths_t possible_paths;
        chessboard.get_all_paths(MIN_LAYER_SIGN, possible_paths);
        std::sort(possible_paths.begin(), possible_paths.end(), [](ChessPath &p1, ChessPath &p2) {
            return p2.value < p1.value;
        });

        for (ChessPath &chess_path: possible_paths) {
            int eval = alpha_beta_eval(chess_path, alpha, beta, depth - 1, MIN_LAYER_SIGN);
            maxEval = maxEval > eval ? maxEval : eval;
            alpha = alpha > eval ? alpha : eval;
            if (beta <= alpha) {
                break;
            }
        }

        // 恢复棋盘
        chessboard.undo_move_chess(path);
        return maxEval;

    } else { // min层
        int minEval = MAX_EVAL_VAL;

        // 搜索对手的可能路径
        paths_t possible_paths;
        chessboard.get_all_paths(MAX_LAYER_SIGN, possible_paths);

        std::sort(possible_paths.begin(), possible_paths.end(), [](ChessPath &p1, ChessPath &p2) {
            return p2.value > p1.value;
        });

        for (ChessPath &chessPath: possible_paths) {
            int eval = alpha_beta_eval(chessPath, alpha, beta, depth - 1, MAX_LAYER_SIGN);
            minEval = minEval < eval ? minEval : eval;
            beta = beta < eval ? beta : eval;
            if (beta <= alpha) {
                break;
            }
        }

        // 恢复棋盘
        chessboard.undo_move_chess(path);
        return minEval;
    }
}


int AlphaBeta::eval_path_val(const ChessPath &path, int depth) {
    this->depth = depth;
    return this->alpha_beta_eval(const_cast<ChessPath &>(path), ALPHA_INIT_VAL, BETA_INIT_VAL, this->depth,
                                 MIN_LAYER_SIGN);
}


int AlphaBetaWithMemory::alpha_beta_with_memory_eval(ChessPath &path, int alpha, int beta, int depth, int colorSign) {
    // 判断生死
    if (path.eat == -5) {
        return MAX_EVAL_VAL;
    } else if (path.eat == 5) {
        return MIN_EVAL_VAL;
    }
    // 到达深度
    if (depth == 1) {
        chessboard.move_chess(path);
        int val = chessboard.get_on_board_val();
        chessboard.undo_move_chess(path);
        return val;
    }

    // 落子
    chessboard.move_chess(path);

    // 落子后先判断是否有对将情况
    if (chessboard.is_general_face2face()) {
        if (colorSign == MAX_LAYER_SIGN) {
            chessboard.undo_move_chess(path);
            return MAX_EVAL_VAL + depth;
        } else {
            chessboard.undo_move_chess(path);
            return MIN_EVAL_VAL - depth;
        }
    }

    // -------------------- 查询置换表 ---------------------------------------------------
    int ch_hash = chessboard.get_hash();
    TableMsg *tableMsg;
    bool find_ch;

    if (colorSign == MAX_LAYER_SIGN) {
        find_ch = tran_table_max.find(ch_hash, tableMsg);
    } else {
        find_ch = tran_table_min.find(ch_hash, tableMsg);
    }

    // 要求能查询到当前局面，且置换表中的深度要大于当前深度时才使用置换表
    if (find_ch) {
        if (tableMsg->loDepth >= depth) {
            if (tableMsg->lowerBound >= beta) {
                chessboard.undo_move_chess(path);
                return tableMsg->lowerBound;
            }
            alpha = alpha > tableMsg->lowerBound ? alpha : tableMsg->lowerBound;
        }
        if (tableMsg->upDepth >= depth) {
            if (tableMsg->upperBound <= alpha) {
                chessboard.undo_move_chess(path);
                return tableMsg->upperBound;
            }
            beta = beta < tableMsg->upperBound ? beta : tableMsg->upperBound;
        }
    }
    // -------------------- 查询置换表 ---------------------------------------------------

    // max层
    if (colorSign == MAX_LAYER_SIGN) {
        int maxEval = MIN_EVAL_VAL;

        // 对手搜索我方可能的路径
        paths_t possible_paths;
        chessboard.get_all_paths(MIN_LAYER_SIGN, possible_paths);
        std::sort(possible_paths.begin(), possible_paths.end(), [](ChessPath &p1, ChessPath &p2) {
            return p2.value < p1.value;
        });

        for (ChessPath &chess_path: possible_paths) {
            int eval = alpha_beta_with_memory_eval(chess_path, alpha, beta, depth - 1, MIN_LAYER_SIGN);
            maxEval = maxEval > eval ? maxEval : eval;
            alpha = alpha > eval ? alpha : eval;
            if (beta <= alpha) {
                break;
            }
        }

        // 将可能的情况保存到置换表
        if (maxEval <= alpha) {
            update_up_bound(maxEval, MAX_LAYER_SIGN, depth);
        }
        if (alpha < maxEval && maxEval < beta) {
            update_lo_bound(maxEval, MAX_LAYER_SIGN, depth);
            update_up_bound(maxEval + 1, MAX_LAYER_SIGN, depth);
        }
        if (maxEval >= beta) {
            update_lo_bound(maxEval, MAX_LAYER_SIGN, depth);
        }
        chessboard.undo_move_chess(path);
        return maxEval;

    } else { // min层
        int minEval = MAX_EVAL_VAL;

        // 搜索对手的可能路径
        paths_t possible_paths;
        chessboard.get_all_paths(MAX_LAYER_SIGN, possible_paths);

        std::sort(possible_paths.begin(), possible_paths.end(), [](ChessPath &p1, ChessPath &p2) {
            return p2.value > p1.value;
        });

        for (ChessPath &chessPath: possible_paths) {
            int eval = alpha_beta_with_memory_eval(chessPath, alpha, beta, depth - 1, MAX_LAYER_SIGN);
            minEval = minEval < eval ? minEval : eval;
            beta = beta < eval ? beta : eval;
            if (beta <= alpha) {
                break;
            }
        }

        // 将可能的情况保存到置换表
        if (minEval <= alpha) {
            update_up_bound(minEval, MIN_LAYER_SIGN, depth);
        }
        if (alpha < minEval && minEval < beta) {
            update_lo_bound(minEval, MIN_LAYER_SIGN, depth);
            update_up_bound(minEval + 1, MIN_LAYER_SIGN, depth);
        }
        if (minEval >= beta) {
            update_lo_bound(minEval, MIN_LAYER_SIGN, depth);
        }

        // 恢复棋盘
        chessboard.undo_move_chess(path);
        return minEval;
    }
}


int AlphaBetaWithMemory::eval_path_val(const ChessPath &path, int depth) {
    this->depth = depth;
    return this->alpha_beta_with_memory_eval(const_cast<ChessPath &>(path), ALPHA_INIT_VAL, BETA_INIT_VAL, this->depth,
                                 MIN_LAYER_SIGN);
}
