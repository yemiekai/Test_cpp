#include "include/1_TowSum.h"



std::vector<int> Solution1::twoSum(std::vector<int>& nums, int target){
    std::map<int, int> mmap;
    std::vector<int> result;
    int tmp;

    for(int n : nums){
        std::cout << n << std::endl;

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