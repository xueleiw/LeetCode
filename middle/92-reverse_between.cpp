#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// 4-21
// 0ms

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 思路就是判断要翻转的是不是从1开始，分成两种情况讨论；然后记录区间的前后节点，将翻转后的链表接回去就行
class Solution {
    public:
        ListNode* reverse(ListNode* head, ListNode* tail) {
            ListNode* prev = nullptr;
            ListNode* cur = head;
            while(cur != nullptr) {
                ListNode* back = cur->next;
                cur->next = prev;
                prev = cur;
                cur = back;
            }
            return prev;
        }

        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if(left == right || head->next == nullptr) return head; // 确保两个节点以上
            
            ListNode* res = nullptr;
            
            
            if(left == 1) { // 从头开始翻
                ListNode *back = nullptr;
                ListNode* cur = head;
                int index = 1;
                for(cur; cur != nullptr; cur = cur->next) {
                    // if(left == index - 1) {
                    //     p = cur;
                    // }
                    if(right == index) {
                        back = cur->next;
                        cur->next = nullptr;
                        ListNode* new_head = reverse(head, cur);
                        head->next = back;
                        return new_head;
                    }
                    index++;
                }
            } else {
                ListNode *back = nullptr;
                ListNode* prev = head;
                ListNode* cur = head->next;
                ListNode* p = nullptr;
                int index = 2;
                for(cur; cur != nullptr; cur = cur->next) {
                    if(left == index) {
                        p = cur;
                    } else if(left > index) {
                        prev = cur;
                    }
                    //
                    if(right == index) {
                        back = cur->next;
                        cur->next = nullptr;
                        ListNode* new_head = reverse(p, cur);
                        prev->next = new_head;
                        p->next = back;
                        // return head;
                        break;
                    }
                    index++;
                }

            }

            return head;
        }
    };