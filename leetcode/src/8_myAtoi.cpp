#include "8_myAtoi.h"
#include "math.h"

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




void Solution8::test(){
    int result = myAtoi(" asdf  ad -12346576 asdf ");
    std::cout << result << std::endl;

}
