#include "44_IsMatch.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>


/***********************************************************
 * 44  通配符匹配
 * 
========================================================================

输入:
s = "adceb"
p = "*a*b"

输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".

========================================================================
输入:
s = "acdcb"
p = "a*c?b"

输出: false

************************************************************/ 

bool Solution44::isMatch(std::string s, std::string p){
    int sLeng = s.size();  // i
    int pLeng = p.size();  // j
    
    std::vector<std::vector<bool> > dp(sLeng, std::vector<bool>(pLeng, false));
    
    // 先设置边界条件
    dp[0][0] = true;

    // 第一列：空模式无法匹配任何字符串
    for(int i=1; i<sLeng; i++){
        dp[i][0] = false;  
    }

    // 第一行：星号才能匹配空字符串
    for(int j=1; j<pLeng; j++){
        dp[0][j] = (p[j]=='*' && dp[0][j-1]) ? true : false;  
    }

    for(int i=1; i<sLeng; i++){
        for(int j=1; j<pLeng; j++){
            if(p[j] == '*'){
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
            }else if(p[j] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }else if(s[i] == s[j]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = false;
            }
        }
    }

    if(dp[sLeng-1][pLeng-1]){
        return true;
    }

    return false;

}




void Solution44::test(){

    isMatch("123", "12345");
    
}
