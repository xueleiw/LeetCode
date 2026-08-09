/**
 * 2024-12-21
 * 1-不要想太多，根据长度折半对比是否相等即可
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
    bool isPalindrome(ListNode* head) {
        vector<int> A;
        int length = 0;
        for(ListNode* p = head; p != nullptr; p = p->next) {
            A.push_back(p->val);
            length++;
        }
        for(int i = 0; i < length / 2; i++){
            if(A[i] != A[length - i - 1]) return false;
        }

        return true;
    }
};

int main() {

    return 0;
}