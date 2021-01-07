#include "include/1_TowSum.h"



std::vector<int> Solution1::twoSum(std::vector<int>& nums, int target){
    std::map<int, int> mmap;
    std::vector<int> result;

    int size = nums.size();
    int matchNum;

    // 遍历数组
    for(int i = 0; i < size; i++){
        matchNum = target - nums[i];  // 你要找到数

        // 看看有没有
        if(mmap.find(matchNum) != mmap.end()){
            return std::vector<int>{mmap[matchNum], i};  // 返回索引
        }

        mmap[nums[i]] = i;  // 索引存起来, 继续下一轮寻找
    }

    return result;
}


void Solution1::test(){
    std::vector<int> nums {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result;

    result = this->twoSum(nums, target);

    std::cout << "result :" << std::endl;
    
    for(auto it : result){
        std::cout << it << std::endl;
    }


}