//
// Created by 张睿 on 2022/5/29.
//

#include "../include/quiescence.h"

int Quiescence::quiescence(ChessPath &path, int alpha, int beta, int maxDepth, int colorSign) {
    // 判断生死
    if (path.eat == 5) {
        return MIN_EVAL_VAL;
    }
    if (path.eat == -5) {
        return MAX_EVAL_VAL;
    }

    // 到达搜索深度
    if (maxDepth == 1) {
        chessboard.move_chess(path);
        int val = chessboard.get_on_board_val();
        chessboard.undo_move_chess(path);
        return val;
    }

    // 下棋
    chessboard.move_chess(path);

    // 落子后先判断是否有对将情况
    if (chessboard.is_general_face2face()) {
        if (colorSign == MAX_LAYER_SIGN) {
            chessboard.undo_move_chess(path);
            return MAX_EVAL_VAL;
        } else {
            chessboard.undo_move_chess(path);
            return MIN_EVAL_VAL;
        }
    }

    // max
    if (colorSign == MAX_LAYER_SIGN) {
        paths_t chessPaths;
        chessboard.get_all_paths(MIN_LAYER_SIGN, chessPaths);

        // 如果结果为空，返回当前棋盘的价值
        if (chessPaths.empty()) {
            int val = chessboard.get_on_board_val();
            chessboard.undo_move_chess(path);
            return val;
        }

        // 如果没有被将军，只生成吃子的路径，并使用mvv/lva启发
        if (!chessboard.is_checked(MIN_LAYER_SIGN)) {
            paths_t eat_paths;
            for (auto &p: chessPaths) {
                if (p.eat != 0) {
                    eat_paths.emplace_back(p);
                }
            }

            // 如果结果为空，返回当前棋盘的价值
            if (eat_paths.empty()) {
                int val = chessboard.get_on_board_val();
                chessboard.undo_move_chess(path);
                return val;
            }

            // 启发
            sort(eat_paths.begin(), eat_paths.end(), [](ChessPath &l, ChessPath &r) {
#ifndef MVV_LVA
                return l.value > r.value;
#else
                if (get_pos_val(l.to_x, l.to_y, l.eat) != get_pos_val(r.to_x, r.to_y, r.eat)) {
                    return get_pos_val(l.to_x, l.to_y, l.eat) < get_pos_val(r.to_x, r.to_y, r.eat);
                } else {
                    return get_pos_val(l.from_x, l.from_y, chessboard.board[l.from_x][l.from_y]) <
                           get_pos_val(r.from_x, r.from_y, chessboard.board[r.from_x][r.from_y]);
                }
#endif
            });

            int maxEval = MIN_EVAL_VAL;
            for (ChessPath chessPath: eat_paths) {
                int eval = quiescence(chessPath, alpha, beta, maxDepth - 1, MIN_LAYER_SIGN);
                maxEval = maxEval > eval ? maxEval : eval;
                alpha = alpha > maxEval ? alpha : maxEval;
                if (beta <= alpha) {
                    break;
                }
            }
            chessboard.undo_move_chess(path);
            return maxEval;

        } else {

            sort(chessPaths.begin(), chessPaths.end(), [](ChessPath &l, ChessPath &r) {
                return l.value > r.value;
            });

            int maxEval = MIN_EVAL_VAL;
            for (ChessPath chessPath: chessPaths) {
                int eval = quiescence(chessPath, alpha, beta, maxDepth - 1, MIN_LAYER_SIGN);
                maxEval = maxEval > eval ? maxEval : eval;
                alpha = alpha > maxEval ? alpha : maxEval;
                if (beta <= alpha) {
                    break;
                }
            }
            chessboard.undo_move_chess(path);
            return maxEval;
        }

    } else {
        paths_t chessPaths;
        chessboard.get_all_paths(MAX_LAYER_SIGN, chessPaths);

        // 如果结果为空，返回当前棋盘的价值
        if (chessPaths.empty()) {
            int val = chessboard.get_on_board_val();
            chessboard.undo_move_chess(path);
            return val;
        }

        // 如果没有被将军，只生成吃子的路径，并使用mvv/lva启发
        if (!chessboard.is_checked(MAX_LAYER_SIGN)) {
            paths_t eat_paths;
            for (auto &p: chessPaths) {
                if (p.eat != 0) {
                    eat_paths.emplace_back(p);
                }
            }

            // 如果结果为空，返回当前棋盘的价值
            if (eat_paths.empty()) {
                int val = chessboard.get_on_board_val();
                chessboard.undo_move_chess(path);
                return val;
            }

            // 启发
            sort(eat_paths.begin(), eat_paths.end(), [](ChessPath &l, ChessPath &r) {
#ifndef MVV_LVA
                return l.value < r.value;
#else
                if (get_pos_val(l.to_x, l.to_y, l.eat) != get_pos_val(r.to_x, r.to_y, r.eat)) {
                    return get_pos_val(l.to_x, l.to_y, l.eat) > get_pos_val(r.to_x, r.to_y, r.eat);
                } else {
                    return get_pos_val(l.from_x, l.from_y, chessboard.board[l.from_x][l.from_y]) >
                           get_pos_val(r.from_x, r.from_y, chessboard.board[r.from_x][r.from_y]);
                }
#endif
            });

            int minEval = MAX_EVAL_VAL;
            for (ChessPath &chessPath: eat_paths) {
                int eval = quiescence(chessPath, alpha, beta, maxDepth - 1, MAX_LAYER_SIGN);
                minEval = minEval < eval ? minEval : eval;
                beta = beta < eval ? beta : eval;
                if (beta <= alpha) {
                    break;
                }
            }

            // 恢复棋盘
            chessboard.undo_move_chess(path);
            return minEval;
        } else {

            sort(chessPaths.begin(), chessPaths.end(), [](ChessPath &l, ChessPath &r) {
                return l.value < r.value;
            });

            int minEval = MAX_EVAL_VAL;
            for (ChessPath chessPath: chessPaths) {
                int eval = quiescence(chessPath, alpha, beta, maxDepth - 1, MAX_LAYER_SIGN);
                minEval = minEval < eval ? minEval : eval;
                beta = beta < eval ? beta : eval;
                if (beta <= alpha) {
                    break;
                }
            }
            chessboard.undo_move_chess(path);
            return minEval;
        }
    }
}


int Quiescence::alpha_beta_quiescence_with_memory_eval(ChessPath &path, int alpha, int beta, int depth, int colorSign) {
    // 判断生死
    if (path.eat == -5) {
        return MAX_EVAL_VAL;
    } else if (path.eat == 5) {
        return MIN_EVAL_VAL;
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
    int ch_ver = chessboard.get_verify();
    TableMsg *tableMsg;

    if (colorSign == MAX_LAYER_SIGN) {
        tableMsg = tran_table_max.get_table(ch_hash, ch_ver);
    } else {
        tableMsg = tran_table_min.get_table(ch_hash, ch_ver);
    }

    // 要求能查询到当前局面，且置换表中的深度要大于当前深度时才使用置换表
    if (tableMsg != nullptr) {
        if (tableMsg->lo_depth <= depth) {
            if (tableMsg->lo_bound >= beta) {
                chessboard.undo_move_chess(path);
                return tableMsg->lo_bound;
            }
            alpha = alpha > tableMsg->lo_bound ? alpha : tableMsg->lo_bound;
        }
        if (tableMsg->up_depth <= depth) {
            if (tableMsg->up_bound <= alpha) {
                chessboard.undo_move_chess(path);
                return tableMsg->up_bound;
            }
            beta = beta < tableMsg->up_bound ? beta : tableMsg->up_bound;
        }
    }
    // -------------------- 查询置换表 ---------------------------------------------------

    // max层
    if (colorSign == MAX_LAYER_SIGN) {

        // 处理叶子节点
        if (depth == 1) {
            if (path.eat != 0) { // 如果正在发生吃子，进行静态搜索
                chessboard.undo_move_chess(path);
                // 这里要调用 MAX_LAYER_SIGN，因为静态搜索要帮助当前层完成搜索
                return quiescence(path, alpha, beta, QUIESCENCE_MAX_DEPTH, MAX_LAYER_SIGN);
            } else { // 如果没有上述两种局面，评估并返回结果
                int val = chessboard.get_on_board_val();
                chessboard.undo_move_chess(path);
                return val;
            }
        }

        // 对手搜索我方可能的路径
        paths_t possible_paths;
        if (tableMsg != nullptr) {
            possible_paths.push_back(tableMsg->best_path);
            chessboard.get_all_paths(MIN_LAYER_SIGN, possible_paths);
            std::sort(possible_paths.begin() + 1, possible_paths.end(), [](ChessPath &p1, ChessPath &p2) {
                return p2.value < p1.value;
            });
        } else {
            chessboard.get_all_paths(MIN_LAYER_SIGN, possible_paths);
            std::sort(possible_paths.begin(), possible_paths.end(), [](ChessPath &p1, ChessPath &p2) {
                return p2.value < p1.value;
            });
        }

        int al = alpha;
        int maxEval = MIN_EVAL_VAL;
        ChessPath cur_best = possible_paths[0];

        for (ChessPath &chess_path: possible_paths) {
            int eval = alpha_beta_quiescence_with_memory_eval(chess_path, al, beta, depth - 1, MIN_LAYER_SIGN);
            if (eval > maxEval) {
                maxEval = eval;
                cur_best = chess_path;
            }
            al = al > eval ? al : eval;
            if (beta <= al) {
                break;
            }
        }

        // 将可能的情况保存到置换表
        if (maxEval <= alpha) {
            update_up_bound(tableMsg, maxEval, MAX_LAYER_SIGN, depth, ch_hash, ch_ver, cur_best);
        }
        if (alpha < maxEval && maxEval < beta) {
            update_lo_bound(tableMsg, maxEval, MAX_LAYER_SIGN, depth, ch_hash, ch_ver, cur_best);
            update_up_bound(tableMsg, maxEval + 1, MAX_LAYER_SIGN, depth, ch_hash, ch_ver, cur_best);
        }
        if (maxEval >= beta) {
            update_lo_bound(tableMsg, maxEval, MAX_LAYER_SIGN, depth, ch_hash, ch_ver, cur_best);
        }
        chessboard.undo_move_chess(path);
        return maxEval;

    } else { // min层

        // 处理叶子节点
        if (depth == 1) {
            if (path.eat != 0) { // 如果正在发生吃子，进行静态搜索
                chessboard.undo_move_chess(path);
                // 这里要调用 MIN_LAYER_SIGN，因为静态搜索要帮助当前层完成搜索
                return quiescence(path, alpha, beta, QUIESCENCE_MAX_DEPTH, MIN_LAYER_SIGN);
            } else { // 如果没有上述两种局面，评估并返回结果
                int val = chessboard.get_on_board_val();
                chessboard.undo_move_chess(path);
                return val;
            }
        }

        // 搜索对手的可能路径
        paths_t possible_paths;
        if (tableMsg != nullptr) {
            possible_paths.push_back(tableMsg->best_path);
            chessboard.get_all_paths(MAX_LAYER_SIGN, possible_paths);
            std::sort(possible_paths.begin(), possible_paths.end(), [](ChessPath &p1, ChessPath &p2) {
                return p2.value > p1.value;
            });
        } else {
            chessboard.get_all_paths(MAX_LAYER_SIGN, possible_paths);
            std::sort(possible_paths.begin(), possible_paths.end(), [](ChessPath &p1, ChessPath &p2) {
                return p2.value > p1.value;
            });
        }

        int be = beta;
        int minEval = MAX_EVAL_VAL;
        ChessPath cur_best = possible_paths[0];

        for (ChessPath &chessPath: possible_paths) {
            int eval = alpha_beta_quiescence_with_memory_eval(chessPath, alpha, be, depth - 1, MAX_LAYER_SIGN);
            if (eval < minEval) {
                minEval = eval;
                cur_best = chessPath;
            }
            be = be < eval ? be : eval;
            if (be <= alpha) {
                break;
            }
        }

        // 将可能的情况保存到置换表
        if (minEval <= alpha) {
            update_up_bound(tableMsg, minEval, MIN_LAYER_SIGN, depth, ch_hash, ch_ver, cur_best);
        }
        if (alpha < minEval && minEval < beta) {
            update_lo_bound(tableMsg, minEval, MIN_LAYER_SIGN, depth, ch_hash, ch_ver, cur_best);
            update_up_bound(tableMsg, minEval + 1, MIN_LAYER_SIGN, depth, ch_hash, ch_ver, cur_best);
        }
        if (minEval >= beta) {
            update_lo_bound(tableMsg, minEval, MIN_LAYER_SIGN, depth, ch_hash, ch_ver, cur_best);
        }

        // 恢复棋盘
        chessboard.undo_move_chess(path);
        return minEval;
    }
}


int Quiescence::eval_path_val(const ChessPath &path, int depth) {
    this->search_depth = depth;
    return alpha_beta_quiescence_with_memory_eval(const_cast<ChessPath &>(path), ALPHA_INIT_VAL, BETA_INIT_VAL, depth,
                                                  MIN_LAYER_SIGN);
}


int Quiescence::eval_path_val(const ChessPath &path, int depth, int color_sign) {
    this->search_depth = depth;
    return alpha_beta_quiescence_with_memory_eval(const_cast<ChessPath &>(path), ALPHA_INIT_VAL, BETA_INIT_VAL, depth,
                                                  color_sign);
}
