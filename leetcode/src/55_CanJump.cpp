#include "55_CanJump.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>


/***********************************************************
 * 55  跳跃游戏
 * 
========================================================================================================
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步,从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。

========================================================================================================

输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样, 总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0, 所以永远不可能到达最后一个下标
========================================================================================================

********************************************************************/

bool Solution55::canJump(std::vector<int>& nums){
    int leng = nums.size();
    int maxPosition = 0;

    for(int now = 0; now < leng; now++){
        if(now > maxPosition){
            return false;  // 最远只能跳到max, 而i已经超过max了
        }

        maxPosition = std::max(maxPosition, now + nums[now]);
        if(maxPosition >= leng){
            return true;
        }
    }

    return true;  // 当nums为0时, 直接返回true
}


void Solution55::test(){


}

