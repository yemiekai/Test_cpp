#include "11_ContainerWithMostWater.h"
#include "math.h"

/*******************************************
 * 
 * 11. 盛水最多的容器
 * 
 ********************************************/ 
int Solution11::maxArea(std::vector<int>& height){
    int l = 0;
    int r = height.size() - 1;
    int ans = 0;
    while (l < r) {
        int area = std::min(height[l], height[r]) * (r - l);
        ans = std::max(ans, area);
        if (height[l] <= height[r]) {
            ++l;
        }
        else {
            --r;
        }
    }
    return ans;

}




void Solution11::test(){
    

}