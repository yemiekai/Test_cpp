#include "include/27_RemoveElement.h"
#include "math.h"
#include <algorithm>
#include <queue>


int Solution27::removeElement(std::vector<int>& nums, int val){
    int i = 0;
    for(int j = 0; j<nums.size(); j++){
        if(nums[j] != val){
            nums[i] = nums[j];
            i++;
        }
    }

}
