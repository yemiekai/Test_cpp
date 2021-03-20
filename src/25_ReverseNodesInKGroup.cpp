#include "include/25_ReverseNodesInKGroup.h"
#include "math.h"
#include <algorithm>
#include <queue>

/*******************************************
 *  25. K个一组翻转链表
 ******************************************/

// 反转区间
std::pair<ListNode*, ListNode*> Solution25::reverse(ListNode* head, ListNode* end){
/*******************************************************************
 * 思路:
 * head                                              end
 * [1] ----> [2] ----> [3] ----> [4] ----> [5] ----> [6]
 * [1] <---- [2]       [3] ----> [4] ----> [5] ----> [6]
 * [1] <---- [2] <---- [3]       [4] ----> [5] ----> [6]
 * [1] <---- [2] <---- [3] <---- [4]       [5] ----> [6]
 * [1] <---- [2] <---- [3] <---- [4] <---- [5]       [6]
 * [1] <---- [2] <---- [3] <---- [4] <---- [5] <---- [6]
 * 
 * 
 * 其中, head和end不变
 * head                                              end
   [1] <---- [2]       [3] ----> [4] ----> [5] ----> [6]
           newHead newHeadNext    n
   
 * head                                              end
   [1] <---- [2] <---- [3]       [4] ----> [5] ----> [6]
           newHead newHeadNext    n

 * head                                              end
   [1] <---- [2] <---- [3]       [4] ----> [5] ----> [6]
                     newHead      n
                   newHeadNext    

 * head                                              end
   [1] <---- [2] <---- [3]       [4] ----> [5] ----> [6]
                     newHead  newHeadNext  
                       
 * 
 * 
 *******************************************************************/
    ListNode* newHead = head;
    ListNode* newHeadNext = head->next;

    while(newHead != end){

        ListNode* n = newHeadNext->next;
        newHeadNext->next = newHead;
        newHead = newHeadNext;
        newHeadNext = n;
    }

    return {end, head};
}

ListNode* Solution25::reverseKGroup(ListNode* head, int k){
    ListNode* hair = new ListNode();  // 头发比头还高
    hair->next = head;
    ListNode *end = head;
    ListNode *pre = hair;

    while(head){
        // 获取间隔K的头和尾
        for(int i=0; i<k; i++){
            end = head->next;
            if(end==nullptr){
                return hair->next;
            }
        }
         
        ListNode *tmp = end->next;  // 记下尾部的下一个地方
        std::pair<ListNode*, ListNode*> result = reverse(head, end);  // 反转这个区间

        // 这个区间的头和尾
        head = result.first;
        end = result.second;

        // 把这个区间接回去
        pre->next = head;
        end->next = tmp;

        // 下一次反转的初始指针
        pre = end;
        head = end->next;
    }



    return hair->next;
}