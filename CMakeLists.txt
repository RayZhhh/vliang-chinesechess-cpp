cmake_minimum_required(VERSION 3.20)
project(vliang_chinese_chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(vliang_chinese_chess main.cpp cpp/include/chessboard.h cpp/include/zobrist_code.h cpp/include/weights.h cpp/source/chessboard.cpp cpp/include/alpha_beta.h cpp/include/tree_search.h cpp/source/tree_search.cpp cpp/include/evaluator.h cpp/include/tree_creator.hpp cpp/source/alpha_beta.cpp
        cpp/include/mtdf.h cpp/include/transition_table.hpp cpp/include/quiescence.h cpp/source/quiescence.cpp cpp/source/evaluator.cpp py_interface.cpp cpp/source/mtdf.cpp cpp/include/path_filter.h test/evaluator_so.cpp)
