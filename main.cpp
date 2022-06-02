#include "cpp/include/multi_thread_evaluator.h"

#include <stack>

using namespace std;

class ConsoleGame {
public:

    static ChessPath convertPath(string path) {
        int fx = path[0] - '0';
        int fy = path[1] - '0';
        int tx = path[2] - '0';
        int ty = path[3] - '0';
        int eat = path[4] - '0';
        return {fx, fy, tx, ty, eat};
    }

    static void runCChessGame() {
        stack<ChessPath> stack;

        Chessboard cChessboard;
        cChessboard.print_chessboard();

        while (true) {

            cout << "input: 21240  ---- move the chess at <2, 1> to <2, 4> without eating any chess" << endl;
            cout << "input: 21242  ---- move the chess at <2, 1> to <2, 4> and eat the chess labeled 2" << endl;
            cout << "input: regret ---- you know what it means" << endl;
            cout << "input: exit   ---- you know what it means" << endl;

            // player
            string path;
            cin >> path;

            if ("exit" == path) {
                break;
            }

            if ("regret" == path) {
                if (!stack.empty()) {
                    auto p = stack.top();
                    cChessboard.undo_move_chess(p);
                    stack.pop();

                    p = stack.top();
                    cChessboard.undo_move_chess(p);
                    stack.pop();

                    cChessboard.print_chessboard();
                } else {
                    cout << "It is the initial state of the chessboard." << endl;
                }
                continue;
            }

            if ("print" == path) {
                for (auto &i: cChessboard.board) {
                    for (auto &j: i) {
                        cout << j;
                    }
                }
                cout << endl;
                continue;
            }

            auto chess_path = convertPath(path);
            stack.push(chess_path);
            cChessboard.move_chess(chess_path);
            cChessboard.print_chessboard();

            // ai
            MultiThreadEvaluator evaluator(cChessboard, 8, TreeType::MTDF);
            ChessPath best = evaluator.get_best_path();
            cChessboard.move_chess(best);
            stack.push(best);
            cChessboard.print_chessboard();
        }
    }
};


class ArgParser {
public:

    Chessboard board;
    TreeType tree_type;
    int depth{};

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
        if ("ALPHA_BETA" == tree_type_str) tree_type = ALPHA_BETA;
        if ("ALPHA_BETA_WITH_MEMORY" == tree_type_str) tree_type = ALPHA_BETA_WITH_MEMORY;
        if ("MTDF" == tree_type_str) tree_type = MTDF;
        if ("QUIE" == tree_type_str) tree_type = QUIE;
    }

    void parse_depth(const string &depth_str) {
        this->depth = std::stoi(depth_str);
    }
};


#include <fstream>

void py_parse(const char **argv) {
    ArgParser parser;
    parser.parse_chessboard(argv[1]);
    parser.parse_tree_type(argv[2]);
    parser.parse_depth(argv[3]);

    MultiThreadEvaluator evaluator(parser.board, parser.depth, parser.tree_type);
    auto best_path = evaluator.get_best_path();
    evaluator.print_res = false;

    string path = argv[4];
    ofstream out(path, ios::out);
    out << best_path.from_x << "," << best_path.from_y << "," << best_path.to_x << "," << best_path.to_y << ","
        << best_path.eat;
}


class AISelfMatch {
public:
    Chessboard cChessboard;

    int step = 0;

    void startSelfMatch() {

        cChessboard.print_chessboard();

//        cChessboard.move_chess(ChessPath(2, 1, 2, 4, 0));
//        cChessboard.move_chess(ChessPath(3,2,4,2,0));
        cChessboard.print_chessboard();

        while (true) {
            if (step++ == 60) {
                cout << "和棋" << endl;
                break;
            }
            //
            ChessPath best_1 = MultiThreadEvaluator(cChessboard, 8, TreeType::MTDF,
                                                    TreeSearch::MIN_LAYER_SIGN).get_best_path();
            cChessboard.move_chess(best_1);
            cout << "min 落子：" << best_1 << endl;

            cChessboard.print_chessboard();
            if (best_1.eat == -5) {
                cout << "min 赢" << endl;
                break;
            }

            //
            ChessPath best_2 = MultiThreadEvaluator(cChessboard, 8, TreeType::MTDF_QUIE,
                                                    TreeSearch::MAX_LAYER_SIGN).get_best_path();
            cChessboard.move_chess(best_2);
            cout << "max 落子：" << best_2 << endl;
            cChessboard.print_chessboard();
            if (best_2.eat == 5) {
                cout << "max 赢" << endl;
                break;
            }
        }
    }
};


int main(int argc, const char **argv) {
    AISelfMatch().startSelfMatch();
//    ConsoleGame::runCChessGame();
//    py_parse(argv);
    return 0;
}


