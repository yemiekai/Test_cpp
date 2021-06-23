#include "5_LongestPalindrome.h"
#include "utils.h"


/*******************************************
 * 
 * 最长回文
 * 
 ********************************************/ 
std::string Solution5::longestPalindrome(std::string s){
    int size = s.size();
    std::vector<std::vector<int>> pd(size, std::vector<int>(size));  // 1表示是回文, 0表示不是回文
    std::string result;
    
    //pd[l][r] == 1 表示 s[l] ~ s[r]之间是回文
    // 动态规划要求先规划到范围小的, 往大扩张, 所以要注意规划顺序
    for(int r=1; r<size; r++){
        for(int l=r; l>=0; l--){
            if(r-l<=2 && s[l]==s[r]){  // 间隔2个数的情况: a, aa, aba都是回文, 都满足s[l]=s[r]
                pd[l][r] = 1;
            }else if(s[l]==s[r] && pd[l+1][r-1]==1){  // 间隔2个数以上的, 要求上一次是回文
                pd[l][r] = 1;
            }

            if(pd[l][r]==1 && (r-l+1) > result.size()){
                result = s.substr(l,r+1);
            }

        }
    }



}

// 解法2
std::string Solution5::longestPalindrome2(std::string s){
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    std::string ans;
    /****************************************
     * 先规划所有长度为1的子串
     * 再规划所有长度为2的子串
     * ....
     * 
     ****************************************/ 
    for (int l = 0; l < n; ++l) {  // 控制子字符串长度
        for (int i = 0; i + l < n; ++i) {
            int j = i + l;
            if (l == 0) {  // 单个字符, 必为回文
                dp[i][j] = 1;
            } else if (l == 1) {  // 两个字符, 相等时必为回文
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            if (dp[i][j] && l + 1 > ans.size()) {
                ans = s.substr(i, l + 1);
            }
        }
    }
    return ans;
}



void Solution5::test(){

}