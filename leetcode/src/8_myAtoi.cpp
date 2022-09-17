#include "8_myAtoi.h"
#include "math.h"
#include "unordered_map"


/*******************************************
 * 
 * 字符串转数字
 * 
 ********************************************/ 
int Solution8::myAtoi(std::string s){
    unsigned int result = 0;
    int sign = 1;  // 1:正数, -1:负数
    unsigned int positiveMax = 1u << 31 - 1;
    unsigned int negativeMax = 1u << 31;
    
    bool start = false;

    for(char c : s){
        if(start){
            if( c >= '0' && c <='9'){
                result = result*10 + c - '0';

                if(sign == 1 && result >=positiveMax){
                    return positiveMax;
                }else if(sign == -1 && result >= negativeMax){
                    return sign*negativeMax;
                }

                continue;
            }else{
                break;
            }
        }
        else{
            if( c=='-'){
                sign = -1;
                start = true;
            }else if( c >= '0' && c <='9'){
                result = result*10 + c - '0';
                start = true;
            }else{
                
            }
           
            
        }

    }

    return sign * result;
}

class AutoMachine{
public:
    int m_sign = 1;
    std::string m_state = "start";
    long long m_ans = 0;

    std::unordered_map<std::string, std::vector<std::string> > m_table = {
        {"start", {"start", "signed", "in_number", "end"} },
        {"signed", {"end", "end", "in_number", "end"} },
        {"in_number", {"end", "end", "in_number", "end"} },
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c){
        if(std::isspace(c)){
            return 0;
        }else if(c == '-' || c == '+'){
            return 1;
        }else if(std::isdigit(c)){
            return 2;
        }else{
            return 3;
        }
    }

    void get(char c){
        m_state = m_table[m_state][get_col(c)];
        if(m_state=="signed"){
            m_sign = (c == '-' ? -1 : 1);
        }

        if(m_state=="in_number"){
            m_ans = m_ans*10 + (c-'0');
            if(m_sign==1){
                m_ans = std::min(m_ans, (long long)INT_MAX);
            }else{
                m_ans = std::min(m_ans, -(long long)INT_MIN);  // 因为到时候还要乘以-1
            }
        }

    }
private:
};

// 解法2
int Solution8::myAtoi2(std::string s){
    AutoMachine a;
    for(char c : s){
        a.get(c);
    }
    return a.m_sign * a.m_ans;
}

void Solution8::test(){
    int result = myAtoi(" asdf  ad -12346576 asdf ");
    std::cout << result << std::endl;
    

}
