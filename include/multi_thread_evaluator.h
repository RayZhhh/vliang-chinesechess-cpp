//
// Created by 张睿 on 2022/5/25.
//

#ifndef VLIANG_CHINESE_CHESS_MULTI_THREAD_EVALUATOR_H
#define VLIANG_CHINESE_CHESS_MULTI_THREAD_EVALUATOR_H

#include "tree_search.h"
#include "tree_creator.h"
#include <thread>
#include <ctime>


class MultiThreadEvaluator {
    vector<int> evaluated_value;
    TreeType tree_type;

public:
    MultiThreadEvaluator(Chessboard chessboard, int depth, TreeType tree_type) {
        this->board = chessboard;
        this->depth = depth;
        this->tree_type = tree_type;
    }

    ChessPath get_best_path();

    Chessboard board;
    int depth;

};


void calculate_each_path(Chessboard board, ChessPath &path, int depth, TreeType type) {
    auto tree = TreeCreator::get_tree(board, type);
    path.value = tree->eval_path_val(path, depth);
    cout << ">";
    cout.flush();
}


ChessPath MultiThreadEvaluator::get_best_path() {
    auto start_time = chrono::system_clock::now();

    paths_t paths;
    this->board.get_all_paths(TreeSearch::MIN_LAYER_SIGN, paths);

    vector<thread> threads;
    for (ChessPath &path: paths) {
        threads.emplace_back(thread(calculate_each_path, this->board, std::ref(path), this->depth, this->tree_type));
    }

    for (auto &t: threads) {
        t.join();
    }

    sort(paths.begin(), paths.end(), [](auto l, auto r) { return l.value > r.value; });

    cout << endl;
    for (auto &path: paths) {
        cout << path << endl;
    }

    cout << endl << "best path: " << paths[0] << endl;
    cout << "thread time: " << (float) (chrono::system_clock::now() - start_time).count() / 1000000 << "s" << endl;

    return paths[0];
}


#endif //VLIANG_CHINESE_CHESS_MULTI_THREAD_EVALUATOR_H
