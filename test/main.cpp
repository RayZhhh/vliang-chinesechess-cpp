//
//  main.cpp
//  test
//
//  Created by 张睿 on 2022/8/14.
//

#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int main(int argc, const char *argv[]) {
    string line;
    auto fin = ifstream("t.txt");
    auto fout = ofstream("out.py", ios::out);

    while (!fin.eof()) {
        getline(fin, line);

        for (char &i: line) {
            if (i == ';') {
                i = ' ';
            } else if (i == '{') {
                i = ':';
            } else if (i == '}') {
                i = ' ';
            } else if (i == '(') {
                i = ' ';
            } else if (i == ')') {
                i = ' ';
            }
        }

        fout << line << endl;
    }
    return 0;
}
