#include "include/20_ValidParentheses.h"
#include "math.h"
#include <algorithm>

/*******************************************
 * 
 *  20. 有效的括号
 ********************************************/

bool Solution20::isValid(std::string s){
    std::map<char, char> mp = {
        {'{', '}'},
        {'[', ']'},
        {'(', ')'}
    };
    std::vector<char> stack;
    for(char cc:s){
        if(mp.count(cc)){  // 是左括号, 直接往stack里加
            stack.push_back(cc);
        }else{
            char end = stack.back();  // 是右括号, 取出栈顶元素
            stack.pop_back();
            if(mp[end] != cc){  // 是否配对
                return false;
            }
        }
    }

    return stack.empty();
}
