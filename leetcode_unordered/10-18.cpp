#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;


// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         Node* dummy = new Node(-1);
//         Node* q = dummy;
//         Node* p = head;
//         unordered_map<Node*, Node*> mp; // A  B

//         while(p != NULL) {
//             Node* tmp = new Node(p->val);
//             mp[p] = tmp;
//             q->next = tmp;
//             q = q->next;
//             p = p->next;
//         }
//         p = head;
//         while(p != NULL) {
//             if(p->random != NULL) {
//                 Node* tmp = mp[p];
//                 Node* randp = mp[p->random];
//                 tmp->random = randp;
//             }
//             p = p->next;
//         }

//         Node* res = dummy->next;
//         delete dummy;
//         return res;
//     }
// };

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//     class cmp {
//         public:
//             bool operator() (ListNode* x, ListNode* y) {
//                 return x->val > y->val; 
//             }
//     };

//     ListNode* sortList(ListNode* head) {
//         priority_queue<ListNode*, vector<ListNode*>, cmp> q;
//         ListNode* p = head;
//         while(p != nullptr) {
//             ListNode* tmp = p;
//             tmp->next = nullptr;
//             p = p->next;
//             q.push(tmp);
//         }

//         ListNode* dummy = new ListNode(-1);
//         head = dummy;
//         while(!q.empty()) {
//             ListNode* t = q.top();
//             q.pop();
//             head->next = t;
//             head = head->next;
//         }
//         head = dummy->next;
//         delete dummy;
//         return head;
//     }
// };

// class Solution {
// public:
//     ListNode* rev(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* next = nullptr;
//         ListNode* tmp = nullptr;
//         while(head != nullptr) {
//             next = head->next;
//             head->next = prev;
//             prev = head;
//             head = next;
//         }

//         return prev;
//     }

//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* next = head;
//         ListNode* dummy = new ListNode(-1);
//         dummy->next = head;
//         ListNode* prev = dummy;
//         int len = 0;

//         while(len < k && next != nullptr) {
//             len++;
//             prev = next;
//             next = next->next;
//         }
//         if(len < k) return head;

//         prev->next = nullptr;
//         ListNode* tail = reverseKGroup(next, k);
//         ListNode* new_head = rev(head);
//         head->next = tail;

//         // head = dummy->next;
//         delete dummy;
//         return new_head;
//     }
// };

// struct Node {
//     Node* prev;
//     Node* next;
//     int val;
//     int key;
//     Node(int x): val(x){
//         next = nullptr;
//         prev = nullptr;
//     }
// };

// class LRUCache {
// private:    
//     int cap;
//     int size;
//     unordered_map<int, Node*> mp;
//     Node* head;
//     Node* tail;

// public:
//     LRUCache(int capacity) {
//         cap = capacity;
//         size = 0;
//         head = new Node(-1);
//         tail = new Node(-1);
//         head->next = tail;
//         tail->prev = head;
//     }

//     void move_head(Node* p) {
//         Node* prev = p->prev;
//         Node* next = p->next;
//         prev->next = next;
//         next->prev = prev;
//         //
//         next = head->next;
//         head->next = p;
//         p->prev = head;
//         p->next = next;
//         next->prev = p;
//     }

//     void move_(Node* p) {
//         Node* next = head->next;
//         head->next = p;
//         p->prev = head;
//         p->next = next;
//         next->prev = p;
//     }

//     int get(int key) {
//         if(mp.count(key)) {
//             int res = mp[key]->val;
//             move_head(mp[key]);
//             return res;
//         } else {
//             return -1;
//         }
//     }
    
//     void delete_tail() {
//         Node* cur = tail->prev;
//         Node* prev = cur->prev;
//         prev->next = tail;
//         tail->prev = prev;
//         mp.erase(cur->key);
//         delete cur;
//     }

//     void put(int key, int value) {
//         if(mp.count(key)) {
//             mp[key]->val = value;
//             move_head(mp[key]);
//         } else {
//             if(size < cap) {
//                 Node* tmp = new Node(value);
//                 tmp->key = key;
//                 mp[key] = tmp;
//                 move_(tmp);
//                 size++;
//             } else {
//                 delete_tail();
//                 Node* tmp = new Node(value);
//                 tmp->key = key;
//                 mp[key] = tmp;
//                 move_(tmp);
//             }
//         }
//     }
// };

// class Solution {
// public:
//     int findLonelyPixel(vector<vector<char>>& picture) {
//         int m = picture.size();
//         int n = picture[0].size();
//         vector<int> row(m, 0);
//         vector<int> col(n, 0);

//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(picture[i][j] == 'B') {
//                     row[i]++;
//                     col[j]++;
//                 }
//             }
//         }

//         int res = 0;
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(picture[i][j] == 'B') {
//                     if(row[i] == 1 && col[j] == 1) {
//                         res++;
//                     }
//                 }
//             }
//         }
//         return res;

//     }
// };

// class Solution {
// public:
//     string addStrings(string num1, string num2) {
//         string res = "";
//         int i = num1.length() - 1;
//         int j = num2.length() - 1;

//         int p = 0;
//         while(i >= 0 && j >= 0) {
//             int a = num1[i] - '0';
//             int b = num2[j] - '0';
//             int x = (a + b + p) % 10;
//             p = (a + b + p) / 10;
//             res.push_back(x + '0');
//             i--;j--;
//         }
//         while(i >= 0) {
//             int a = num1[i] - '0';
//             int x = (a + p) % 10;
//             p = (a + p) / 10;
//             res.push_back(x +'0');
//             i--;
//         }
//         while(j >= 0) {
//             int a = num2[j] - '0';
//             int x = (a + p) % 10;
//             p = (a + p) / 10;
//             res.push_back(x +'0');
//             j--;
//         }
//         if(p != 0) {
//             res.push_back(p +'0');
//         }
        
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };

// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         vector<int> a;
//         ListNode* p = head;
//         while(p != nullptr) {
//             a.push_back(p->val);
//             p = p->next;
//         }

//         k = k % a.size();
//         p = head;
//         int i = a.size() - 2;
//         while(p != nullptr) {
//             p->val = a[i];
//             i = (i + 1) % a.size();
//             p = p->next;
//         }
        
//         return head;
//     }
// };

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n + 1, 0);
//         if(n == 1) return nums[0];

//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
//         for(int i = 2; i < n; i++) {
//             dp[i] = max(dp[i - 1], dp[i - 1] + nums[i]);
//         }

//         return dp[n - 1];
//     }
// };

// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> dp(n + 1, INT_MAX);
//         dp[0] = 0;

//         for(int i = 1; i <= n; i++) {
//             for(int j = 1; j * j <= i; j++) {
//                 if(dp[i - j * j] != INT_MAX) {
//                     dp[i] = min(dp[i], dp[i - j * j] + 1);
//                 }
//             }
//         }

//         return dp[n];
//     }
// };

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount + 1, INT_MAX);
//         dp[0] = 0;

//         for(int i = 1; i <= amount; i++) {
//             for(int j = 0; j < coins.size(); j++) {
//                 if(i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
//                     dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//                 }
//             }
//         }

//         return dp[amount] == INT_MAX ? -1 : dp[amount]; 
//     }
// };

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         vector<bool> dp(s.length() + 1, false);
//         dp[0] = true;
//         unordered_set<string> st(wordDict.begin(), wordDict.end());

//         for(int i = 1; i <= s.length(); i++) {
//             for(int j = 0; j < wordDict.size(); j++) {
//                 if(i >= wordDict[j].length()) {
//                     string tmp = s.substr(i - wordDict[j].length(), wordDict[j].length());
//                     if(st.count(tmp) && dp[i - wordDict[j].length()]){
//                         dp[i] = true;
//                     }
//                 }
//             }
//         }

//         return dp[s.length()];
//     }
// };

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n + 1, 1);
//         int res = 1;

//         for(int i = 1; i <= n; i++) {
//             for(int j = 1; j <= i; j++) {
//                 if(nums[i - 1] > nums[j - 1]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//             res = max(res, dp[i]);
//         }

//         return res;
//     }
// };