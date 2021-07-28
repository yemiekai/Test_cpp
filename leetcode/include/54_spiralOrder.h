#ifndef _54_SPIRAL_ORDER_H
#define _54_SPIRAL_ORDER_H

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

// 54  螺旋矩阵
/*****************************************************************


*******************************************************************/
class Solution54{

public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix);
    
    void test();

};

#endif