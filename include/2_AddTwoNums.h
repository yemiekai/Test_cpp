#ifndef _2_ADD_TWO_NUMS_
#define _2_ADD_TWO_NUMS_

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 

#include <vector>
#include <map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution2 {
public:
    void test();
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

#endif