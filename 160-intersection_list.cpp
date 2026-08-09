/**
 * 2024-12-20
 * 1-先反转两个链表，直至遍历到不相同的节点；这样的复杂度应该是线性的
 * 2-两层for循环遍历，暴力求解
*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;
        // ListNode* result = nullptr;
        if(pa == nullptr || pb == nullptr) {
            return nullptr;
        }

        // 因为不确定哪个链表更长
        for(pa = headA; pa != nullptr; pa = pa->next) {
            for(pb = headB; pb != nullptr; pb = pb->next){
                if(pa == pb){
                    return pa;
                }
            }
        }
        
        return nullptr;
    }
};

int main() {
    
    return 0;
}