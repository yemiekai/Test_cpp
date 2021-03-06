#include "31_NextPermutation.h"
#include "math.h"
#include <algorithm>
#include <queue>

/***********************************************************
 * 31 下一个排列
 * https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode-solution/
 * 
 * 更大的数是这个意思:
 *  1234
 *  1243
 *  1324
 *  1342
 *  1423
 *  1432
 *  2134
 *  2143
 *  2314
 *  2341
 *  2413
 *  2431
 *  3124
 *  3142
 *  3214
 *  3241
 *  3412
 *  3421
 *  4123
 *  4132
 *  4213
 *  4231
 *  4312
 *  4321
 * 它们一个比一个大
 * 
 * 现在要对这样的数  找下一个更大的数:
 * 
 * [0] [1] [2] [3] [4] [5] [6] [7] [8]  ---  (索引)
 *  1   5   8   4   7   6   5   3   1   ---  (数值)
 * 
 * 先找到第一个升序的位置, 这里是索引[3]和[4], 对应数字4和7
 * 由于此时后面都是降序的, 所以从后往前遍历第一个比索引[3]大的数, 这个一定是刚好比它大一点点的数, 这个数是索引[6]
 *
 * 然后交换索引[3]和索引[6]:
 * 
 * [0] [1] [2] [3] [4] [5] [6] [7] [8]
 *  1   5   8   5   7   6   4   3   1
 * 
 * 再对索引[3]后面做反转(因为后面还是倒叙的)
 * 
 * [0] [1] [2] [3] [4] [5] [6] [7] [8]
 *  1   5   8   5   1   3   4   6   7
 * 
 * 这个数就是下一个比它大的数
 ************************************************************/ 
void Solution31::nextPermutation(std::vector<int>& nums){
    int i = nums.size() - 2;

    // 从尾到头, 找出第一组升序的位置, 这个位置是[i]
    while(i >=0 && nums[i]>=nums[i+1]){
        i--;
    }

    if(i>=0){
        int j = nums.size() - 1;

        // 从尾到头, 找到比位置[i]大的数, 这个位置是[j]
        while(j>=0 && nums[i]>=nums[j]){
            j--;
        }

        // 交换这两个数
        std::swap(nums[i], nums[j]);
    }

    // 对[i]以后的数排序(升序)
    std::reverse(nums.begin()+i+1, nums.end());
}