#include "include/4_FindMedianSortedArrays.h"
#include "include/utils.h"


/*******************************************
 * 
 * 获取两个数组的中位数
 * 
 ********************************************/ 
double Solution4::findMedianSortedArrays(std::vector<int>& num1, std::vector<int>& num2){
    int length1 = num1.size();
    int length2 = num2.size();
    int total = length1 + length2;

    // 长度为奇数, 例如[1,2,3,4,5], 返回3
    if(1 == total%2){
        double k = this->getKthNumber(num1, num2, total/2 + 1);
        return k;
    }
    else // 长度为偶数, 例如[1,2,3,4,5,6], 返回(3+4)/2
    { 
        double k1 = this->getKthNumber(num1, num2, total/2);
        double k2 = this->getKthNumber(num1, num2, total/2+1);
        return (k1+k2)/2.0;
    }

}


/****************************************
 * 
 * 获取两个有序数组(先把它们合并起来排序)中, 排序第k个数(从小到大排)
 * 
 ****************************************/
double Solution4::getKthNumber(std::vector<int>& num1, std::vector<int>& num2, int k){
    int length1 = num1.size();
    int length2 = num2.size();
    int bias1 = 0;  // num1当前起始位置的索引, 假装前面bias1个数字全部被干掉了
    int bias2 = 0;  // num2当前起始位置的索引, 假装前面bias2个数字全部被干掉了
    int restNums = k;  // 现在要找: 在剩下的总数里面排第resNums的数

    // 异常判断
    if(k > (length1+length2)){
        return 0;
    }

    while(true){
        /**************************************************
         * 可以先不看这几个if条件, 看完下面的处理, 再来看这几个判断
         **************************************************/ 
        if(bias1 == length1){
            return num2[bias2 + restNums-1];
        }
        if(bias2 == length2){
            return num1[bias1 + restNums-1];
        }
        if(restNums == 1){
            return std::min(num1[bias1], num2[bias2]);
        }

        // 算中位数的位置, 并且防止越界
        int nowIdx1 = std::min(restNums/2-1 + bias1, length1-1);
        int nowIdx2 = std::min(restNums/2-1 + bias2, length2-1);

        // 哪个小, 就把哪个数组前bias个数字干掉, 对bias进行偏移
        if(num1[nowIdx1] <= num2[nowIdx2]){
            bias1 = nowIdx1 + 1;
        }else{
            bias2 = nowIdx2 + 1;
        }
        
        // 还剩下的数, bias总数就是被干掉的数
        restNums = k - (bias1+bias2);

    }

    
}

void Solution4::test(){
    int num1[2] = {1, 2};
    int num2[2] = {3, 4};
    std::vector<int> a = createVector(num1, 2);
    std::vector<int> b = createVector(num2, 2);

    double result = findMedianSortedArrays(a, b);
    printf("result : %f\n", result);
}