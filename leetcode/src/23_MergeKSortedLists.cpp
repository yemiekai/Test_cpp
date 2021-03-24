#include "include/23_MergeKSortedLists.h"
#include "math.h"
#include <algorithm>
#include <queue>

/*******************************************
 *  23. 合并K个升序的列表
 ******************************************/
struct Status{
    int val;
    ListNode* node;
    bool operator < (const Status &ref) const{
        return val > ref.val;  // 优先队列是降序的, 排序的依据是运算符<, 我们要的是升序, 所以这里用>实现<
    }

    Status() : val(0), node(nullptr) {}
    Status(int x) : val(x), node(nullptr) {}
    Status(int x, ListNode *n) : val(x), node(n) {}
};

ListNode* Solution23::mergeKLists(std::vector<ListNode*>& lists){
    std::priority_queue<Status> pq;  // 优先队列是有序的, 元素push进去后会自动排序
    ListNode* head = new ListNode();
    ListNode* p = head;

    for(ListNode *n :lists){
        if(n){
            pq.push(Status(n->val, n));
        }
    }
    
    while(!pq.empty()){
        p->next = pq.top().node;  // 取出队列头(val最小的), 上链
        pq.pop();

        p = p->next;  // 移动到链表尾
        if(p->next){
            pq.push(Status(p->next->val, p->next));  // 把下一个元素加入队列
        }
    }
    
    return head->next;
}

