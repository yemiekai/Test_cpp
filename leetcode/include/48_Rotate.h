#ifndef _48_ROTATE_H
#define _48_ROTATE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <string.h>  // memset的头文件
#include <algorithm>
#include <vector>
#include <map>
#include <set>

// 48  旋转图像
/******************************************************************
 *   1  2  3        7  4  1      5  1  9  11        15 13  2  5
 *   4  5  6   ->   8  5  2      2  4  8  10   ->   14  3  4  1  
 *   7  8  9        9  6  3      13 3  6  7         12  6  8  9
 *                               15 14 12 16        16  7  10 11
 * 
 *******************************************************************/
class Solution48{

public:
    void rotate(std::vector<std::vector<int> > &matrix);


    void test();

};

#endif