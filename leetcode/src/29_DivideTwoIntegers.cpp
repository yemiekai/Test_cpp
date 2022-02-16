#include "29_DivideTwoIntegers.h"
#include "math.h"
#include <algorithm>
#include <queue>


int Solution29::divide(int dividend, int divisor){
    
    /********************************
     * 各种前置判断
     ********************************/ 
    int sign = 1;  // 正数
    if((dividend>0 && divisor<0) || (dividend<0 && divisor>0) ){
        sign = -1;  // 负数
    }
    
    dividend = std::abs(dividend);  // 被除数
    divisor = std::abs(divisor);  // 除数

    // dividend / divisior
    if(divisor > dividend){
        return 0;
    }


    /************************************************
     * 算法开始, 以减法为基础, 以二分法加速
     * 例如 21 / 2, 做下面的循环:
     *  21 - 2 = 19    结果+=1, 减数翻倍(2变成4)
     *  19 - 4 = 15    结果+=2, 减数翻倍(4变成8)
     *  15 - 8 = 7     结果+=4, 减不动了, 减数回到初始值(8变成2)
     * 
     *  7  - 2 = 5     结果+=1, 减数翻倍(2变成4)
     *  5 -  4 = 1     结果+=2  ........
     *   ....
     * 
     ************************************************/ 

    int result = 0;
    int res = dividend;  // 剩下的数
    int sub = divisor; // 减数
    int once = 1;  // 减一次的结果

    while(res >= divisor){

        // 每次把减数翻倍, 直到减不动了, 又重新来
        while(res >= sub){
            res = res - sub;
            result = result + once;

            // 下一次的
            sub = sub+sub; // 减数翻倍
            once = once+once;  // 减一次的结果也翻倍
        }
        
        // 重新来
        sub = divisor;
        once = 1;

    }


    return result;
}
