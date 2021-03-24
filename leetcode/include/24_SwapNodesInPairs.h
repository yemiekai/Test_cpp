#ifndef _24_SWAP_NODES_IN_PAIRS_H_
#define _24_SWAP_NODES_IN_PAIRS_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>

#include <vector>
#include <map>
#include <set>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 24. 两两交换链表中的节点
class Solution24 {
public:
    ListNode* swapPairs(ListNode* head);
    void test();

};

#endif