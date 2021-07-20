#include "43_Multiply.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>


/***********************************************************
 * 43 字符串相乘
 * 
 ************************************************************/ 





// 两个字符串相加
std::string Solution43::addString(std::string s1, std::string s2){
    std::cout << "add in1 :" << s1 << std::endl;
    std::cout << "add in2 :" << s2 << std::endl;

    int idx = 1;
    std::string result("");
    int up = 0;  // 进位标志
    int sum = 0;

    // 从低位开始加, 所以要反转一下
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());

    while(idx<=s1.size() && idx<=s2.size())
    {
        int x = (s1[idx-1] - '0') > 0 ? (s1[idx-1] - '0') : 0;
        int y = (s2[idx-1] - '0') > 0 ? (s2[idx-1] - '0') : 0;
        sum = x+y+up;
        up = sum/10;
        result += (sum%10 + '0');
        idx++;
    }
    
    /************************************************************
     * 其中一个字符串已经处理完了, 剩下s1或者s2还有一部分
     * 到底是谁还有剩的, 不用管, 2个while循环一视同仁
     ************************************************************/

    while(idx<=s1.size()){
        int x = (s1[idx-1] - '0') > 0 ? (s1[idx-1] - '0') : 0;
        sum = x + up;
        up = sum/10;
        result += (sum%10 + '0');

        idx++;
    }

    while(idx<=s2.size()){
        int x = (s2[idx-1] - '0') > 0 ? (s2[idx-1] - '0') : 0;
        sum = x + up;
        up = sum/10;
        result += (sum%10 + '0');

        idx++;
    }

    // 最后的进位
    if(up>0){
        result += '1';
    }
    
    // 再倒回来
    std::reverse(result.begin(), result.end());

    std::cout << "add out :" << result << std::endl << std::endl;
    return result;
}


std::string Solution43::multiply(std::string num1, std::string num2){

    std::string result("");

    if(num1.size()==0 || num2.size()==0){
        return std::string("0");
    }
    
    if(num1.size()==1 && num1[0]=='0'){
        return std::string("0");
    }

    if(num2.size()==1 && num2[0]=='0'){
        return std::string("0");
    }

    std::string bigger = num1;
    std::string smaller = num2;
    if(smaller.size() > bigger.size() ){
        bigger = num2;
        smaller = num1;
    }
    
    std::cout << "bigger :" << bigger << std::endl;
    std::cout << "smaller:" << smaller << std::endl;
    /*********************************************
     * bigger:   3 4 5
     * smaller:    1 2
     * --------------------
     *           6 9 0
     *         3 4 5
     * 
     * tmp = 2*5*1 + 2*4*10 + 2*3*100
     * 
     * 首先用2乘以bigger里面每一个数, 所以第2个for循环里面是bigger, 得到690
     * 
     * 每大循环一次, 要补一个0, 例如第二次大循环得到345, 要
     *********************************************/
    
    int zeros = 0;  // 要补几个零

    for(int i=smaller.size()-1; i>=0; i--){

        int lower = 0;
        int upper = 0;
        std::string tmp("");

        // 逐位相乘
        for(int j=bigger.size()-1; j>=0; j--){
            int x = (bigger[j] - '0') > 0 ? (bigger[j] - '0') : 0;
            int y = (smaller[i] - '0') > 0 ? (smaller[i] - '0') : 0;
            int num = x*y + upper;  // upper: 来自上一次的进位
            lower = num%10;  // 个位数
            upper = num/10;  // 十位数(要进位的)
            tmp += (lower+'0');
        }

        // 还有进位
        if(upper>0){
            tmp += (upper+'0');
        }
        
        // 前面是倒过来加的, 所以要倒回来 
        std::reverse(tmp.begin(), tmp.end());

        // 补zeros个0
        for(int z=0; z<zeros; z++){
            tmp += "0";
        }
        
        // 加到结果里, 继续下一轮乘法
        result = addString(result, tmp);
        zeros++;

        std::cout << tmp << std::endl;
    }

    return result;
}



void Solution43::test(){

    std::cout << multiply("123456789","987654321") << std::endl;

    // std::cout <<"True ans:" << 123*456 << std::endl;
    
}
