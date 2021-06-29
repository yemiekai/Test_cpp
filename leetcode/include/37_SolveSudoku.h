#ifndef _37_SOLVE_SUDOKU_H
#define _37_SOLVE_SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <string.h>  // memset的头文件

#include <vector>
#include <map>
#include <set>

// 37 有效的数独
class Solution37 {
private:
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];
    bool valid;
    std::vector<std::pair<int, int> > spaces;



public:
    void dfs(std::vector<std::vector<char>>& board, int pos){

        if (pos == spaces.size()) {
            valid = true;
            return;
        }
        
        // 取出空位置的坐标
        auto mPair = spaces[pos];
        int i = mPair.first;
        int j = mPair.second;

        // 对这个位置尝试填入0~9的数
        for (int digit = 0; digit < 9 && !valid; ++digit) {
            // 位置合法(行、列、格子 都没出现过这个数)
            if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {

                // 置标志位
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;

                // 填进数字
                board[i][j] = digit + '0' + 1;

                // 递归进去, 找下一个空白位 
                dfs(board, pos + 1);

                // 标志位复原
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
            }
        }


    }
    void solveSudoku(std::vector<std::vector<char>>& board){
        memset(line, false, sizeof(line));
        memset(column, false, sizeof(column));
        memset(block, false, sizeof(block));
        valid = false;

        // 首先遍历一次输入, 把状态初始化
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    // 此位置为空, 记下来
                    spaces.emplace_back(i, j);  
                }
                else {
                    // 已有数据, 设置标志位
                    int digit = board[i][j] - '0' - 1;
                    line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                }
            }
        }

        dfs(board, 0);
    }

    void test();

};

#endif