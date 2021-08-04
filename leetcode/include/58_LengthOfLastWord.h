#ifndef _58_LENGTH_OF_LAST_WORD_H
#define _58_LENGTH_OF_LAST_WORD_H

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

// 57  插入区间
/*******************************************************************************************
给你一个字符串 s，由若干单词组成，单词之间用单个或多个连续的空格字符隔开。
返回字符串中最后一个单词的长度。如果不存在最后一个单词，请返回 0 。

[单词]是指仅由字母组成、不包含任何空格字符的最大子字符串。


输入：s = "Hello World"
输出：5
-------------------------------------------------------------------------------------------
输入：s = " "
输出：0
*********************************************************************************************/
class Solution58{

public:
    int lengthOfLastWord(std::string s);
    
    void test();

};

#endif