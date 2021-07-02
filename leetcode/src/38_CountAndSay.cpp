#include "38_CountAndSay.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>

/***********************************************************
 * 38  外观数列
 * 
 ************************************************************/ 
std::string Solution38::countAndSay(int n){
    std::string nowString("1");

    for(int i = 1; i<n; i++){
        std::string saying = "";  // 对nowString的读音

        // 从第一个数开始
        char num = nowString[0];  // 当前是什么数字
        int count = 0;  // 当前数字出现了几次
        
        // 遍历要读的字符串
        for(char c : nowString){

            if(num == c)  // 数字相同, 给它计数
            {
                count++;
            }
            else  // 数字不同了
            {
                saying.push_back('0'+count);  // 它出现的次数
                saying.push_back(num);  // 它是什么数

                // 下一个数字
                num = c;  
                count = 1;
            }
        }
        
        saying.push_back('0'+count);
        saying.push_back(num);

        nowString = saying;  // 下一轮循环对它来读数
    }

    return nowString;
}


void Solution38::test(){

    std::string saying = countAndSay(5);

    std::cout << saying << std::endl;

    return ;
}