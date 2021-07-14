#include "45_jump.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>


/***********************************************************
 * 45 跳跃游戏II
 * 
 * 贪心算法
 ************************************************************/ 

int Solution45::jump(std::vector<int>& nums){
    int maxPos = 0;
    int end = 0;
    int step = 0; // 走了几步

    for(int now=0; now<nums.size(); now++){

        // 在now这个地方, 能跳的最远位置
        maxPos = std::max(maxPos, now+nums[now]);

        // 到达本次的最远位置了
        if(now == end){
            end = maxPos;  // 更新下轮循环的边界
            step++;  // 跳一步, 进入下轮循环
        }
    }

   
    return step;
}




void Solution45::test(){

}
