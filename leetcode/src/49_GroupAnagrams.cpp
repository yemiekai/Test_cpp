#include "49_GroupAnagrams.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>


/***********************************************************
 * 49  字母异位词分组

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

输入: strs = ["a"]
输出: [["a"]]

********************************************************************/

std::vector<std::vector<std::string> > Solution49::groupAnagrams(std::vector<std::string>& strs){
    std::unordered_map<std::string, std::vector<std::string>> mmp;

    for(std::string st : strs){
        std::string tag(st);
        std::sort(tag.begin(), tag.end());  // 排序
        mmp[tag].push_back(st);  // 排序完的字符串作为键值
    }

    std::vector<std::vector<std::string> > result;
    for(auto it : mmp){
        result.push_back(it.second);
    }

    return result;

}