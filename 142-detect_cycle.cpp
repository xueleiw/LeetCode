/**
 * 2024-12-22
 * 1-按照之前检测环的方法，判断一个节点是否遍历了两次，然后返回节点即可；但是需要用到Map，查找可能比较耗时
 * 2-一次遍历，每次把节点的值修改为最大值，如果当前节点的值是最大值的话那么该节点便是循环的头节点
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

/*===== 1-: 12ms =====*/ 
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         map<ListNode*, int> A;
//         for(ListNode* p = head; p != nullptr; p = p->next) {
//             if(A.count(p) != 0) {
//                 return p;
//             }
//             A.insert(pair<ListNode*, int>(p, 0));
//         }
//         return nullptr;
//     }
// };

/*===== 1-: 8ms =====*/ 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        for(ListNode* p = head; p != nullptr; p = p->next) {
            if(p->val == INT_MAX) {
                return p;
            }
            p->val = INT_MAX;
        }
        return nullptr;
    }
};

int main() {



    return 0;
}
