#include "36_ValidSudoku.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>

/***********************************************************
 * 36  有效的数独
 ************************************************************/ 

// 
bool Solution36::isValidSudoku(std::vector<std::vector<char>>& board){
        bool result;

        // 9行, 每1行有9个标志位, 分别代表1,2,3,4,5,6,7,8,9标志位置1时, 代表该数字填入了
        std::vector<std::vector<int> > eachRow(9, std::vector<int>(9, 0));  
        std::vector<std::vector<int> > eachCol(9, std::vector<int>(9, 0));  
        std::vector<std::vector<int> > eachGrid(9, std::vector<int>(9, 0));

        for(int i=0; i<9; i++){  // 第i行
            for(int j=0; j<9; j++){  // 第j列

                if(board[i][j] == '.'){
                    continue;
                }

                int number = board[i][j] - '0';  // 当前位置的数字

                int gridNum = 3 * (int)(i/3) + j/3;  // 当前位置落在第几个格子
                
                // 检查这个数字是否已经存在
                if(eachRow[i][number-1] == 0){
                    eachRow[i][number-1] = 1;
                }else{
                    return false;
                }
                
                if(eachCol[j][number-1] == 0){
                    eachCol[j][number-1] = 1;
                }else{
                    return false;
                }

                if(eachGrid[gridNum][number-1] == 0){
                    eachGrid[gridNum][number-1] = 1;
                }else{
                    return false;
                }
            }
        }

        return true;

}


void Solution36::test(){
}