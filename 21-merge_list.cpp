/**
 * 2024-12-21
 * 1-新建一个头结点代表返回链表的头，注意两个输入链表的判空，最后返回的时候删除头结点即可； 但是我没有理解为什么最后还要返回空值，已经考虑了所有情况。
 * 
*/
#include<bits/stdc++.h>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr = new ListNode(-1);
        ListNode* prev = curr;
        ListNode* pa = list1;
        ListNode* pb = list2;
        // 判断链表是否有空的情况
        if(list1 == nullptr && list2 ==nullptr) {
            return nullptr;
        } else if(list1 == nullptr) {
            return list2;
        } else if(list2 == nullptr) {
            return list1;
        }
        // 下面保证两个链表都不为空
        while (pa != nullptr && pb != nullptr) {
            if(pa->val <= pb->val) {
                prev->next = pa; 
                prev = prev->next;
                pa = pa->next;
            } else {
                prev->next = pb; 
                prev = prev->next;
                pb = pb->next;
            }
        }
        if(pa != nullptr) {
            prev->next = pa;
            return curr->next;
        }

        if(pb != nullptr) {
            prev->next = pb;
            return curr->next;
        }
        return nullptr;
    }
};

int main() {


    return 0;
}