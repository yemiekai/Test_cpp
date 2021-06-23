#include "19_RemoveNthNodeFromEndOfList.h"
#include "math.h"
#include <algorithm>

/*******************************************
 * 
 *  19. 删除链表的倒数第N个节点
 ********************************************/

ListNode* Solution19::removeNthFromEnd(ListNode* head, int n){
    ListNode* pEnd = head;
    ListNode* pStart = head;

    // 双指针, 一头一尾, 两个指针间隔n+1
    while(n>=0 && pEnd!=nullptr){
        pEnd = pEnd->next;
        n--;
    }

    if(pEnd == nullptr){
        return head;
    }

    while(pEnd->next != nullptr){
        pEnd = pEnd->next;
        pStart = pStart->next;
    }
    
    pStart->next = pStart->next->next;

    return head;
}
