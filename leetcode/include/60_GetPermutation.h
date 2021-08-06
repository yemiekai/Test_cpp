#ifndef _60_GET_PERMUTATION_H
#define _60_GET_PERMUTATION_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <string.h>  // memset的头文件
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>

// 60 排列序列
/*******************************************************************************************
给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

====================================================================
我是用暴力法得到所有的组合, 然后返回第k个, 但是很慢, 看答案说可以直接算出第k个:

【数学的方法】
总共的排列有 n! 个
其中：
1开头的排列有 (n-1)! 个
2开头的排列也有 (n-1)! 个
....
n开头的排列有 (n-1)! 个

所以题目要求返回第k个, 就能算出是'几'开头, 减少计算量
剩下的继续这样算: 有 (n-2)! 个 ...

*********************************************************************************************/
class Solution60{

public:
    std::string tmp = "";
    std::vector<std::string> result;
    std::vector<int> bUsed;

    void dfs(int n){
        if(tmp.length() >= n){
            result.push_back(tmp);
            return;
        }

        for(int i = 0; i<n; i++){
            if(bUsed[i] == 1){
                continue;
            }

            bUsed[i] = 1;
            tmp.push_back('1'+i);
            dfs(n);
            tmp.pop_back();
            bUsed[i] = 0;
        }
    }

    std::string getPermutation(int n, int k){
        bUsed = std::vector<int>(n, 0);
        dfs(n);
        // std::sort(result.begin(), result.end());  // 都不用排序了, 直接就是这个结果

        return result[k-1];

    };
    
    void test();

};

#endif