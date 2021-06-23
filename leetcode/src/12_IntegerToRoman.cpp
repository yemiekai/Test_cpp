#include "12_IntegerToRoman.h"
#include "math.h"

/*******************************************
 * 
 * 12. 整数转罗马数字
 * 
 ********************************************/
std::string Solution12::intToRoman(int num){
    int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    std::string res = "";

    for(int i=0; i<13; i++){
        while(num > nums[i]){
            num -= nums[i];
            res += romans[i];
        }
    }

    return res;
    
}




void Solution12::test(){
    

}
