#include "6_ZConvert.h"


/*******************************************
 * 
 * Z形变换
 * 
 ********************************************/ 
std::string Solution6::zConvert(std::string s, int numRows){
    std::vector<std::string> st(numRows);
    int total = s.size();
    int nowIdx = 0;
    int direction = -1;  // 1是向下, 0是向上
    
    if(numRows == 1){
        return s;
    }

    for(char c : s){
        if(nowIdx % (numRows-1) == 0){
            direction = 0 - direction;
        }

        st[nowIdx] += c;
        nowIdx += direction;
    }

    std::string result;
    for(std::string s : st){
        result += s;
    }

    return result;
    
}




void Solution6::test(){
    std::string ts("abcdefghijk");
    std::string result;
    

    result = zConvert(ts, 3);
    std::cout << result << std::endl;
}