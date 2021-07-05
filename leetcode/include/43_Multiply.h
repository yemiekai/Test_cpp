#ifndef _43_MULTIPLY_H
#define _43_MULTIPLY_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <string.h>  // memset的头文件
#include <algorithm>
#include <vector>
#include <map>
#include <set>

// 43 字符串相乘
class Solution43 {

public:
    std::string addString(std::string s1, std::string s2);
    std::string multiply(std::string num1, std::string num2);

    void test();

};

#endif