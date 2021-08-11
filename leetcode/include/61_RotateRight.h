#ifndef _61_ROTATE_RIGHT_H
#define _61_ROTATE_RIGHT_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <string.h>  // memset的头文件
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include "1.h"

// 61 旋转链表
/*******************************************************************************************
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

====================================================================
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
====================================================================
输入：head = [0,1,2], k = 4
输出：[2,0,1]

*********************************************************************************************/
class Solution61{

public:

    ListNode* rotateRight(ListNode* head, int k);
    
    void test();

};

#endif