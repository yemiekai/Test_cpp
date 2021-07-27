#ifndef _53_MAX_SUB_ARRAY_H
#define _53_MAX_SUB_ARRAY_H

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

// 53  最大子序和
/*****************************************************************
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

*******************************************************************/
class Solution53{

public:
    int maxSubArray(std::vector<int>& nums);
    int totalNQueens(int n);
    void test();

};

#endif