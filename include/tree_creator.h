//
// Created by 张睿 on 2022/5/25.
//

#ifndef VLIANG_CHINESE_CHESS_TREE_CREATOR_H
#define VLIANG_CHINESE_CHESS_TREE_CREATOR_H

#include "alpha_beta.h"
#include <memory>

enum TreeType {
    ALPHA_BETA,
    ALPHA_BETA_WITH_MEMORY
};


class TreeCreator {
public:

    static shared_ptr<TreeSearch> get_tree(Chessboard board, TreeType treeType) {
        switch (treeType) {
            case ALPHA_BETA:
                return std::make_shared<AlphaBeta>(board);

            case ALPHA_BETA_WITH_MEMORY:
                return std::make_shared<AlphaBetaWithMemory>(board);

            default:
                return nullptr;
        }
    }

};

#endif //VLIANG_CHINESE_CHESS_TREE_CREATOR_H
