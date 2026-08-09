/**
 * 2025-1-2
 * 1-: 按照链表的长度遍历之后删除节点即可，需要考虑删除头结点的情况
 */


#include<iostream>
#include<vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



/*===============1-: 0ms=====================*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int len = 0;
        for(p; p != nullptr; p = p->next) {
            len++; // 计算链表的长度
        }
        if(len == n) { // 删除头结点
            return head->next;
        }

        p = head;
        for(int i =1; i< len - n; i++) {
            p = p->next; // 到它的父节点
        }
        p->next = p->next->next;
        return head;
    }
};

int main() {


    return 0;
}
