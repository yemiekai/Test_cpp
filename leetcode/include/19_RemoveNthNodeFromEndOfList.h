#ifndef _19_REMOVE_N_TH_FROM_END_H_
#define _19_REMOVE_N_TH_FROM_END_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>

#include <vector>
#include <map>
#include <set>

#include "1.h"

// 19. 删除链表的倒数第N个节点
class Solution19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
    void test();

};

#endif