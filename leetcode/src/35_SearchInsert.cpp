#include "35_SearchInsert.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>

/***********************************************************
 * 35 搜索插入位置
 ************************************************************/ 

// 
int Solution35::searchInsert(std::vector<int>& nums, int target){
    int i=0;
    for(i=0; i<nums.size(); i++){
        if(nums[i]==target || nums[i]>target){
            break;
        }
    }

    return i;
}

// 用二分法来做
static int searchInsert(std::vector<int>& nums, int target){
    int left = 0;
    int right = nums.size() - 1;

    int mid = (left + right) / 2;

    while(left<right){
        if(nums[mid] == target){
            break;
        }
        else if(nums[mid] < target){
            mid = (mid+right) / 2;
        }else{
            mid = (left+mid) / 2;
        }
    }

    return mid;
}