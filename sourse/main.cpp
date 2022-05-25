#include <iostream>
#include "../include/chessboard.h"
#include "../include/tree_search.h"
#include "../include/alpha_beta.h"
#include "../include/multi_thread_evaluator.h"

using namespace std;

#define coo cout<<
#define aa <<
#define ee <<endl;



int main() {
    Chessboard board;
    board.move_chess(ChessPath(2, 1, 2, 4, 0));

    MultiThreadEvaluator evaluator(board, 10, TreeType::ALPHA_BETA);
    evaluator.get_best_path();

    return 0;
}
