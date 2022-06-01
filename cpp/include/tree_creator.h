//
// Created by 张睿 on 2022/5/25.
//

#ifndef VLIANG_CHINESE_CHESS_TREE_CREATOR_H
#define VLIANG_CHINESE_CHESS_TREE_CREATOR_H

#include "alpha_beta.h"
#include "mtdf.h"
#include "quiescence.h"
#include "iter_deepening.h"
#include <memory>


enum TreeType {
    ALPHA_BETA,
    ALPHA_BETA_WITH_MEMORY,
    MTDF,
    QUIE,
    MTDF_QUIE,
    ITER_DEEP
};


class TreeCreator {
public:

    static shared_ptr<TreeSearch> get_tree(Chessboard board, TreeType treeType) {
        switch (treeType) {

            case ALPHA_BETA:
                return std::make_shared<AlphaBeta>(board);

            case ALPHA_BETA_WITH_MEMORY:
                return std::make_shared<AlphaBetaWithMemory>(board);

            case MTDF:
                return std::make_shared<MTDF_Searching>(board);

            case QUIE:
                return std::make_shared<Quiescence>(board);

            case MTDF_QUIE:
                return std::make_shared<MTDF_Quiescence_Searching>(board);

            case ITER_DEEP:
                return std::make_shared<IterDeepening>(board);

            default:
                return nullptr;
        }
    }

};

#endif //VLIANG_CHINESE_CHESS_TREE_CREATOR_H
