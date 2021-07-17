#ifndef _46_PERMUTE_H
#define _46_PERMUTE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <string.h>  // memset的头文件
#include <algorithm>
#include <vector>
#include <map>
#include <set>

// 46  全排列
/******************************************************************
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *******************************************************************/
class Solution46{

public:
    std::vector<std::vector<int>> result;
    std::vector<int> tmp;
    std::vector<bool> used;
    int leng;

    void dfs(const std::vector<int>& input, int nowPos){
        if(tmp.size()==leng){
            result.push_back(tmp);
            return;
        }
        if(nowPos>=leng){
            return;
        }

        for(int i = nowPos; i < leng; i++){
            if(used[i]){
                continue;  // 用过的数字跳过
            }

            tmp.push_back(input[i]);
            used[i] = true;

            dfs(input, nowPos);

            tmp.pop_back();
            used[i] = false;
        }

    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums){
        this->leng = nums.size();
        this->used = std::vector<bool>(this->leng, false);
        dfs(nums, 0);

        return result;
    };

    void test();

};

#endif