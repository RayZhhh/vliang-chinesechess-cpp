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
    board.print_chessboard();

    MultiThreadEvaluator evaluator(board, 8, TreeType::ALPHA_BETA_WITH_MEMORY);
    evaluator.get_best_path();


    return 0;
}
