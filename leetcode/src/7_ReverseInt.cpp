#include "7_ReverseInt.h"


/*******************************************
 * 
 * 反转数字
 * 
 ********************************************/ 
int Solution7::reverse(int x){
    int result;
    int single;
    int sign = 1;


    while( x!=0 )
    {
        // 这里要先检查会不会溢出, 溢出直接返回0
        if(result < INT_MIN/10 || result > INT_MAX/10){
            return 0;
        }
        single = x%10;
        result = result*10 + single;
        x = x/10;
    }
    
    return result;
}




void Solution7::test(){

}
