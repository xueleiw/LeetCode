/**
 * 2024-12-19
 * 一次遍历，从前往后逐个节点翻转:使用三个指针
 * 注意情况：空集合；只有一个节点；多个节点
 */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        // 只有一个节点
        if(head->next == nullptr) {
            return head;
        }

        ListNode* pa = head->next;
        ListNode* tmp = head;
        tmp->next = nullptr;  // 尾节点指向空
        ListNode* p_back = pa->next;  // 还不知道有没有三个节点，可能为空
        
        while (pa != nullptr) {
            pa->next = tmp;
            tmp = pa;
            pa = p_back;
            if(p_back == nullptr) {
                break;
            }
            p_back = pa->next;
        }
        
        return tmp;

    }
};

int main() {
    Solution solu;
    // 创建一个链表
    
    ListNode* node3 = new ListNode(30);  // 第三个节点，值为 30
    ListNode* node2 = new ListNode(20, node3);  // 第二个节点，值为 20，指向 node3
    ListNode* node1 = new ListNode(10, node2);  // 第一个节点，值为 10，指向 node2

    ListNode* result = solu.reverseList(node2);
    for(ListNode* p = result; p != nullptr; p = p->next) {
        cout << p->val << ' ';
    }

    delete node1;
    delete node2;
    delete node3;

    cout << __cplusplus;
    return 0;
}