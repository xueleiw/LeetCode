#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 9-2

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// [7,7,7,7]
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dumm = new ListNode(-1);
        dumm->next = head;
        ListNode* prev = dumm;
        ListNode* tmp = head;
        while(tmp != nullptr) {
            if(tmp->val == val) {
                ListNode* cur_next = tmp->next;
                prev->next = cur_next;
                delete tmp;
                tmp = cur_next;     
                continue;
            } else {
                prev = tmp;
                tmp = tmp->next;
            }
        }

        head = dumm->next;
        delete dumm;
        return head;
    }
};


int main() {
    queue<int> q;
    

    return 0;
}
