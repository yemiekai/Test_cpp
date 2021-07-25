#ifndef _52_SOLVE_N_QUEENS_2_H
#define _52_SOLVE_N_QUEENS_2_H

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

// 52  N皇后问题2
/******************************************************************

 和51一样的

*******************************************************************/
class Solution52{

public:

    std::unordered_set<int> colums;
    std::unordered_set<int> d1;  // 左上到右下的斜线
    std::unordered_set<int> d2;  // 
    std::vector<int> queens;
    int result;

    void dfs(int n, int nowRow){
        if(n == nowRow){
            result++;
            return;
        }

        for(int col = 0; col < n; col++){
            int idx_d1 = nowRow - col;
            if(d1.find(idx_d1) != d1.end()){
                continue;
            }

            int idx_d2 = nowRow + col;
            if(d2.find(idx_d2) != d2.end()){
                continue;
            }

            if(colums.find(col) != colums.end()){
                continue;
            }

            colums.insert(col);
            d1.insert(idx_d1);
            d2.insert(idx_d2);

            dfs(n, nowRow+1);

            colums.erase(col);
            d1.erase(idx_d1);
            d2.erase(idx_d2);

        }
    }

    int totalNQueens(int n);
    void test();

};

#endif