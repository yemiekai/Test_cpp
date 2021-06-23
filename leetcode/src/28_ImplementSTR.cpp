#include "28_ImplementSTR.h"
#include "math.h"
#include <algorithm>
#include <queue>

/***************************************************************************
 * 从haystack的start位置开始, 和needle逐个比较
 * 如果完全一致, 返回true, 不相同或者长度不够, 返回false
 * 
 * 例如: 
 *             [0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] [13] [14]
 * haystack:    a   s   d   f   g   4   5   6   f   g   h    a    f    3    2
 * needle:                                      f   g   h    a
 * start:       8
 * 
 * 从haystack的第8个索引开始比较
 ****************************************************************************/
bool compare(const std::string &haystack, const std::string &needle, int start){
    int hayLength = haystack.length();
    int compareLength = needle.length();

    if(start + compareLength < haystack.length()){
        return false;
    }

    for(int i = 0; i < compareLength; i++){
        if(haystack[start+i] == needle[i]){
            continue;
        }else{
            return false;
        }
    }

    return true;
}

int Solution28::strStr(std::string haystack, std::string needle){
    
    int location = 0;

    while(location < haystack.length()){
        if(compare(haystack, needle, location)){
            return location;
        }
        location++;
    }

    return -1;

}
