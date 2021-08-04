#include "58_LengthOfLastWord.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>

// 58 最后一个单词的长度
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
int Solution58::lengthOfLastWord(std::string s){
    int length = 0;
    int lastLen = 0;

    // 从头开始遍历
    for(char c : s){
        if(c == ' '){
            length = 0;  // 遇到空格就重新计数
        }else{
            length++;
            lastLen = length;  // lastLen就能保持和"最近一次空格前"的字符串长度一样
        }
    }

    return lastLen;
}


void Solution58::test(){


}

