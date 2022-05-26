cmake_minimum_required(VERSION 3.20)
project(vliang_chinese_chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(vliang_chinese_chess sourse/main.cpp include/chessboard.h include/zobrist_code.h include/weights.h sourse/chessboard.cpp include/alpha_beta.h include/tree_search.h sourse/tree_search.cpp include/multi_thread_evaluator.h include/tree_creator.h sourse/alpha_beta.cpp
        hashmap/HashMap.h hashmap/HashBucket.h hashmap/HashNode.h)
