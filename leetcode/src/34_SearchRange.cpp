#include "34_SearchRange.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>

/***********************************************************
 * 34 在排序数组中查找元素的第一个和最后一个位置
 ************************************************************/ 

// 二分法查找的实现
int Solution34::binarySearch(std::vector<int>& nums, int target, bool lower){
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    int result;

    while(left <= right){
        mid = (left + right) / 2;
        
        // 只有收缩右边界的时候, 才记一次结果, 因此结果一定比target刚好大(lower未开启的时候)
        if(target < nums[mid] || (lower && target <= nums[mid])){
            right = mid - 1;  // 收缩右边界
            result = mid;
        }else{
            left = mid + 1;  // 目标比中间数大, 收缩左边界
        }

    }


}



std::vector<int> Solution34::searchRange(std::vector<int>& nums, int target){
    int leftIdx = this->binarySearch(nums, target, true);
    int rightIdx = this->binarySearch(nums, target, false) - 1;

    if(leftIdx <= rightIdx 
       && rightIdx < nums.size()
       && nums[leftIdx] == nums[rightIdx]
       && nums[rightIdx] == target){

           return std::vector<int>{leftIdx, rightIdx};
       }

    return std::vector<int>{-1, -1};
    
}