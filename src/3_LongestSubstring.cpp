#include "include/3_LongestSubstring.h"


int Solution3::lengthOfLongestSubstring(std::string s){
    std::set<char> mSet;
    int strLength = s.size();  // 输入字符串长度

    int nowLength;  // set当前长度
    int lastLength;  // set上一次长度
    int nowIndex = 0;
    int headIndex = 0;
    int result;
    char nowChar;

    while(nowIndex < strLength && headIndex <= nowIndex){
        nowChar = s[nowIndex];
        lastLength = mSet.size();
        mSet.insert(nowChar);  // 添加到集合
        nowLength = mSet.size();

        // 长度没变, 说明是重复, 把头踢掉, 再来
        if(nowLength == lastLength){
            mSet.erase(mSet.find(s[headIndex]));
            headIndex++;
        }else{
            result = std::max(nowLength, result);
            nowIndex++;
        }

    }

    return result;
}


void Solution3::test(){
    std::string s = std::string("abcabcbb");

    int result = lengthOfLongestSubstring(s);
    std::cout << result << std::endl;
}