#include "61_RotateRight.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>

// 61 旋转链表
/*******************************************************************************************
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

====================================================================
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]

解释：连成环后, 指针向右移动(3)位, 就是新的头  (长度是5, 5-2=3)
====================================================================
输入：head = [0,1,2], k = 4
输出：[2,0,1]

解释：连成环后，指针向右移动(2)位, 就是新的头  (长度是3, 4%3=1, 3-1=2)
*********************************************************************************************/


ListNode* Solution61::rotateRight(ListNode* head, int k){

    // 这种情况直接返回
    if(k==0 || head==nullptr || head->next==nullptr){
        return head;
    }
    
    ListNode* end = head;
    ListNode* now = head;
    ListNode* newEnd = nullptr;  // 尾指针, 在now前1位. (因为是个环)
    int leng = 0;

    // 先算链表长度
    while(now){
        end = now;
        now = now->next;
        leng++;
    }
    
    // 首尾相连
    end->next = head;

    // 要断开的位置. 向右移就是 "k%leng", 向左移就是 "leng - k%leng", 因为
    int move = leng - k%leng;

    // 重置一下
    now = head;

    // 头指针向右移动move次, 就是新的头的位置
    while(move){
        
        if(nullptr == now->next){
            end = head;
            now = head;
            newEnd = nullptr;
        }
        newEnd = now;
        now = now->next;
        move--;
    }


    // 拼接新的首位
    newEnd->next = nullptr;

    return now;

}

