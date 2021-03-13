#include "include/24_SwapNodesInPairs.h"
#include "math.h"
#include <algorithm>
#include <queue>

/*******************************************
 *  24. 两两交换链表中的节点
 ******************************************/
ListNode* Solution24::swapPairs(ListNode* head){
    ListNode* head = new ListNode();
    ListNode* p = head;

    if(head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* node = head->next;
    head->next = swapPairs(node->next);
    node->next = head;

    return node;
}

