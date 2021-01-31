#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 

#include <vector>



template <class TYPE>

/***************************************
 * 从数组创建vector
 * 函数模板不能分离实现
 ***************************************/
std::vector<TYPE> createVector(TYPE array[], int length){
    std::vector<TYPE> res;

    /***************
     * 方法1:
     ***************/
    for(int i=0; i<length; i++){
        res.push_back(array[i]);
    }

    /***************
     * 方法2:
     * 传入两个参数array和*(&array+1), 两个都是指针, array指向数组的首元素地址, 
     * &array为指向数组指针的指针, 加1后就直接跨越了1个数组长度, 再用*取值后, *(&array + 1)为指向数组尾元素的地址.
     ***************/
    // vector<int> res2(array, *(&array + 1));
    // return res2;

    return res;
}
#endif