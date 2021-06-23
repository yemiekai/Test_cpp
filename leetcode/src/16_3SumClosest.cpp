#include "16_3SumClosest.h"
#include "math.h"
#include <algorithm>

int distance(int a, int b){
    return abs(a-b);
}


/*******************************************
 * 
 * 16. 最接近的三数之和
 * 
 ********************************************/
int Solution16::threeSumClosest(std::vector<int>& nums, int target){
    std::vector<std::vector<int>> res;
    int leng = nums.size();
    std::sort(nums.begin(), nums.end());
    int closest = 10e7;
    int tmp;

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
            while(second<third){
                tmp = distance(nums[first]+nums[second]+nums[third], target);
                if(tmp == 0){
                    return 0;
                }else if(tmp >= closest){
                    third--;
                }else if(tmp < closest){
                    third--;
                    closest = tmp;
                }
            }

            if(second>=third){
                break;
            }

        }
    }

    return closest;
}




void Solution16::test(){
    

}
