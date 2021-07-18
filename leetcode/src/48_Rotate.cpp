#include "48_Rotate.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>


/***********************************************************
 * 48 旋转图像
 * 
 * 
 *   1  2  3        7  4  1      5  1  9  11        15 13  2  5
 *   4  5  6   ->   8  5  2      2  4  8  10   ->   14  3  4  1  
 *   7  8  9        9  6  3      13 3  6  7         12  6  8  9
 *                               15 14 12 16        16  7  10 11
 * 
 *******************************************************************/

void Solution48::rotate(std::vector<std::vector<int> > &matrix){
    int length = matrix.size();
    
    // 首先每一行倒序
    for(int i = 0; i <length; i++){
        std::reverse(matrix[i].begin(), matrix[i].end());
    }

    // 然后转置
    for(int i=0; i<length; i++){
        for(int j=0; j<length-i; j++){
            std::swap(matrix[i][j], matrix[length-j-1][length-i-1]);
        }
    }
    
}