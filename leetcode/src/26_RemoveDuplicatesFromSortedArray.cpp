#include "include/26_RemoveDuplicatesFromSortedArray.h"
#include "math.h"
#include <algorithm>
#include <queue>


int Solution26::removeDuplicates(std::vector<int>& nums){
    int i = 0;
    for(int j = 1; j<nums.size(); j++){
        if(nums[j] != nums[i]){
            i++;
            nums[i] = nums[j];
        }
    }

}
