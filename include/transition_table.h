//
// Created by Derek on 2022/5/28.
//

#ifndef VLIANG_CHINESE_CHESS_TRANSITION_TABLE_H
#define VLIANG_CHINESE_CHESS_TRANSITION_TABLE_H


template<class TableMsg>
class TranTable {
    const static int HASH_SIZE = 1 << 20;
    const static int VER_SIZE = 1 << 10;
    const static int HASH_KEY = HASH_SIZE - 1;
    const static int VER_KEY = VER_SIZE - 1;

    TableMsg *map[HASH_SIZE][VER_SIZE]{nullptr};

public:
    TranTable() {
        for (auto &i: this->map) {
            for (auto &j: i) {
                j = nullptr;
            }
        }
    }

    TableMsg *get_table(int hash, int verify) {
        return map[hash & HASH_KEY][verify & VER_KEY];
    }

    void add_table(TableMsg *table, int hash, int verify) {
        map[hash & HASH_KEY][verify & VER_KEY] = table;
    }

    ~TranTable() {
        for (auto &i: this->map) {
            for (auto &j: i)
                delete j;
        }
    }
};

#endif //VLIANG_CHINESE_CHESS_TRANSITION_TABLE_H
