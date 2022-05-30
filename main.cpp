#include "include/multi_thread_evaluator.h"

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

            auto chess_path = convertPath(path);
            stack.push(chess_path);
            cChessboard.move_chess(chess_path);
            cChessboard.print_chessboard();

            // ai
            MultiThreadEvaluator evaluator(cChessboard, 6, TreeType::QUIE);
            ChessPath best = evaluator.get_best_path();
            cChessboard.move_chess(best);
            stack.push(best);
            cChessboard.print_chessboard();
        }
    }
};


int main() {
//    Chessboard board;
//    board.move_chess(ChessPath(2, 1, 2, 4, 0));
//    board.print_chessboard();
//    MultiThreadEvaluator evaluator(board, 8, TreeType::MTDF);
//    evaluator.get_best_path();
    ConsoleGame::runCChessGame();
    return 0;
}
