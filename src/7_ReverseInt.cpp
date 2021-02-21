#include "include/7_ReverseInt.h"


/*******************************************
 * 
 * 反转数字
 * 
 ********************************************/ 
int Solution7::reverse(int x){
    int result;
    int single;
    int sign = 1;

    if(x==0){
        return x;
    }

    if(x<0){
        x = 0-x;
        sign = -1;
    }

    while( x>0 ){
        single = x%10;

        // 这里要先检查会不会溢出, 再决定下一步

        result = result*10 + single;
        x = x/10;
    }
    
    return sign*result;
}




void Solution7::test(){

}
