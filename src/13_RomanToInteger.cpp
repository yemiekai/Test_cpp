#include "include/13_RomanToInteger.h"
#include "math.h"

/*******************************************
 * 
 * 13. 罗马转整数
 * 
 ********************************************/
int Solution13::romanToInt(std::string s){
    int len = s.size();
    std::map<char, int> mp = {
        {'M',1000},
        {'D',500},
        {'C',100},
        {'L',50},
        {'X',10},
        {'V',5},
        {'I',1}
        };
        
    int result = 0;
    for(int i=0; i<len; i++){
        if( i < len-1 && mp[s[i]] < mp[s[i+1]]){
            result -= mp[s[i]];
        }else{
            result += mp[s[i]];
        }

    }
}




void Solution13::test(){
    

}
