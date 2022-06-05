cmake_minimum_required(VERSION 3.20)
project(vliang_chinese_chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(vliang_chinese_chess main.cpp cpp/include/chessboard.h cpp/include/zobrist_code.h cpp/include/weights.h cpp/sourse/chessboard.cpp cpp/include/alpha_beta.h cpp/include/tree_search.h cpp/sourse/tree_search.cpp cpp/include/multi_thread_evaluator.h cpp/include/tree_creator.h cpp/sourse/alpha_beta.cpp
        cpp/include/mtdf.h cpp/include/transition_table.hpp cpp/include/quiescence.h cpp/sourse/quiescence.cpp cpp/include/iter_deepening.h cpp/sourse/multi_thread_evaluator.cpp py_interface.cpp)
