#ifndef _59_GENERATE_MATRIX_H
#define _59_GENERATE_MATRIX_H

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

// 59  螺旋矩阵II
/*******************************************************************************************
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]

| 1 2 3 |
| 8 9 4 |
| 7 6 5 |
*********************************************************************************************/
class Solution59{

public:
    std::vector<std::vector<int> > generateMatrix(int n);
    
    void test();

};

#endif