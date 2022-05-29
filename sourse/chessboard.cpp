//
// Created by 张睿 on 2022/5/21.
//

#include "../include/chessboard.h"

void Chessboard::get_path_of_1(int x, int y, paths_t &ret) {
    int colorSign = board[x][y] > 0 ? 1 : -1;
    // 向上寻找路径
    if (x >= 1) {
        for (int i = x - 1; i >= 0; i--) {
            if (board[i][y] == 0) {
                ret.emplace_back(ChessPath(x, y, i, y));
            } else if (board[i][y] * colorSign > 0) {
                break;
            } else if (board[i][y] * colorSign < 0) {
                ret.emplace_back(ChessPath(x, y, i, y, board[i][y]));
                break;
            }
        }
    }
    // 向下寻找路径
    if (x <= 8) {
        for (int i = x + 1; i <= 9; i++) {
            if (board[i][y] == 0) {
                ret.emplace_back(ChessPath(x, y, i, y));
            } else if (board[i][y] * colorSign > 0) {
                break;
            } else if (board[i][y] * colorSign < 0) {
                ret.emplace_back(ChessPath(x, y, i, y, board[i][y]));
                break;
            }
        }
    }
    // 向左寻找路径
    if (y >= 1) {
        for (int i = y - 1; i >= 0; i--) {
            if (board[x][i] == 0) {
                ret.emplace_back(ChessPath(x, y, x, i));
            } else if (board[x][i] * colorSign > 0) {
                break;
            } else if (board[x][i] * colorSign < 0) {
                ret.emplace_back(ChessPath(x, y, x, i, board[x][i]));
                break;
            }
        }
    }
    // 向右寻找路径
    if (y <= 7) {
        for (int i = y + 1; i <= 8; i++) {
            if (board[x][i] == 0) {
                ret.emplace_back(ChessPath(x, y, x, i));
            } else if (board[x][i] * colorSign > 0) {
                break;
            } else if (board[x][i] * colorSign < 0) {
                ret.emplace_back(ChessPath(x, y, x, i, board[x][i]));
                break;
            }
        }
    }
}


void Chessboard::get_path_of_2(int x, int y, paths_t &ret) {
    int colorSign = board[x][y] > 0 ? 1 : -1;
    // 每个马当前最多有八种跳法，判断蹩马腿情况
    // 左上方
    if (x >= 2 && y >= 1 && board[x - 1][y] == 0) {
        // 没有棋子或是对方的棋子
        if (board[x - 2][y - 1] * colorSign <= 0) {
            ret.emplace_back(ChessPath(x, y, x - 2, y - 1, board[x - 2][y - 1]));
        }
    }
    if (x >= 1 && y >= 2 && board[x][y - 1] == 0) {
        if (board[x - 1][y - 2] * colorSign <= 0) {
            ret.emplace_back(ChessPath(x, y, x - 1, y - 2, board[x - 1][y - 2]));
        }
    }
    // 右上方
    if (x >= 2 && y <= 7 && board[x - 1][y] == 0) {
        if (board[x - 2][y + 1] * colorSign <= 0) {
            ret.emplace_back(ChessPath(x, y, x - 2, y + 1, board[x - 2][y + 1]));
        }
    }
    if (x >= 1 && y <= 6 && board[x][y + 1] == 0) {
        if (board[x - 1][y + 2] * colorSign <= 0) {
            ret.emplace_back(ChessPath(x, y, x - 1, y + 2, board[x - 1][y + 2]));
        }
    }
    // 左下方
    if (x <= 7 && y >= 1 && board[x + 1][y] == 0) {
        if (board[x + 2][y - 1] * colorSign <= 0) {
            ret.emplace_back(ChessPath(x, y, x + 2, y - 1, board[x + 2][y - 1]));
        }
    }
    if (x <= 8 && y >= 2 && board[x][y - 1] == 0) {
        if (board[x + 1][y - 2] * colorSign <= 0) {
            ret.emplace_back(ChessPath(x, y, x + 1, y - 2, board[x + 1][y - 2]));
        }
    }
    // 右下方
    if (x <= 7 && y <= 7 && board[x + 1][y] == 0) {
        if (board[x + 2][y + 1] * colorSign <= 0) {
            ret.emplace_back(ChessPath(x, y, x + 2, y + 1, board[x + 2][y + 1]));
        }
    }
    if (x <= 8 && y <= 6 && board[x][y + 1] == 0) {
        if (board[x + 1][y + 2] * colorSign <= 0) {
            ret.emplace_back(ChessPath(x, y, x + 1, y + 2, board[x + 1][y + 2]));
        }
    }
}


void Chessboard::get_path_of_3(int x, int y, paths_t &ret) {
    int colorSign = board[x][y] > 0 ? 1 : -1;
    if (colorSign > 0) {
        // 左上
        if ((x == 9 && y == 2) || (x == 7 && y == 4) || (x == 9 && y == 6) || (x == 7 && y == 8)) {
            if (board[x - 1][y - 1] == 0 && board[x - 2][y - 2] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x - 2, y - 2, board[x - 2][y - 2]));
            }
        }
        // 右上
        if ((x == 7 && y == 0) || (x == 9 && y == 2) || (x == 7 && y == 4) || (x == 9 && y == 6)) {
            if (board[x - 1][y + 1] == 0 && board[x - 2][y + 2] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x - 2, y + 2, board[x - 2][y + 2]));
            }
        }
        // 左下
        if ((x == 5 && y == 2) || (x == 7 && y == 4) || (x == 5 && y == 6) || (x == 7 && y == 8)) {
            if (board[x + 1][y - 1] == 0 && board[x + 2][y - 2] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x + 2, y - 2, board[x + 2][y - 2]));
            }
        }
        // 右下
        if ((x == 7 && y == 0) || (x == 5 && y == 2) || (x == 7 && y == 4) || (x == 5 && y == 6)) {
            if (board[x + 1][y + 1] == 0 && board[x + 2][y + 2] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x + 2, y + 2, board[x + 2][y + 2]));
            }
        }
    } else {
        // 左上
        if ((x == 4 && y == 2) || (x == 2 && y == 4) || (x == 2 && y == 8) || (x == 4 && y == 6)) {
            if (board[x - 1][y - 1] == 0 && board[x - 2][y - 2] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x - 2, y - 2, board[x - 2][y - 2]));
            }
        }
        // 右上
        if ((x == 4 && y == 2) || (x == 2 && y == 0) || (x == 2 && y == 4) || (x == 4 && y == 6)) {
            if (board[x - 1][y + 1] == 0 && board[x - 2][y + 2] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x - 2, y + 2, board[x - 2][y + 2]));
            }
        }
        // 左下
        if ((x == 0 && y == 2) || (x == 2 && y == 4) || (x == 0 && y == 6) || (x == 2 && y == 8)) {
            if (board[x + 1][y - 1] == 0 && board[x + 2][y - 2] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x + 2, y - 2, board[x + 2][y - 2]));
            }
        }
        // 右下
        if ((x == 2 && y == 0) || (x == 0 && y == 2) || (x == 2 && y == 4) || (x == 0 && y == 6)) {
            if (board[x + 1][y + 1] == 0 && board[x + 2][y + 2] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x + 2, y + 2, board[x + 2][y + 2]));
            }
        }
    }
}


void Chessboard::get_path_of_4(int x, int y, paths_t &ret) {
    int colorSign = board[x][y] > 0 ? 1 : -1;
    if (colorSign > 0) {
        // 左上
        if ((x == 8 && y == 4) || (x == 9 && y == 5)) {
            if (board[x - 1][y - 1] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x - 1, y - 1, board[x - 1][y - 1]));
            }
        }
        // 右上
        if ((x == 8 && y == 4) || (x == 9 && y == 3)) {
            if (board[x - 1][y + 1] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x - 1, y + 1, board[x - 1][y + 1]));
            }
        }
        // 左下
        if ((x == 8 && y == 4) || (x == 7 && y == 5)) {
            if (board[x + 1][y - 1] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x + 1, y - 1, board[x + 1][y - 1]));
            }
        }
        // 右下
        if ((x == 8 && y == 4) || (x == 7 && y == 3)) {
            if (board[x + 1][y + 1] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x + 1, y + 1, board[x + 1][y + 1]));
            }
        }
    } else {
        // 左上
        if ((x == 1 && y == 4) || (x == 2 && y == 5)) {
            if (board[x - 1][y - 1] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x - 1, y - 1, board[x - 1][y - 1]));
            }
        }
        // 右上
        if ((x == 1 && y == 4) || (x == 2 && y == 3)) {
            if (board[x - 1][y + 1] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x - 1, y + 1, board[x - 1][y + 1]));
            }
        }
        // 左下
        if ((x == 1 && y == 4) || (x == 0 && y == 5)) {
            if (board[x + 1][y - 1] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x + 1, y - 1, board[x + 1][y - 1]));
            }
        }
        // 右下
        if ((x == 1 && y == 4) || (x == 0 && y == 3)) {
            if (board[x + 1][y + 1] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x + 1, y + 1, board[x + 1][y + 1]));
            }
        }
    }
}


void Chessboard::get_path_of_5(int x, int y, paths_t &ret) {
    int colorSign = board[x][y] > 0 ? 1 : -1;
    if (colorSign > 0) {
        // 上
        if (x >= 8) {
            if (board[x - 1][y] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x - 1, y, board[x - 1][y]));
            }
        }
        // 下
        if (x <= 8) {
            if (board[x + 1][y] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x + 1, y, board[x + 1][y]));
            }
        }
        // 左
        if (y >= 4) {
            if (board[x][y - 1] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x, y - 1, board[x][y - 1]));
            }
        }
        // 右
        if (y <= 4) {
            if (board[x][y + 1] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x, y + 1, board[x][y + 1]));
            }
        }
    } else {
        // 上
        if (x >= 1) {
            if (board[x - 1][y] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x - 1, y, board[x - 1][y]));
            }
        }
        // 下
        if (x <= 1) {
            if (board[x + 1][y] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x + 1, y, board[x + 1][y]));
            }
        }
        // 左
        if (y >= 4) {
            if (board[x][y - 1] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x, y - 1, board[x][y - 1]));
            }
        }
        // 右
        if (y <= 4) {
            if (board[x][y + 1] * colorSign <= 0) {
                ret.emplace_back(ChessPath(x, y, x, y + 1, board[x][y + 1]));
            }
        }
    }
}


void Chessboard::get_path_of_6(int x, int y, paths_t &ret) {
    int colorSign = board[x][y] > 0 ? 1 : -1;
    // 上
    if (x >= 1) {
        int i = x - 1;
        for (; i >= 0; i--) {
            if (board[i][y] == 0) {
                ret.emplace_back(ChessPath(x, y, i, y));
            } else {
                break;
            }
        }
        if (i >= 1) {
            for (int j = i - 1; j >= 0; j--) {
                if (board[j][y] != 0) {
                    // 对方棋子，可将其吃掉，退出循环
                    if (board[j][y] * colorSign < 0) {
                        ret.emplace_back(ChessPath(x, y, j, y, board[j][y]));
                        break;
                    } else { // 己方棋子，退出循环
                        break;
                    }
                }
            }
        }
    }
    // 下
    if (x <= 8) {
        int i = x + 1;
        for (; i <= 9; i++) {
            if (board[i][y] == 0) {
                ret.emplace_back(ChessPath(x, y, i, y));
            } else {
                break;
            }
        }
        if (i <= 8) {
            for (int j = i + 1; j <= 9; j++) {
                if (board[j][y] != 0) {
                    // 对方棋子，可将其吃掉，退出循环
                    if (board[j][y] * colorSign < 0) {
                        ret.emplace_back(ChessPath(x, y, j, y, board[j][y]));
                        break;
                    } else { // 己方棋子，退出循环
                        break;
                    }
                }
            }
        }
    }
    // 左
    if (y >= 1) {
        int i = y - 1;
        for (; i >= 0; i--) {
            if (board[x][i] == 0) {
                ret.emplace_back(ChessPath(x, y, x, i));
            } else {
                break;
            }
        }
        if (i >= 1) {
            for (int j = i - 1; j >= 0; j--) {
                if (board[x][j] != 0) {
                    if (board[x][j] * colorSign < 0) {
                        ret.emplace_back(ChessPath(x, y, x, j, board[x][j]));
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    // 右
    if (y <= 7) {
        int i = y + 1;
        for (; i <= 8; i++) {
            if (board[x][i] == 0) {
                ret.emplace_back(ChessPath(x, y, x, i));
            } else {
                break;
            }
        }
        if (i <= 7) {
            for (int j = i + 1; j <= 8; j++) {
                if (board[x][j] != 0) {
                    if (board[x][j] * colorSign < 0) {
                        ret.emplace_back(ChessPath(x, y, x, j, board[x][j]));
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
    }
}


void Chessboard::get_path_of_7(int x, int y, paths_t &ret) {
    int colorSign = board[x][y] > 0 ? 1 : -1;
    if (colorSign > 0) {
        // 上
        if (x >= 1 && board[x - 1][y] * colorSign <= 0) {
            ret.emplace_back(ChessPath(x, y, x - 1, y, board[x - 1][y]));
        }
    } else {
        // 下
        if (x <= 8 && board[x + 1][y] * colorSign <= 0) {
            ret.emplace_back(ChessPath(x, y, x + 1, y, board[x + 1][y]));
        }
    }
    // 过河后可以向左向右
    if ((colorSign > 0 && x <= 4) || (colorSign < 0 && x >= 5)) {
        // 左
        if (y >= 1 && board[x][y - 1] * colorSign <= 0) {
            ret.emplace_back(ChessPath(x, y, x, y - 1, board[x][y - 1]));
        }
        // 右
        if (y <= 7 && board[x][y + 1] * colorSign <= 0) {
            ret.emplace_back(ChessPath(x, y, x, y + 1, board[x][y + 1]));
        }
    }
}


void Chessboard::get_chess_path_of_id(int x, int y, paths_t &ret) {
    int id = board[x][y];
    if (id == 1 || id == -1) {
        get_path_of_1(x, y, ret);
    } else if (id == 2 || id == -2) {
        get_path_of_2(x, y, ret);
    } else if (id == 3 || id == -3) {
        get_path_of_3(x, y, ret);
    } else if (id == 4 || id == -4) {
        get_path_of_4(x, y, ret);
    } else if (id == 5 || id == -5) {
        get_path_of_5(x, y, ret);
    } else if (id == 6 || id == -6) {
        get_path_of_6(x, y, ret);
    } else if (id == 7 || id == -7) {
        get_path_of_7(x, y, ret);
    }
}


bool Chessboard::is_general_face2face() {
    int rivalY = 0;
    for (int i = 3; i <= 5; i++) {
        bool findFlag = false;
        for (int j = 0; j <= 2; j++) {
            if (board[i][j] == -5) {
                rivalY = j;
                findFlag = true;
            }
            if (findFlag) {
                break;
            }
        }
    }
    bool isFind = false;
    for (int i = 7; i <= 9; i++) {
        if (board[i][rivalY] == 5) {
            isFind = true;
            break;
        }
    }
    // r如果没有
    if (!isFind) {
        return false;
    }
    bool getRivalGeneral = false;
    for (int i = 0; board[i][rivalY] != 5; i++) {
        if (board[i][rivalY] == -5) {
            getRivalGeneral = true;
            continue;
        }
        if (getRivalGeneral && board[i][rivalY] != 0) {
            return true;
        }
    }
    return false;
}


void Chessboard::init_chessboard() {
    for (auto &i: this->board) {
        for (int &j: i) {
            j = 0;
        }
    }
    this->board[0][0] = -Chess::JU;
    this->board[0][1] = -Chess::MA;
    this->board[0][2] = -Chess::XIANG;
    this->board[0][3] = -Chess::SHI;
    this->board[0][4] = -Chess::JIANG;
    this->board[0][5] = -Chess::SHI;
    this->board[0][6] = -Chess::XIANG;
    this->board[0][7] = -Chess::MA;
    this->board[0][8] = -Chess::JU;
    this->board[2][1] = -Chess::PAO;
    this->board[2][7] = -Chess::PAO;
    this->board[3][0] = -Chess::ZU;
    this->board[3][2] = -Chess::ZU;
    this->board[3][4] = -Chess::ZU;
    this->board[3][6] = -Chess::ZU;
    this->board[3][8] = -Chess::ZU;
    // 我方
    this->board[9][0] = Chess::JU;
    this->board[9][1] = Chess::MA;
    this->board[9][2] = Chess::XIANG;
    this->board[9][3] = Chess::SHI;
    this->board[9][4] = Chess::JIANG;
    this->board[9][5] = Chess::SHI;
    this->board[9][6] = Chess::XIANG;
    this->board[9][7] = Chess::MA;
    this->board[9][8] = Chess::JU;
    this->board[7][1] = Chess::PAO;
    this->board[7][7] = Chess::PAO;
    this->board[6][0] = Chess::ZU;
    this->board[6][2] = Chess::ZU;
    this->board[6][4] = Chess::ZU;
    this->board[6][6] = Chess::ZU;
    this->board[6][8] = Chess::ZU;
}


void Chessboard::get_all_paths(int colorSign, paths_t &ret) {
    if (colorSign > 0) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                if (this->board[i][j] > 0) {
                    get_chess_path_of_id(i, j, ret);
                }
            }
        }
    } else {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                if (this->board[i][j] < 0) {
                    get_chess_path_of_id(i, j, ret);
                }
            }
        }
    }

    // 计算走棋后改变的权重
    for (auto &path: ret) {
        int id = board[path.from_x][path.from_y];
        int eatVal = path.eat == 0 ? 0 : get_pos_val(path.eat, path.to_x, path.to_y);
        int after = get_pos_val(id, path.to_x, path.to_y);
        int before = get_pos_val(id, path.from_x, path.from_y);
        path.value = after - before - eatVal;
    }
}


void Chessboard::move_chess(const ChessPath &path) {
    board[path.to_x][path.to_y] = board[path.from_x][path.from_y];
    board[path.from_x][path.from_y] = 0;
}


void Chessboard::undo_move_chess(const ChessPath &path) {
    board[path.from_x][path.from_y] = board[path.to_x][path.to_y];
    board[path.to_x][path.to_y] = path.eat;
}


int Chessboard::get_on_board_val() {
    int val = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (this->board[i][j] != 0) {
                int id = board[i][j];
                if (id == 0) {
                    continue;
                }
                val += (id > 0) ? weights[id][i][j] : -weights[-id][9 - i][8 - j];
            }
        }
    }
    return val;
}


inline static string num2char(int num) {
    switch (num) {
        case 0:
            return "零";
        case 1:
            return "一";
        case 2:
            return "二";
        case 3:
            return "三";
        case 4:
            return "四";
        case 5:
            return "五";
        case 6:
            return "六";
        case 7:
            return "七";
        case 8:
            return "八";
        case 9:
            return "九";
    }
    return "";
}


void Chessboard::print_chessboard() {
    printf("%5s", "");
    for (int i = 0; i < 9; i++) {
        printf("%6d", i);
    }
    printf("\n");
    printf("   --------------------------------------------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("%6s", num2char(i).c_str());
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                printf("%6c", '.');
            } else {
                printf("%6d", board[i][j]);
            }
        }
        printf("\n\n");
    }
    printf("\n\n");
}


void Chessboard::copy(Chessboard &chessboard) {
    for (int i = 0; i < CHESSBOARD_ROWS; i++) {
        for (int j = 0; j < CHESSBOARD_COLS; ++j) {
            this->board[i][j] = chessboard.board[i][j];
        }
    }
}


int Chessboard::get_hash() {
    int hash = 0;
    for (int i = 0; i < CHESSBOARD_ROWS; i++) {
        for (int j = 0; j < CHESSBOARD_COLS; j++) {
            if (this->board[i][j] != 0) {
                hash ^= get_hash_code_of_id(board[i][j], i, j);
            }
        }
    }
    return hash;
}


int Chessboard::get_verify() {
    int hash = 0;
    for (int i = 0; i < CHESSBOARD_ROWS; i++) {
        for (int j = 0; j < CHESSBOARD_COLS; j++) {
            if (this->board[i][j] != 0) {
                hash ^= get_verify_code_of_id(board[i][j], i, j);
            }
        }
    }
    return hash;
}


bool Chessboard::is_checked(int color_sign) {
    paths_t paths;
    get_all_paths(-color_sign, paths);
    for (auto &chessPath : paths) {
        if (chessPath.eat == 5 || chessPath.eat == -5) {
            return true;
        }
    }
    return false;
}


ostream &operator<<(ostream &out, const ChessPath &path) {
    out << "Path{ <" << path.from_x << ", " << path.from_y << "> to <" << path.to_x << ", " << path.to_y
        << "> eat " << path.eat << "} " << "value = " << path.value;
    return out;
}


