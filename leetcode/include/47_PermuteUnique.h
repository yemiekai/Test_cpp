#ifndef _47_PERMUTE_UNIQUE_H
#define _47_PERMUTE_UNIQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <string.h>  // memset的头文件
#include <algorithm>
#include <vector>
#include <map>
#include <set>

// 47  全排列II
/******************************************************************
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *******************************************************************/
class Solution47{

public:
    std::vector<int> inputNums;
    int length;

    std::vector<std::vector<int>> result;
    std::vector<int> tmp;
    std::vector<bool> used;  // 当前索引上的数字是否用过

    void dfs(int nowPos){
        // 长度到了, 判断要不要加进result
        if(nowPos >= this->length || tmp.size() >= this->length){
            if(std::find(result.begin(), result.end(), tmp) == result.end()){
                result.push_back(tmp);  // 未存在, 则加进去
            }

            return;
        }

        for(int i = nowPos; i<this->length; i++){
            if(false == used[i]){
                tmp.push_back(this->inputNums[i]);
                used[i] = true;  // 用了这个索引的数, 设置标志位

                dfs(nowPos);  // 进入递归

                tmp.pop_back();
                used[i] = false;
            }
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums){
        this->inputNums = nums;
        this->length = nums.size();
        this->used = std::vector<bool>(this->length, false);

        dfs(0);

        return result;
    };

    void test();

};

#endif