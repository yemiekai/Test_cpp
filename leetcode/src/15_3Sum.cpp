#include "15_3Sum.h"
#include "math.h"
#include <algorithm>
/*******************************************
 * 
 * 15. 三数之和
 * 
 ********************************************/
std::vector<std::vector<int>> Solution15::threeSum(std::vector<int>& nums){
    std::vector<std::vector<int>> res;
    int leng = nums.size();

    std::sort(nums.begin(), nums.end());

    // 确定第1个数, 开始遍历
    for(int first = 0; first<leng; first++){
        // 跳过重复的
        if(first > 0 && nums[first] == nums[first-1]){
            continue;
        }
        
        int third = leng-1;

        // 确定第2个数, 开始遍历
        for(int second = first+1; second<leng; second++){
            // 跳过重复的
            if(second>first+1 && nums[second] == nums[second-1]){
                continue;
            }

            // 找符合条件的
            while(second<third && nums[first]+nums[second]+nums[third]>0){
                third--;
            }

            if(second==third){
                break;
            }

            if(nums[first]+nums[second]+nums[third] == 0){
                res.push_back( {nums[first],nums[second],nums[third]} );
            }
        }
    }

    return res;
}




void Solution15::test(){
    

}
