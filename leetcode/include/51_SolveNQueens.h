#ifndef _51_SOLVE_N_QUEENS_H
#define _51_SOLVE_N_QUEENS_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <string.h>  // memset的头文件
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>

// 51  N皇后问题
/******************************************************************
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。


输入：n = 4

输出：[[".Q..",
        "...Q",
        "Q...",
        "..Q."],

       ["..Q.",
        "Q...",
        "...Q",
        ".Q.."]]

解释：如上图所示，4 皇后问题存在两个不同的解法。

 *******************************************************************/
class Solution51{

public:
    std::vector<std::vector<std::string>> solveNQueens(int n){
        auto solutions = std::vector<std::vector<std::string>>();
        auto queens = std::vector<int>(n, -1);  // 每一行(n)的第几列放了一个皇后
        auto columns = std::unordered_set<int>();
        auto diagonals1 = std::unordered_set<int>();
        auto diagonals2 = std::unordered_set<int>();
        backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
        return solutions;
    }

    void backtrack(std::vector<std::vector<std::string>> &solutions, 
                    std::vector<int> &queens, 
                    int n, // n皇后
                    int row, // 现在是第几行
                    std::unordered_set<int> &columns, 
                    std::unordered_set<int> &diagonals1,
                    std::unordered_set<int> &diagonals2) 
    {
        if (row == n) {
            std::vector<std::string> board = generateBoard(queens, n);
            solutions.push_back(board);
        }
        else
        {
            // 对这一行的每一列回溯
            for (int i = 0; i < n; i++) {
                // 在这一列能被吃到, 退出...
                if (columns.find(i) != columns.end()) {
                    continue;
                }

                // 左上到右下的斜线号
                int diagonal1 = row - i;
                if (diagonals1.find(diagonal1) != diagonals1.end()) {
                    continue;
                }

                // 右上到左下的斜线号
                int diagonal2 = row + i;
                if (diagonals2.find(diagonal2) != diagonals2.end()) {
                    continue;
                }
                
                queens[row] = i;  // 第row行第i列放一个皇后, 也可以理解为, 有n个皇后, 每一行一个, 这是第row个, 放在第i列
                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);

                // 去下一行, 然后又对下一行的每一列判断
                backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);

                queens[row] = -1;
                columns.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);
            }
        }
    }

    std::vector<std::string> generateBoard(std::vector<int> &queens, int n) {
        auto board = std::vector<std::string>();
        for (int i = 0; i < n; i++) {
            std::string row = std::string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }

    void test();

};

#endif