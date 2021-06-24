#include "33_SearchRotate.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>

/***********************************************************
 * 33 搜索旋转数组
 ************************************************************/ 
int Solution33::search(std::vector<int>& nums, int target){
    int n = (int)nums.size();
    if (!n) {
        return -1;
    }
    if (n == 1) {
        return nums[0] == target ? 0 : -1;
    }
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target){
            return mid;
        } 

        // 先判断是否落在左边有序空间
        if (nums[0] <= nums[mid]) {
            // 正好处于左边有序空间
            if (nums[0] <= target && target < nums[mid]) {
                r = mid - 1;  // 收缩右边界
            } else {
                l = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[n - 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;


}