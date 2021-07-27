#include "53_MaxSubArray.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>


/***********************************************************
 * 53   最大子序和
********************************************************************/

/******************************************************************
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

 *******************************************************************/


int Solution53::maxSubArray(std::vector<int>& nums){
    int max = 0;
    int result = nums[0];
    int leng = nums.size();

    /******************************************************
     * 假设当前走到了 i , max表示 i 之前累积的最大和
     * 
     * 如果当前的数字 nums[i] 加上之前的和(max), 比 nums[i]还小, 
     * 证明前面的是个累赘, 对增大'总和'毫无帮助, 
     * 把它抛弃掉, 记最大的为 nums[i], 开启新一轮计数
     ******************************************************/
    for(int i=0; i<leng; i++){
        max = std::max(max + nums[i], nums[i]);
        result = std::max(max, result);
    }

    return result;
}

/**************
 * 
 * 其它解释：
 * 
动态规划的是首先对数组进行遍历, 当前最大连续子序列和为 sum, 结果为 ans
* 如果 sum > 0, 则说明 sum 对结果有增益效果, 则 sum 保留并加上当前遍历数字
* 如果 sum <= 0, 则说明 sum 对结果无增益效果, 需要舍弃, 则 sum 直接更新为当前遍历数字
* 每次比较 sum 和 ans 的大小, 将最大值置为ans, 遍历结束返回结果
* 时间复杂度：O(n)

作者：guanpengchn
链接：https://leetcode-cn.com/problems/maximum-subarray/solution/hua-jie-suan-fa-53-zui-da-zi-xu-he-by-guanpengchn/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 * ******************/