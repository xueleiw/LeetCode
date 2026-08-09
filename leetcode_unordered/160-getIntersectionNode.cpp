#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
// 8-12
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode*> st;
//         while(headA != nullptr) {
//             st.insert(headA);
//             headA = headA->next;
//         }
//         while(headB != nullptr) {
//             if(st.count(headB)) {
//                 return headB;
//             }
//             headB = headB->next;
//         }

//         return nullptr;
//     }
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* next = nullptr;
//         while(head != nullptr) {
//             next = head->next;
//             head->next = prev;
//             prev = head;
//             head = next;
//         }
//         return prev;
//     }
// };

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // 0价值最少个数是0个
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};


int main() {

    return 0;
}