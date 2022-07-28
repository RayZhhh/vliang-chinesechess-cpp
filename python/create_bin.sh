#!/bin/bash

echo "g++ -std=c++20 -O3 -o ./bin/vliang_py_interface ../py_interface.cpp ../cpp/source/*.cpp"

# 创建bin目录
if [ -f "bin" ]
then
  echo "bin is already exist"
else
  mkdir bin
fi

# 编译得到 vliang_py_interface 并放入 bin/ 目录下
g++ -std=c++20 -O3 -o ./bin/vliang_py_interface ../py_interface.cpp ../cpp/source/*.cpp
