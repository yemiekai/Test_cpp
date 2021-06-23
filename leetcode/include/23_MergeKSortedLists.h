#ifndef _23_MERGE_K_SORTED_LISTS_H_
#define _23_MERGE_K_SORTED_LISTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>

#include <vector>
#include <map>
#include "1.h"

// 23. 合并K个升序的列表
class Solution23 {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists);
    void test();

};

#endif