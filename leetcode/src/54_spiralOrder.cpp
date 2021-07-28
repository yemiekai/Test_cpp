#include "54_spiralOrder.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>


/***********************************************************
 * 54   螺旋矩阵
********************************************************************/

std::vector<int> Solution54::spiralOrder(std::vector<std::vector<int>>& matrix){
    int totalRows = matrix.size();
    int totalCols = matrix[0].size();
    std::vector<int> result;
    std::vector<std::vector<int> > trace(totalRows*totalCols, std::vector<int>(totalCols, 0));

    int direct[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};  // {行, 列}
    int nowDirect = 0;
    
    int total = 0; // 走过几个格子了
    int turn = 0; // 转弯次数
    int col = 0;  // 当前所处列
    int row = 0;  // 当前所处行
    int tmpCol = 0; 
    int tmpRow = 0;

    while(total < totalRows*totalCols){
        result.push_back(matrix[row][col]);  // 记录当前位置结果
        trace[row][col] = 1;  // 记录走过的位置
        total++;  // 总步数
        nowDirect = turn % 4; // 当前方向

        // 试探下一步将要走到哪
        tmpRow = row + direct[nowDirect][0];
        tmpCol = col + direct[nowDirect][1];
        
        // 越界或者遇到已经走过的
        if(tmpRow < 0 || tmpRow >= totalRows || tmpCol < 0 || tmpCol >= totalCols || trace[tmpRow][tmpCol] == 1 ){
            turn++;  // 该掉头了
            nowDirect = turn % 4; // 当前方向
        }

        // 更新位置
        row += direct[nowDirect][0];
        col += direct[nowDirect][1];

    }

    return result;
}


void Solution54::test(){
    int inputData[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    std::vector<std::vector<int> > intputMatrix;
    std::vector<int> result;

    for(int i = 0; i <3; i++){
        std::vector<int> row;
        for(int j = 0; j < 3; j++){
            row.push_back(inputData[i][j]);
        }
        intputMatrix.push_back(row);
    }

    result = spiralOrder(intputMatrix);

    for(int item : result){
        std::cout << item << std::endl;
    }
}

