#include "cpp/include/evaluator.h"


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
            cout << "input: regret ---- regret" << endl;
            cout << "input: exit   ---- exit console game" << endl;

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
            MultiThreadEvaluator evaluator(cChessboard, 6, TreeType::MTDF_QUIE);
            ChessPath best = evaluator.get_best_path();
            cChessboard.move_chess(best);
            stack.push(best);
            cChessboard.print_chessboard();
        }
    }
};


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
            ChessPath best_1 = MultiThreadEvaluator(cChessboard, 6, TreeType::MTDF_QUIE,
                                                    TreeSearchBase::MAX_LAYER_SIGN).get_best_path();
            cChessboard.move_chess(best_1);
            cout << "min 落子：" << best_1 << endl;

            cChessboard.print_chessboard();
            if (best_1.eat == -5) {
                cout << "min 赢" << endl;
                break;
            }

            //
            ChessPath best_2 = MultiThreadEvaluator(cChessboard, 8, TreeType::MTDF,
                                                    TreeSearchBase::MIN_LAYER_SIGN).get_best_path();
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
//    AISelfMatch().startSelfMatch();
    ConsoleGame::runCChessGame();
}
