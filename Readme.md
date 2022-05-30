# 微量-中国象棋

------
👤作者：睿

📧邮件：rayZhh@163.com

------

## 简介

这个项目是我仓库中vlumino-chinese chess的++复现。实现了基本的搜索算法，优化了代码的结构。 经对比，相同局面使用c++评估速度更快（约两倍的性能）。

代码中可能会出现逻辑上的错误。这个真的不好debug。 由于只能根据输出的结果去分析，我很难确定是代码逻辑上的问题还是算法本身的结果就这样。

## 说明

·main.cpp中有控制台游戏，直接运行即可。可以尝试不同的搜索算法。

·暂时不支持开局库

·目前没有做前端/GUI

## 未来的工作

·可能增加"空着剪枝"，进一步加快评估速度。

·可能做一个python的接口，更方便的构建GUI。

·可能优化置换表和静态搜索。

## 编译运行

```shell
g++ -std=c++20 -O3 -o chess main.cpp source/*.cpp
./chess
```

## 评估

```c++
#include "include/multi_thread_evaluator.h"

int main() {
    Chessboard board;
    
    board.move_chess(ChessPath(2, 1, 2, 4, 0));
    
    board.print_chessboard();
    
    // 创建评估器
    MultiThreadEvaluator evaluator(board, 8, TreeType::MTDF);
    // 评估
    auto path = evaluator.get_best_path();
    // 落子
    board.move_chess(path);
    
    return 0;
}
```