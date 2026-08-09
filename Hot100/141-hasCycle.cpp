#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// 4-18
// 快慢指针判断链表是否有环

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if(head == nullptr || head->next == nullptr) {
                return false;
            }
            ListNode *slow = head;
            ListNode *fast = head->next;

            while(slow != fast) {
                if(fast == nullptr || fast->next == nullptr) {
                    return false;
                }
                slow = slow->next;
                fast = fast->next->next;
            }

            return true;
        }
    };
