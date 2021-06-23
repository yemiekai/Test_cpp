#include "21_MergeTwoSortedLists.h"
#include "math.h"
#include <algorithm>

/*******************************************
 * 
 *  21. 合并两个有序的列表
 ********************************************/

ListNode* Solution21::mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode* head;
    ListNode* pList = head;

    while(l1 != nullptr && l2 != nullptr){
        if(l1->val < l2->val){
            pList->next = l1;
            l1 = l1->next;
        }else{
            pList->next = l2;
            l2 = l2->next;
        }
        pList = pList->next;
    }

    if(l1 != nullptr){
        pList->next = l1;
    }
    
    if(l2 != nullptr){
        pList->next = l2;
    }

    return head->next;

}
