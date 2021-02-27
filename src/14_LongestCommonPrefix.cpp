#include "include/14_LongestCommonPrefix.h"
#include "math.h"
#include <algorithm>
/*******************************************
 * 
 * 14. 最长公共前缀
 * 
 ********************************************/
std::string Solution14::longestCommonPrefix(std::vector<std::string>& strs){
    std::string res = strs[0];
    
    for(std::string s : strs){
        res = getTowPrefix(res, s);
        if(res.length() == 0){
            break;
        }

    }

    return res;
   
}

/******************************************************
 * 帮助函数
 * 获取2个字符串的最长公共前缀
 ******************************************************/
std::string Solution14::getTowPrefix(std::string s1, std::string s2){
    int size = std::min(s1.size(), s2.size());
    int index = 0;
    while(index<size && s1[index]==s2[index]){
        index++;
    }

    return s1.substr(0, index);
}


void Solution14::test(){
    

}
