#ifndef _34_SEARCH_RANGE_H
#define _34_SEARCH_RANGE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>

#include <vector>
#include <map>
#include <set>

// 34 在排序数组中查找元素的第一个和最后一个位置
class Solution34 {
public:
    int binarySearch(std::vector<int>& nums, int target, bool lower);
   
    std::vector<int> searchRange(std::vector<int>& nums, int target);
    
    void test();

};

#endif