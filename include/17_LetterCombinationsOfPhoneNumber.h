#ifndef _17_LETTER_COMBINATIONS_OF_PHONE_NUMBER_H_
#define _17_LETTER_COMBINATIONS_OF_PHONE_NUMBER_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>

#include <vector>
#include <map>
#include <set>

// 17. 电话号码的字母组合
class Solution17 {
public:
    std::string tmp;
    std::vector<std::string> res;
    std::vector<std::string> board={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


    /******************************************
     * digits是输入的一串数字, 如"235"
     * pos是当前遍历到第几个数字
     * board是数字对应的字符集, 如数字'2'对应了"abc"
     ******************************************/ 
    void DFS(int pos, std::string digits){
        if(pos == digits.size()){
            res.push_back(tmp);
            return;
        }
        int num = digits[pos]-'0';
        for(int i=0; i<board[num].size(); i++){
            tmp.push_back(board[num][i]);
            DFS(pos+1, digits);
            tmp.pop_back();
        }
    }

    std::vector<std::string> letterCombinations(std::string digits){
        if(digits.size()==0) return res;
        DFS(0,digits);
        return res;
    }

    void test();

};


#endif