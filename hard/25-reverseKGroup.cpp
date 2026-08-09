
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// 4-21
// 0ms
// 思路就是把每个区间分割开来，存在vector里面，每个区间分别逆转之后接在一起，最后把剩下的不足k的部分接起来

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* reverse(ListNode* head) {
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

        ListNode* reverseKGroup(ListNode* head, int k) {
            if(k == 1 || head->next == nullptr) return head;
            int n = 0;
            for(ListNode* p = head; p != nullptr; p = p->next) {
                n++;
            }

            vector<pair<ListNode*, ListNode*>> s;
            ListNode* cur = head;
            while(n - k >= 0) { // 如果能够翻转
                int count = 1;
                for(cur; cur != nullptr; cur = cur->next) {
                    if(count == k) {
                        s.push_back(pair<ListNode*, ListNode*>(head, cur));
                        head = cur->next;
                        cur->next = nullptr;
                        cur = head;
                        break;
                    }
                    count++;
                }
                n -= k;
            }
            //此时 head指向最后不足k个的链表头，或者是空
            vector<ListNode*> _s;
            for(int i = 0; i < s.size(); i++) {
                ListNode* _tmp = s[i].first;
                // while(_tmp != nullptr) {
                //     cout << _tmp->val << ' ';
                //     _tmp = _tmp->next;
                // }cout << endl;
                ListNode* tmp = reverse(s[i].first);
                // cout <<s[i].first->val << " " << tmp->val << " s " << endl;
                _s.push_back(tmp);
            }
            // cout << _s.size() << endl;

            ListNode* new_head = _s[0];
            ListNode* tmp = new_head;
            for(int i = 1; i < _s.size(); i++) {
                while(tmp->next != nullptr) {
                    tmp = tmp->next;
                }
                tmp->next = _s[i];
                tmp = _s[i];
            }
            while(tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = head;


            return new_head;
        }
    };