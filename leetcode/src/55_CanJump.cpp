#include "55_CanJump.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>


/***********************************************************
 * 55  跳跃游戏
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

