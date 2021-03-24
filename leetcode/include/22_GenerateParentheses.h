#ifndef _22_GENERATE_PARENTHESES_H_
#define _22_GENERATE_PARENTHESES_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>

#include <vector>
#include <map>
#include <set>


// 22. 括号生成
/*
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 */
class Solution22 {
public:
    std::vector<std::string> result;
    std::string tmp;
    int num;
    void DFS(std::string s, int left, int right){
        if(s.length() == 2*num){
            result.push_back(s);
            return;
        }

        if(left < num){
            DFS(s+"(", left+1, right);
        }
        if(right < left){
            DFS(s+")", left, right+1);
        }


    };

    std::vector<std::string> generateParenthesis(int n){
        num = n;
        DFS("", 0, 0);
    };

    void test();

};

#endif