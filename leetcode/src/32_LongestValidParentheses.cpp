#include "32_LongestValidParentheses.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>

/***********************************************************
 * 32 最长有效括号
 * https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/
 * 解法2
 ************************************************************/ 
int Solution32::longestValidParentheses(std::string s){
    int maxLength = 0;
    std::stack<int> stk;
    stk.push(-1);
    int total = s.size();

    for(int i=0; i<total; i++){
        if(s[i]=='(')  // 左括号, 索引进栈
        {
            stk.push(i);  
        }
        else  // 右括号, 弹出一个`左括号`
        {
            stk.pop();

            if(stk.empty()){
                stk.push(i);  // 栈为空, 把当前右括号的索引进栈
            }else{
                maxLength = std::max(maxLength, i-stk.top());  // 当前索引减栈顶索引
            }
        }
    }

}