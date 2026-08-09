/**
 * 2024-12-21
 * 1-一直遍历，如果存在环那么遍历的次数会大于最大的节点数，由此可作判断
 * 2-通过map映射，查看当前节点是否被访问过，如果有那么一定存在环
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

// 1: 13ms
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         int length = 0;
//         for(ListNode* p = head; p != nullptr; p = p->next) {
//             length++;
//             if(length > 1e4 + 10) return true;
//         }
//         return false;
//     }
// };

//2: 23ms
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> A;
        for(ListNode* p = head; p != nullptr; p = p->next) {
            if(A.count(p) != 0) return true;
            A.insert(pair<ListNode*, bool>(p, true));
        }
        return false;
    }
};

int main() {

    return 0;
}