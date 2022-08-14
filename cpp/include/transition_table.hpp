//
// Created by Derek on 2022/5/28.
//

#ifndef VLIANG_CHINESE_CHESS_TRANSITION_TABLE_HPP
#define VLIANG_CHINESE_CHESS_TRANSITION_TABLE_HPP

#include <unordered_map>


template<class TableMsg>
class TranTable {

    unordered_map<int, unordered_map<int, TableMsg *>> map;

public:

    inline TableMsg *get_table(int hash, int verify) {
        return map[hash][verify];
    }

    inline void add_table(TableMsg *table, int hash, int verify) {
        map[hash][verify] = table;
    }

    ~TranTable() {
        for (auto &i: this->map) {
            for (auto &j : i.second) {
                delete j.second;
            }
        }
    }
};



#endif //VLIANG_CHINESE_CHESS_TRANSITION_TABLE_HPP
