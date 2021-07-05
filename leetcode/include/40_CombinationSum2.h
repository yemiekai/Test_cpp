#ifndef _40_COMBINATION_SUM2_H
#define _40_COMBINATION_SUM2_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <string.h>  // memset的头文件
#include <algorithm>
#include <vector>
#include <map>
#include <set>

// 40 数组总和2
class Solution40 {

public:
    /**************************************************
     * 
     * 1. nowIdx : 每次递归都从当前索引开始, 往后遍历; 前面的不管了, 避免重复.
     * 
     * 2. res: 距离目标值target还差多少; 用于判断递归结束条件
     * 
     **************************************************/
    std::vector<std::vector<int> > result;
    std::vector<int> tmp;

    /**************************************************
     * 1. nowIdx : 每次递归都从当前索引开始, 往后遍历; 前面的不管了, 避免重复.
     * 2. res: 距离目标值target还差多少; 用于判断递归结束条件
     **************************************************/
    void trackBack(std::vector<int>& candidates, int nowIdx, int res){
        if(res == 0){
            // 由于不能有重复的组合, 所以排序一下再加入
            std::vector<int> tmptmp(tmp.begin(), tmp.end());
            std::sort(tmptmp.begin(), tmptmp.end());
            if(std::find(result.begin(), result.end(), tmptmp) == result.end()){
                result.push_back(tmptmp);
            }
            return;
        }else if(res < 0){
            return;
        }
        
        for(int i=nowIdx; i<candidates.size(); i++){
            tmp.push_back(candidates[i]);
            trackBack(candidates, i+1, res-candidates[i]);
            tmp.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        trackBack(candidates, 0, target);
        return result;
    }

    void test();

};

#endif