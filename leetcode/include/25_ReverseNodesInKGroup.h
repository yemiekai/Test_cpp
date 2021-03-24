#ifndef _25_REVERSE_NODES_IN_K_GROUP_
#define _25_REVERSE_NODES_IN_K_GROUP_

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

// 25. K个一组翻转链表
class Solution25 {
public:
    std::pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* end);
    ListNode* reverseKGroup(ListNode* head, int k);
    void test();

};

#endif