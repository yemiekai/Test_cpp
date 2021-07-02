#include "42_Trap.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>

/***********************************************************
 * 42 接雨水
 * 
 * 核心: 找到每个坑属于哪个‘桶’, 桶有2个边界, 找到最小边界, 就知道能盛多少水
 * 
 ************************************************************/ 
int Solution42::Trap(std::vector<int> &height){
    int n = height.size();

    // 从左往右走, --> , 每个位置的值为, 到目前为止的最大值
    std::vector<int> leftMax;
    leftMax[0] = height[0];
    for(int i=1; i<n; i++){
        leftMax[i] = std::max(leftMax[i-1], height[i]);
    }

    // 从右往左走, <-- , 每个位置的值为, 到目前为止的最大值
    std::vector<int> rightMax;
    rightMax[n-1] = height[n-1];
    for(int i = n-2; i>0; i--){
        rightMax[i] = std::max(height[i], rightMax[i+1]);
    }

    // 现在左右最大值都有了, 也就是有了 ‘凹槽’ 的 ‘边界’
    // 每个 ‘凹槽’ 能装多少水, 取决于最小 ‘边界’
    int result = 0;
    for(int i=0; i<n; i++){
        int board = std::min(rightMax[i], leftMax[i]);  // 这个是凹槽的边界
        result += (board - height[i]);
    }
   
    return n+1;

}

