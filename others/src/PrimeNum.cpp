#include "PrimeNum.h"
#include "math.h"

/*****************************
 * 判断素数（ 除了1和它自己, 没有数可以整除了）
 * 
 * 先开根号, 从2开始遍历, 都不能整除就是素数
 * 
 ****************************/

bool isPrime(int num){
    int sq = 0;

    sq = (int)sqrt((double)num);  // 因为是对称的, 算到根号那里就可以了

    for(int i=2; i<=sq; i++){
        if(num%i == 0){
            return false;
        }
    }

    return true;

}