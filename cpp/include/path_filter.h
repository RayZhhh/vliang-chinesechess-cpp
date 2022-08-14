//
// Created by 张睿 on 2022/8/1.
//

#ifndef VLIANG_CHINESE_CHESS_PATH_FILTER_H
#define VLIANG_CHINESE_CHESS_PATH_FILTER_H


class GameRecorder {

    class RecorderTable {
    public:
        int time = 1;
    };

public:

    int max_repeat_times;

    GameRecorder() {
        max_repeat_times = 5;
    }

    unordered_map<int, unordered_map<int, RecorderTable *>> record_map{};

    /**
     * 记录当前的棋盘
     * @param board
     */
    void recode(Chessboard board) {
        RecorderTable *rt;
        if ((rt = record_map[board.get_hash()][board.get_verify()]) != nullptr) {
            rt->time++;
        } else {
            record_map[board.get_hash()][board.get_verify()] = new RecorderTable();
        }
    }

    /**
     * 查询在当前 board 下，如果要走path那么出现的盘面次数
     * @param board
     * @return
     */
    int find_same_times(Chessboard board) {
        RecorderTable *rt;
        if ((rt = record_map[board.get_hash()][board.get_verify()]) != nullptr) {
            return rt->time;
        } else {
            return 0;
        }
    }

    /**
     * 筛选路径。
     * 对打过分的路径进行筛选。将路径得分按照从高到低排序，依次查看每个路径落子后的棋盘情况。
     * 如果当前落子方法导致棋盘局面重复超过某个次数那么放弃这种走法。否则选择这种走法。
     *
     * 获得路径后不会记录落子后的盘面情况。
     *
     * @param board
     * @param paths
     * @return
     */
    ChessPath choose_path(Chessboard board, paths_t &paths) {
        for (auto &path : paths) {
            int times = find_same_times(board);
            if (times > max_repeat_times) {
                continue;
            } else {
                return path;
            }
        }
    }

    ~GameRecorder() {
        for (auto &i : record_map) {
            for (auto &j : i.second) {
                delete j.second;
            }
        }
    }
};

#endif //VLIANG_CHINESE_CHESS_PATH_FILTER_H
