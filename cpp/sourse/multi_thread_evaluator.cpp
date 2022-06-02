//
// Created by 张睿 on 2022/5/31.
//

#include "../include/multi_thread_evaluator.h"

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


ChessPath MultiThreadEvaluator::get_best_path() {
    auto start_time = chrono::system_clock::now();

    paths_t paths;
    this->board.get_all_paths(this->color_sign, paths);

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
                       this->color_sign));
    }

    for (auto &t: threads) {
        t.join();
    }

    if (color_sign == TreeSearch::MIN_LAYER_SIGN) {
        sort(paths.begin(), paths.end(), [](auto l, auto r) { return l.value > r.value; });
    } else {
        sort(paths.begin(), paths.end(), [](auto l, auto r) { return l.value < r.value; });
    }

    cout << endl;
    for (auto &path: paths) {
        cout << path << endl;
    }

    if (print_res) {
        cout << endl << "best path: " << paths[0] << endl;
        cout << "thread time: " << (float) (chrono::system_clock::now() - start_time).count() / 1000000 << "s" << endl;
    }

    return paths[0];
}