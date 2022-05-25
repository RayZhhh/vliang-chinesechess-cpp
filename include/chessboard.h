//
// Created by 张睿 on 2022/5/17.
//

#ifndef VLIANG_CHINESE_CHESS_CHESSBOARD_H
#define VLIANG_CHINESE_CHESS_CHESSBOARD_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "weights.h"


using namespace std;


#define CHESSBOARD_ROWS 10
#define CHESSBOARD_COLS 9


class Chess;

class ChessPath;

class Chessboard;


typedef int chessboard_t[CHESSBOARD_ROWS][CHESSBOARD_COLS];
typedef vector<ChessPath> paths_t;


class Chess {
public:
    const static int JU = 1;
    const static int MA = 2;
    const static int XIANG = 3;
    const static int SHI = 4;
    const static int JIANG = 5;
    const static int PAO = 6;
    const static int ZU = 7;
};


class ChessPath {
    friend ostream &operator<<(ostream &out , const ChessPath &a);

public:
    int from_x;
    int from_y;
    int to_x;
    int to_y;
    int eat;
    int value;

    ChessPath(int from_x, int from_y, int to_x, int to_y, int eat) :
            from_x(from_x), from_y(from_y), to_x(to_x), to_y(to_y), eat(eat) {
    }

    ChessPath(int from_x, int from_y, int to_x, int to_y) :
            from_x(from_x), from_y(from_y), to_x(to_x), to_y(to_y), eat(0) {
    }

};


class Chessboard {
public:
    chessboard_t board;

private:
    void get_path_of_1(int x, int y, paths_t &ret);

    void get_path_of_2(int x, int y, paths_t &ret);

    void get_path_of_3(int x, int y, paths_t &ret);

    void get_path_of_4(int x, int y, paths_t &ret);

    void get_path_of_5(int x, int y, paths_t &ret);

    void get_path_of_6(int x, int y, paths_t &ret);

    void get_path_of_7(int x, int y, paths_t &ret);

public:
    Chessboard() {
        this->init_chessboard();
    }

//    Chessboard(Chessboard &chessboard) {
//        for (int i = 0; i < CHESSBOARD_ROWS; i++) {
//            for (int j = 0; j < CHESSBOARD_COLS; ++j) {
//                this->board[i][j] = chessboard.board[i][j];
//            }
//        }
//        this->init_chessboard();
//    }

    void copy(Chessboard &chessboard);

    void get_chess_path_of_id(int x, int y, paths_t &ret);

    void get_all_paths(int color_sign, paths_t &ret);

    bool is_general_face2face();

    void init_chessboard();

    void move_chess(const ChessPath &path);

    void undo_move_chess(const ChessPath &path);

    int get_on_board_val();

    void print_chessboard();
};


#endif //VLIANG_CHINESE_CHESS_CHESSBOARD_H
