#include "59_GenerateMatrix.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>

// 59  螺旋矩阵II
/*******************************************************************************************
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]

| 1 2 3 |
| 8 9 4 |
| 7 6 5 |
*********************************************************************************************/
std::vector<std::vector<int> > Solution59::generateMatrix(int n){
    std::vector<std::vector<int> > result(n, std::vector<int>(n, 0));
    
    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int nowDirect = 0;
    int col = 0;
    int row = 0;

    int nextRow = 0;
    int nextCol = 0;
    for(int i = 0; i < n*n; i++){
        result[row][col] = i+1;

        // 尝试走一步
        nextRow = row + direction[nowDirect%4][0];
        nextCol = col + direction[nowDirect%4][1];
        
        // 要换方向了(先判断位置, 再判断数组, 不然会越界报错)
        if(nextRow >= n || nextRow < 0
            || nextCol >= n || nextCol <0 
            || result[nextRow][nextCol] != 0 )
        {
                nowDirect++;
        }

        row = row + direction[nowDirect%4][0];
        col = col + direction[nowDirect%4][1];
    }
    return result;
}


void Solution59::test(){


}

