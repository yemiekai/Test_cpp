#ifndef _4_FIND_MEDIAN_SORTED_ARRAYS_H_
#define _4_FIND_MEDIAN_SORTED_ARRAYS_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>

#include <vector>
#include <map>
#include <set>

class Solution4 {
public:
    void test();
    double findMedianSortedArrays(std::vector<int>& num1, std::vector<int>& num2);
    double getKthNumber(std::vector<int>& num1, std::vector<int>& num2, int k);


};

#endif