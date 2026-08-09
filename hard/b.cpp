#include <iostream>
#include <vector>

using namespace std;
// 9-8
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* tmp = head;
//         ListNode* next = nullptr;
//         while(tmp != nullptr) {
//             next = tmp->next;
//             tmp->next = prev;
//             prev = tmp;
//             tmp = next;
//         }

//         return prev;
//     }
// };



class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head; // one or zero
        }

        ListNode* head_next = head->next;
        ListNode* tmp = head->next->next;
        head_next->next = head;
        head->next = swapPairs(tmp);
        return head_next;
    }
};

int main() {


    return 0;
}
