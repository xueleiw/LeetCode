/**
 * 2024-12-20
 * 1-存在两个vector里面，然后依次遍历相加，最关键的是保存和处理进位情况。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> A, B;
        stack<int> C, D;
        for(ListNode* p = l1; p != nullptr; p = p->next) {
            A.push_back(p->val);
        }
        for(ListNode* p = l2; p != nullptr; p = p->next) {
            B.push_back(p->val);
        }

        A.reserve(A.size());
        B.reserve(B.size());
        ListNode* res = new ListNode();
        ListNode* p = res;
        ListNode* prev = nullptr;
        int tmp_sum = 0; // 进位
        int i = 0; // 记录长链表位置
        if(A.size() >= B.size()) {
            // 根据短的链表遍历
            for(i; i < B.size(); i++) {
                int x = A[i];
                int y = B[i];
                int bit_sum = (((x + y) % 10) + tmp_sum) % 10; // 加完进位也要取模
                if(x + y + tmp_sum >= 10) {
                    tmp_sum = 1;
                } else {
                    tmp_sum = 0;
                }
                p->val = bit_sum;
                p->next = new ListNode();
                prev = p;
                p = p->next;
            }
            for(i; i < A.size(); i++) {
                int bit_sum = (A[i] + tmp_sum) % 10;
                p->val = bit_sum;
                if(A[i] + tmp_sum >= 10) {
                    tmp_sum = 1;
                } else {
                    tmp_sum = 0;
                }
                p->next = new ListNode();
                prev = p;
                p = p->next;
            }
        } else {
            for(i; i < A.size(); i++) {
                int x = A[i];
                int y = B[i];
                int bit_sum = (((x + y) % 10) + tmp_sum) % 10;
                if(x + y + tmp_sum >= 10) {
                    tmp_sum = 1;
                } else {
                    tmp_sum = 0;
                }
                p->val = bit_sum;
                p->next = new ListNode();
                prev = p;
                p = p->next;
            }
            for(i; i < B.size(); i++) {
                int bit_sum = (B[i] + tmp_sum) % 10;
                p->val = bit_sum;
                if(B[i] + tmp_sum >= 10) {
                    tmp_sum = 1;
                } else {
                    tmp_sum = 0;
                }
                p->next = new ListNode();
                prev = p;
                p = p->next;
            }
        }

        // 如果最后一个节点是0就把最后一个新建的节点删去，因为不属于结果
        if(tmp_sum == 0){
            prev->next = nullptr;
        } else {
            p->val = tmp_sum;
        }
        return res;
    }
};

int main() {
    Solution solu;
    // 创建一个链表
    
    ListNode* node3 = new ListNode(3);  
    ListNode* node2 = new ListNode(7);  
    ListNode* listA = new ListNode(3, node2);

    ListNode* nodeb2 = new ListNode(4);  
    ListNode* nodeb1 = new ListNode(2);  
    ListNode* listB = new ListNode(9, nodeb1);

    ListNode* result = solu.addTwoNumbers(listA, listB);
    for(ListNode* p = result; p != nullptr; p = p->next) {
        cout << p->val << ' ';
    }


    ListNode* current = result;
    while (current != nullptr) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    delete nodeb1, nodeb2, node3, listA, listB, node2;
    return 0;
}