#ifndef _21_MERGE_TWO_SORTED_LISTS_H_
#define _21_MERGE_TWO_SORTED_LISTS_H_

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

// 21. 合并两个有序的列表
class Solution21 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    void test();

};

#endif