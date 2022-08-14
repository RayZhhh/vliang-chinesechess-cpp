//
// Created by 张睿 on 2022/6/4.
//
#include <fstream>
#include <iostream>
#include "cpp/include/evaluator.h"

#define COMPILE_PY_INTERFACE

#ifdef COMPILE_PY_INTERFACE

class ArgParser {
public:

    Chessboard board;
    TreeType tree_type;
    int depth{};
    int color_sign;

    void parse_chessboard(const string &str) {
        chessboard_t chessboard;

        for (int i = 0; i < 90; i++) {
            string id_str = string(str.begin() + i * 2, str.begin() + i * 2 + 2);
            int id = stoi(id_str);
            int chess_id = id - 20;
            chessboard[i % 9][i - i % 9 * 9] = chess_id;
        }

        Chessboard ret;
        ret.copy(chessboard);
        this->board = ret;
    }

    void parse_tree_type(const string &tree_type_str) {
        if ("ALPHA_BETA" == tree_type_str)
            tree_type = ALPHA_BETA;
        if ("ALPHA_BETA_WITH_MEMORY" == tree_type_str)
            tree_type = ALPHA_BETA_WITH_MEMORY;
        if ("MTDF" == tree_type_str)
            tree_type = MTDF;
        if ("QUIE" == tree_type_str)
            tree_type = QUIE;
        if ("ITER_DEEP" == tree_type_str)
            tree_type = ITER_DEEP;
        if ("MTDF_QUIE" == tree_type_str)
            tree_type = MTDF_QUIE;

    }

    void parse_depth(const string &depth_str) {
        this->depth = std::stoi(depth_str);
    }

    void parse_color_sign(const string &color_str) {
        if ("MAX_LAYER_SIGN" == color_str) {
            this->color_sign = TreeSearchBase::MAX_LAYER_SIGN;
        } else {
            this->color_sign = TreeSearchBase::MIN_LAYER_SIGN;
        }
    }
};


void py_parse(const char **argv) {

    if (argv[1] == nullptr || argv[2] == nullptr || argv[3] == nullptr || argv[4] == nullptr || argv[5] == nullptr) {
        cerr << "Required parameters:" << endl;
        cerr << "argv[0]: the sequence of the chessboard." << endl;
        cerr << "argv[1]: the type of the searching tree (or searching algorithm)." << endl;
        cerr << "argv[2]: the search depth." << endl;
        cerr << "argv[3]: the target chess color." << endl;
        cerr << "argv[4]: the path of the file which stores the evaluate results." << endl;
        return;
    }

    ArgParser parser;
    parser.parse_chessboard(argv[1]);
    parser.parse_tree_type(argv[2]);
    parser.parse_depth(argv[3]);
    parser.parse_color_sign(argv[4]);

    MultiThreadEvaluator evaluator(parser.board, parser.depth, parser.tree_type, parser.color_sign);
    auto best_path = evaluator.get_best_path();
    evaluator.print_res = false;

    string path = argv[5];
    ofstream out(path, ios::out);
    out << best_path.from_x << "," << best_path.from_y << "," << best_path.to_x << "," << best_path.to_y << ","
        << best_path.eat;
}


int main(int argc, const char **argv) {
    py_parse(argv);
    return 0;
}


#endif