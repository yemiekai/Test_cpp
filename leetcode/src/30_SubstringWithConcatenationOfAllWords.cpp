#include "30_SubstringWithConcatenationOfAllWords.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <unordered_map>

std::vector<int> Solution30::findSubstring(std::string s, std::vector<std::string>& words)
{
    std::vector<int> result;
    
    int wordNums = words.size();  // 有几个单词
    int wordLen = words[0].size();  // 每个单词多长
    int strLen = s.size();  // 给定字符串的长度

    for(int i=0; i<wordLen && (i + wordNums*wordLen)<=strLen; ++i)
    {
        std::unordered_map<std::string, int> differ;

        // 建立初始窗口, 并且用哈希表记录出现的单词次数
        for(int j=0; j<wordNums; j++)
        {
            ++differ[s.substr(i+j*wordLen, wordLen)];
        }

        // 遍历给定的单词表, 更新哈希表中的单词次数
        for(std::string &word : words)
        {
            if(--differ[word] == 0){
                differ.erase(word);
            }
        }

        // 开始滑动窗口
        for(int start=i; start<strLen-wordNums*wordLen+1; start+=wordLen)
        {
            if(start != i)
            {
                std::string word = s.substr(start + (wordNums-1)*wordLen, wordLen);  // 窗口右边的单词
                if(++differ[word] == 0){
                    differ.erase(word);
                }

                word = s.substr(start - wordLen, wordLen);  // 窗口左边的单词
                if(--differ[word] == 0){
                    differ.erase(word);
                }
            }
            
            if(differ.empty()){
                result.emplace_back(start);
            }
        }

    }

    return result;
}

void Solution30::test(){

}
