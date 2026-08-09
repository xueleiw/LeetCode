/**
 * 2025-1-2
 * 1-: 本题的思路是需要4个指针维护被交换两个节点的头尾节点，以及指向被交换的两个节点；开始需要先确定头结点，以及链表为空或只有1个元素的情况。
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = head;
        int len = 0;

        for(p; p != nullptr; p = p->next) {
            len++;
        }
        if(head == nullptr || head->next == nullptr) { // 如果是空链表或者链表只有一个节点无法交换
            return head;
        }

    //    p = head;
        ListNode* a = nullptr;
        ListNode* b = nullptr;
        ListNode* prev = nullptr;
        a = head;
        b = head->next;
        p = head->next->next; // 指向第三个
        b->next = a;
        a->next = p;
        prev = a;
        head = b;
        while (true) {
            // 
            a = p;
            if(a != nullptr) {
                if(a->next != nullptr) {
                    b = a->next;
                    p = b->next;
                } else {
                    break; // 说明后面没有节点可以交换——直接退出
                }
            } else { 
                break; // 说明到了最后直接退出
            }
            // swap
            b->next = a;
            a->next = p;
            prev->next = b;
            prev = a;
        }
        
        return head;
    }
};


int main() {

    return 0;
}