#include "22_GenerateParentheses.h"
#include "math.h"
#include <algorithm>

/*******************************************
 * 
 *  22. 括号生成
 * 
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 ********************************************/

std::string tempString;
std::vector<std::string> result;
int N;
int left;
int right;
void cycle(){
    if(tempString.length()>=N*2){
        result.push_back(tempString);
    }

    if(left < N){
        
    }
}
// 题解见头文件
std::vector<std::string> generateParenthesis(int n) {
    
}