#ifndef _10_REGULAR_EXPRESSION_MATCHING_H_
#define _10_REGULAR_EXPRESSION_MATCHING_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>

#include <vector>
#include <map>
#include <set>

// 10. 正则表达式匹配
class Solution10 {
public:
    void test();
    bool bMatch(int i, int j);
    bool isMatch(std::string s, std::string p);
private:
    std::string m_s;
    std::string m_p;

};

#endif