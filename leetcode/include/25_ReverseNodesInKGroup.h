#ifndef _25_REVERSE_NODES_IN_K_GROUP_
#define _25_REVERSE_NODES_IN_K_GROUP_

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>

#include <vector>
#include <map>
#include <set>

#include "1.h"


// 25. K个一组翻转链表
class Solution25 {
public:
    std::pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* end);
    ListNode* reverseKGroup(ListNode* head, int k);
    void test();

};

#endif