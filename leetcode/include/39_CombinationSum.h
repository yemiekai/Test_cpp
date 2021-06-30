#ifndef _39_COMBINATION_SUM_H
#define _39_COMBINATION_SUM_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <string.h>  // memset的头文件

#include <vector>
#include <map>
#include <set>

// 39 数组总和
class Solution39 {

public:
    std::vector<std::vector<int> > result;
    std::vector<int> tmp;

    /**************************************************
     * 
     * 1. nowIdx : 每次递归都从当前索引开始, 往后遍历; 前面的不管了, 避免重复.
     * 
     * 2. res: 距离目标值target还差多少; 用于判断递归结束条件
     * 
     **************************************************/
    void trackBack(std::vector<int>& candidates, int nowIdx, int res){
        if(res == 0){
            result.push_back(tmp);
            return;
        }else if(res < 0){
            return;
        }
        
        for(int i=nowIdx; i<candidates.size(); i++){
            tmp.push_back(candidates[i]);
            trackBack(candidates, i, res-candidates[i]);
            tmp.pop_back();
        }

    }
    
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    
        trackBack(candidates, 0, target);

        return result;
    }

    void test();

};

#endif