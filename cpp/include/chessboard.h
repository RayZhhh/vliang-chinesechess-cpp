//
// Created by 张睿 on 2022/5/17.
//

#ifndef VLIANG_CHINESE_CHESS_CHESSBOARD_H
#define VLIANG_CHINESE_CHESS_CHESSBOARD_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "_weights.h"
#include "_zobrist_code.h"

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
    friend ostream &operator<<(ostream &out, const ChessPath &a);

public:
    /**
     * 初始点：(from_x, from_y)
     */
    int from_x, from_y;

    /**
     * 落子点：(to_x, to_y)
     */
    int to_x, to_y;

    /**
     * 吃的子
     */
    int eat;

    /**
     * 当前走法的价值
     */
    int value;

    /**
     * 用于打印当前路径的信息
     * @return 路径信息
     *
     * 用法：
     * ChessPath path;  std::cout << path.to_string() << std::endl;
     */
    string to_string();

    ChessPath() {}

    ChessPath(int from_x, int from_y, int to_x, int to_y, int eat) :
            from_x(from_x), from_y(from_y), to_x(to_x), to_y(to_y), eat(eat) {
    }

    ChessPath(int from_x, int from_y, int to_x, int to_y) :
            from_x(from_x), from_y(from_y), to_x(to_x), to_y(to_y), eat(0) {
    }
};


class Chessboard {
public:
    /**
     * 内置的棋盘对象。
     * typedef int chessboard_t[10][9]
     */
    chessboard_t board;

private:
    /**
     * 获得车的所有走法。
     * @param x 车的坐标x
     * @param y 车的坐标y
     * @param ret 路径将存储到这个数组中
     */
    void get_path_of_1(int x, int y, paths_t &ret);

    /**
     * 获得马的所有走法。
     * @param x 马的坐标x
     * @param y 马的坐标y
     * @param ret 路径将存储到这个数组中
     */
    void get_path_of_2(int x, int y, paths_t &ret);

    /**
     * 获得象的所有走法。
     * @param x 象的坐标x
     * @param y 象的坐标y
     * @param ret 路径将存储到这个数组中
     */
    void get_path_of_3(int x, int y, paths_t &ret);

    /**
     * 获得士的所有走法。
     * @param x 士的坐标x
     * @param y 士的坐标y
     * @param ret 路径将存储到这个数组中
     */
    void get_path_of_4(int x, int y, paths_t &ret);

    /**
     * 获得将的所有走法。
     * @param x 将的坐标x
     * @param y 将的坐标y
     * @param ret 路径将存储到这个数组中
     */
    void get_path_of_5(int x, int y, paths_t &ret);

    /**
     * 获得炮的所有走法。
     * @param x 炮的坐标x
     * @param y 炮的坐标y
     * @param ret 路径将存储到这个数组中
     */
    void get_path_of_6(int x, int y, paths_t &ret);

    /**
     * 获得兵的所有走法。
     * @param x 兵的坐标x
     * @param y 兵的坐标y
     * @param ret 路径将存储到这个数组中
     */
    void get_path_of_7(int x, int y, paths_t &ret);

    /**
     * 将阿拉伯数字转换成中国数字
     * @param num
     * @return
     */
    inline string num2char(int num);

public:
    Chessboard() {
        this->init_chessboard();
    }

    /**
     * 复制棋盘
     * @param chessboard
     */
    void copy(Chessboard &chessboard);

    /**
     * 复制棋盘
     * @param board
     */
    void copy(chessboard_t board);

    /**
     * 获得当前棋子的所有路径。
     * @param x 当前棋子的坐标x
     * @param y 当前棋子的坐标y
     * @param ret 路径将保存到这个数组中
     */
    void get_chess_path_of_id(int x, int y, paths_t &ret);

    /**
     * 获得某一方的棋子的所有可能路径。
     * @param color_sign 棋子颜色 1：正数方 2：负数方
     * @param ret 路径将保存到这个数组中
     */
    void get_all_paths(int color_sign, paths_t &ret);

    /**
     * 判断是否发生对将。
     * @return true：发生对将 false：没有发生对将
     */
    bool is_general_face2face();

    /**
     * 某一方是否正在被将军。
     * @param color_sign 棋子颜色 1：正数方 2：负数方
     * @return true：某一方正在被将军 false：当前没有被将军
     */
    bool is_checked(int color_sign);

    /**
     * 初始化棋盘，恢复成初始棋盘。
     */
    void init_chessboard();

    /**
     * 落子。
     * @param path 棋子的路径
     */
    void move_chess(const ChessPath &path);

    /**
     * 恢复走棋。
     * 主要用于在进行搜索时需要恢复棋盘。
     * @param path 要恢复的路径
     */
    void undo_move_chess(const ChessPath &path);

    /**
     * 获得当前盘面的打分。
     * @return 当前盘面的得分值
     */
    int get_on_board_val();

    /**
     * 打印棋盘
     */
    void print_chessboard();

    /**
     * 获得棋盘的哈希值。
     * 使用 zobrist 哈希码作为哈希方法。
     * @return 棋盘的哈希值
     */
    int get_hash();

    /**
     * 获得棋盘的校验哈希值。
     * 由于单哈希会导致冲突，因此需要补充校验码。校验码同样通过 zobrist 方法获得。
     * @return
     */
    int get_verify();

    /**
     * 判断棋盘是否相等。
     * @param chessboard 另一个棋盘
     * @return 是否是相同的棋盘
     */
    bool operator==(const Chessboard &chessboard) const;

    /**
     * 获得棋盘的序列。
     * 从上到下，从左到右遍历整个棋盘，将每个元素用 "," 连接。
     * @return
     */
    string get_board_sequence();

    /**
     * 将棋盘进行左右对称。
     */
    void symmetry_board();

    /**
     * 交换边，即红黑双方互换。
     */
    void change_side();
};


#endif //VLIANG_CHINESE_CHESS_CHESSBOARD_H
