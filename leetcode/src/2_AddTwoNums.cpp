#include "2_AddTwoNums.h"



ListNode* Solution2::addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode *result = new ListNode(0);
    ListNode *pl1 = l1;
    ListNode *pl2 = l2;
    int update = 0;
    int sumtmp;

    while(pl1 != nullptr && pl2 != nullptr){
        sumtmp = pl1->val + pl2->val + update;
        if(sumtmp >= 10){
            update = 1;
            result->next = new ListNode(sumtmp-10);
        }else{
            update = 0;
            result->next = new ListNode(sumtmp);
        }

        pl1 = pl1->next;
        pl2 = pl2->next;
        result = result->next;
    }

    while(pl1 != nullptr){
        result->next = new ListNode(pl1->val);
        pl1 = pl1->next;
    }
    
    while(pl2 != nullptr){
        result->next = new ListNode(pl2->val);
        pl2 = pl2->next;
    }

    return result->next;

}


void Solution2::test(){
    std::vector<int> v1 = {2, 4, 3};
    std::vector<int> v2 = {5, 6, 4};

    ListNode *h1 = new ListNode(0);
    ListNode *h2 = new ListNode(0);

    ListNode *l1 = h1;
    ListNode *l2 = h2;
    for(int v : v1){
        l1->next = new ListNode(v);
        l1 = l1->next;
    }

    for(int v : v2){
        l2->next = new ListNode(v);
        l2 = l2->next;
    }

    // 看看结果
    // while (h1)
    // {
    //     std::cout << h1->val <<std::endl;
    //     h1=h1->next;
    // }

    ListNode *result = addTwoNumbers(h1->next, h2->next);


    
}