#include "52_SolveNQueens2.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>


/***********************************************************
 * 52  n皇后问题2
********************************************************************/

/******************************************************************


 *******************************************************************/
// std::vector<std::vector<std::string>> Solution51::solveNQueens(int n){



//     return n%2 == 0 ? y*y : y*y*x;
// }



int Solution52::totalNQueens(int n){
    result = 0;
    colums = std::unordered_set<int>();
    d1 = std::unordered_set<int>();
    d2 = std::unordered_set<int>();
    queens = std::vector<int>(n, -1);



}