#ifndef _49_GROUP_ANAGRAMS_H
#define _49_GROUP_ANAGRAMS_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <string.h>  // memset的头文件
#include <algorithm>
#include <vector>
#include <map>
#include <set>

// 49  字母异位词分组
/******************************************************************
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

输入: strs = ["a"]
输出: [["a"]]
 *******************************************************************/
class Solution49{

public:
    std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs);


    void test();

};

#endif