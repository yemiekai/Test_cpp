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
        if(mp.find(cc) != mp.end()){
            stack.push_back(cc);
        }else{
            char end = stack.back();
            stack.pop_back();
            if(mp[cc] != cc){
                return false;
            }
        }
    }

    return stack.empty();
}
