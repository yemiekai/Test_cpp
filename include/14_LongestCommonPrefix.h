#ifndef _14_LONGEST_COMMON_PREFIX_H_
#define _14_LONGEST_COMMON_PREFIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>

#include <vector>
#include <map>
#include <set>

// 14. 最长公共前缀
class Solution14 {
public:
    void test();
    std::string longestCommonPrefix(std::vector<std::string>& strs);
    std::string getTowPrefix(std::string s1, std::string s2);

};

#endif