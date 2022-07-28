//
// Created by 张睿 on 2022/5/31.
//

#include "../include/evaluator.h"

#define PROCESS_BAR_CHAR '>'

void
calculate_each_path(Chessboard board, ChessPath &path, int depth, TreeType type, bool print_porcess, int color_sign) {
    auto tree = TreeCreator::get_tree(board, type);
    path.value = tree->eval_path_val(path, depth, color_sign);
    if (print_porcess) {
        cout << ">" << flush;
    }
    cout.flush();
}


string tree_to_string(TreeType type) {
    switch (type) {
        case ALPHA_BETA:
            return "ALPHA_BETA";

        case ALPHA_BETA_WITH_MEMORY:
            return "ALPHA_BETA_WITH_MEMORY";

        case MTDF:
            return "MTDF";

        case QUIE:
            return "QUIE";

        case MTDF_QUIE:
            return "MTDF_QUIE";

        case ITER_DEEP:
            return "ITER_DEEP";

        default:
            return "";
    }
}


ChessPath MultiThreadEvaluator::get_best_path() {
    auto start_time = chrono::steady_clock::now();

    paths_t paths;
    this->board.get_all_paths(-this->color_sign, paths);

    if (print_res) {
        // print process bar
        cout << "evaluating: 0";
        for (auto &i: paths) {
            cout << ">";
        }
        cout << "100" << endl;
        cout << "evaluating:  ";
    }

    vector<thread> threads;
    for (ChessPath &path: paths) {
        threads.emplace_back(
                thread(calculate_each_path, this->board, std::ref(path), this->depth, this->tree_type, this->print_res,
                       -this->color_sign));
    }

    for (auto &t: threads) {
        t.join();
    }

    if (color_sign == TreeSearchBase::MAX_LAYER_SIGN) {
        sort(paths.begin(), paths.end(), [](auto l, auto r) { return l.value > r.value; });
    } else {
        sort(paths.begin(), paths.end(), [](auto l, auto r) { return l.value < r.value; });
    }

    cout << endl;

    string hline = "=====================================================================================";
    string top_line = "===================================Evaluate Result===================================";
    cout << top_line << endl;
    for (int i = 0; i < print_res_num && i < paths.size(); i += 2) {
        cout << "| ";
        printf("%-39s", paths[i].to_string().c_str());
        cout << " | ";
        printf("%-39s", i + 1 < print_res_num && i + 1 < paths.size() ? paths[i + 1].to_string().c_str() : "");
        cout << " |" << endl;
        cout << hline << endl;
    }

    if (print_res) {
        string best_msg = "Best Path: " + paths[0].to_string();
        printf("| %-82s|\n", best_msg.c_str());
        cout << hline << endl;
        string time_msg = "Thread Time=" + std::to_string((float) (chrono::duration_cast<chrono::milliseconds>(
                chrono::steady_clock::now() - start_time).count()) / 1000) + "s";
        string tree_msg =
                "Tree Type=" + tree_to_string(tree_type) + "  Base Search Depth=" + to_string(depth) + "  " + time_msg;
        printf("| %-82s|\n", tree_msg.c_str());
        cout << hline << endl << endl;
    }

    return paths[0];
}


ChessPath DeepeningMultiThreadEvaluator::get_best_path() {
    int real_search_depth = this->depth;
    ChessPath ret;

    while (true) {

        auto start_time = chrono::steady_clock::now();
        ret = MultiThreadEvaluator::get_best_path();
        float eval_time = (float) (chrono::duration_cast<chrono::milliseconds>(
                chrono::steady_clock::now() - start_time).count()) / 1000;

        if (eval_time > this->time_threshold_in_second) {
            break;
        } else {
            this->depth += 2;
        }
    }

    this->depth = real_search_depth;
    return ret;
}
