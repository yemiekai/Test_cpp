#ifndef _19_REMOVE_N_TH_FROM_END_H_
#define _19_REMOVE_N_TH_FROM_END_H_

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
 
// 19. 删除链表的倒数第N个节点
class Solution19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
    void test();

};

#endif