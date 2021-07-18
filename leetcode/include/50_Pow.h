#ifndef _50_POW_H
#define _50_POW_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <string.h>  // memset的头文件
#include <algorithm>
#include <vector>
#include <map>
#include <set>

// 50  计算 x 的 n 次幂函数
/******************************************************************
输入：x = 2.00000, n = 10
输出：1024.00000

----------------------------------------------

输入：x = 2.10000, n = 3
输出：9.26100

----------------------------------------------

输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
 *******************************************************************/
class Solution50{

public:
    double myPow(double x, int n);
    double dfs(double x, int n);

    void test();

};

#endif