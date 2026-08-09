#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// 5-15

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
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
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode*> st;
//         ListNode* p = headA;
//         while(p != nullptr) {
//             st.insert(p);
//             p = p->next;
//         }
//         p = headB;
//         while(p != nullptr) {
//             if(st.count(p)) {
//                 return p;
//             }
//             p = p->next;
//         }
//         return nullptr;
//     }
// };

// class Solution {
// public:
//     ListNode* reverse(ListNode* root) {
//         ListNode* prev = nullptr;
//         ListNode* t = nullptr;
//         while(root != nullptr) {
//             t = root->next;
//             root->next = prev;
//             prev = root;
//             root = t;
//         }
//         return prev;
//     }

//     ListNode* reverseList(ListNode* head) {
//         ListNode* res = reverse(head);
//         return res;
//     }
// };

// 将链表的后半部分反转，然后使用双指针进行判断，这样空间复杂度就是O(1)
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int> s;
//         ListNode* p = head;
//         while(p != nullptr) {
//             s.push_back(p->val);
//             p = p->next;
//         }
//         vector<int> t = s;
//         reverse(t.begin(), t.end());
//         if(s == t) return true;
//         return false;
//     }
// };

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if(head == nullptr || head->next == nullptr) return false;
//         ListNode* s = head;
//         ListNode* t = head->next;
//         while(t->next != nullptr) {
//             if(s == t) return true;
//             s = s->next;
//             t = t->next->next;
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         if(head == nullptr || head->next == nullptr) return nullptr;
//         ListNode* s = head;
//         ListNode* f = head;

//         while(f != nullptr) {
//             if(f ->next != nullptr && f->next->next != nullptr) {
//                 f = f->next->next;
//             } else {
//                 return nullptr;
//             }
//             s = s->next;
//             if(s == f)break;
//         }
//         // cout << s->val << ' ' << f->val;
//         // if(s != f) return nullptr;
//         ListNode* p = head;
//         while(p != s) {
//             p = p->next;
//             s = s->next;
//         }
//         return p;
//     }
// };

// class Solution {
// public:
//     ListNode* merge(ListNode* l1, ListNode* l2) {
//         ListNode* p = l1;
//         ListNode* q = l2;
//         ListNode* dummy = new ListNode(-1);
//         ListNode* tmp = dummy;

//         while(p != nullptr && q != nullptr) {
//             if(p->val <= q->val) {
//                 tmp->next = p;
//                 p = p->next;
//             } else {
//                 tmp->next = q;
//                 q = q->next;
//             }
//             tmp = tmp->next;
//         }
//         if(p != nullptr) {
//             tmp->next = p;
//         }
//         if(q != nullptr) {
//             tmp->next = q;
//         }
//         p = dummy->next;
//         delete dummy;
//         return p;
//     }

//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == nullptr) return list2;
//         if(list2 == nullptr) return list1;

//         ListNode* res = merge(list1, list2);
//         return res;
//     }
// };

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         if(l1 == nullptr) return l2;
//         if(l2 == nullptr) return l1;

//         ListNode* p = l1;
//         ListNode* q = l2;
//         ListNode* dummy = new ListNode(-1);
//         ListNode* t = dummy;
//         int plus = 0;
//         while( p != nullptr && q != nullptr) {
//             int sum = p->val + q->val + plus;
//             plus = sum / 10;
//             p->val = sum % 10;
//             t->next = p;
//             t = t->next;
//             p = p->next;
//             q = q->next;
//         }
//         if(p != nullptr) {
//             while(p) {
//                 int sum = p->val + plus;
//                 plus = sum / 10;
//                 p->val = sum % 10;
//                 t->next = p;
//                 t = t->next;
//                 p = p->next;
//             }
//         }
//         if(q != nullptr) {
//             while(q) {
//                 int sum = q->val + plus;
//                 plus = sum / 10;
//                 q->val = sum % 10;
//                 t->next = q;
//                 t = t->next;
//                 q = q->next;
//             }
//         }
//         if(plus == 1) {
//             t->next = new ListNode(1);
//         }
//         p = dummy->next;
//         delete dummy;
//         return p;
//     }
// };

// 使用双指针，快指针比慢指针提前走n个位置，这样当快节点到空的时候慢节点就会指向删除的前节点
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int len = 0;
//         ListNode* p = head;
//         while(p != nullptr) {
//             len++;
//             p = p->next;
//         }
//         ListNode* dummy = new ListNode(-1);
//         dummy->next = head;
//         p = dummy;
//         int count = 0;
//         while(count < len - n) {
//             count++;
//             p = p->next;
//         }
//         ListNode* t = p->next;
//         p->next = p->next->next;
//         delete t;
//         p = dummy->next;
//         delete dummy;
//         return p;
//     }
// };

// 模拟也还行，递归更好写
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(head == nullptr || head->next == nullptr) return head;

//         ListNode* res = head->next->next;
//         // head->next->next = nullptr;
//         ListNode* ne = head->next;
//         ne->next = head;
//         head->next = swapPairs(res);
//         return ne;
//     }
// };

// class Solution {
// public:
//     ListNode* re(ListNode* root) {
//         ListNode* prev = nullptr;
//         ListNode* t = nullptr;
//         while(root != nullptr) {
//             t = root->next;
//             root->next = prev;
//             prev = root;
//             root = t;
//         }
//         return prev;
//     }

//     ListNode* reverseKGroup(ListNode* head, int k) {
//         int len = 0;
//         ListNode* p = head;
//         ListNode* prev = nullptr;
//         while(p != nullptr && len < k) {
//             len++;
//             prev = p;
//             p = p->next;
//         }
//         if(len < k) {
//             return head;
//         }

//         prev->next = nullptr;
//         ListNode* new_head = re(head);
//         head->next = reverseKGroup(p, k);
//         return new_head;
//     }
// };

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
//         unordered_map<Node*, Node*> mp;
//         Node* dummy = new Node(-1);
//         Node* p = dummy;
//         Node* q = head;
//         while(q != nullptr) {
//             Node* tmp = new Node(q->val);
//             p->next = tmp;
            
//             p = p->next;
//             mp[q] = tmp; // 指向新节点
//             q = q->next;
//         }
//         //
//         for(auto &x: mp) {
//             Node* first = x.first;
//             Node* second = x.second;
//             if(first->random == NULL) {

//             } else {
//                 Node* tmp = first->random;
//                 second->random = mp[tmp];
//             }
//         }
//         p = dummy->next;
//         delete dummy;
//         return p;
//     }
// };

// class cmp {
//     public:
//         bool operator() (ListNode* a, ListNode* b) {
//             return a->val > b->val;
//         }
// };
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if(head == nullptr || head->next == nullptr) return head;
//         priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
//         ListNode* p = head;
//         while(p != nullptr) {
//             pq.push(p);
//             p = p->next;
//         }
//         p = pq.top();
//         head = p;
//         pq.pop();
//         p->next = nullptr;
//         while(!pq.empty()) {
//             cout << p->val << ' ';
//             ListNode* tmp = pq.top();
//             tmp->next = nullptr;  // 别让新节点乱指
//             pq.pop();
//             p->next = tmp;
//             p = p->next;
//         }
//         return head;
//     }
// };

// 5-16
// class cmp {
//     public:
//         bool operator() (ListNode* a, ListNode* b) {
//             return a->val > b->val; 
//         }
// };
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode*, vector<ListNode*>, cmp> q;
//         for(int i = 0; i < lists.size(); i++) {
//             ListNode* p = lists[i];
//             while(p != nullptr) {
//                 q.push(p);
//                 p = p->next;
//             }
//         }
//         ListNode* dummy = new ListNode(-1);
//         ListNode* p = dummy;
//         while(!q.empty()) {
//             ListNode* tmp = q.top();
//             q.pop();
//             tmp->next = nullptr;
//             p->next = tmp;
//             p = p->next;
//         }
//         p->next = nullptr;
//         p = dummy->next;
//         delete dummy;
//         return p;
//     }
// };

// struct Node {
//     Node* prev;
//     Node* next;
//     int k;
//     int v;
//     Node(int key, int value): k(key), v(value) {
//         prev = nullptr;
//         next = nullptr;
//     }
// };
// // get 和 put 必须以 O(1) 的平均时间复杂度运行。
// class LRUCache {
// private:
//     unordered_map<int, Node*> mp;
//     Node* head;
//     Node* tail;
//     int cap;
//     int size;
// public:
//     LRUCache(int capacity) {
//         cap = capacity;
//         size = 0;
//         head = new Node(-1, -1);
//         tail = new Node(-1, -1);
//         mp.clear();
//         head->next = tail;
//         tail->prev = head;
//     }

//     void move_head(Node* p) {
//         Node* prev = p->prev;
//         prev->next = p->next;
//         p->next->prev = prev;
//         //
//         Node* back = head->next;
//         back->prev = p;
//         p->next = back;
//         p->prev = head;
//         head->next = p;
//     }
    
//     int get(int key) {// 代表一次访问
//         if(mp.count(key)) {
//             Node* p = mp[key];
//             move_head(p);
//             return p->v;
//         } else {
//             return -1;
//         }
//     }

//     void insert(Node* p) {
//         // 头插法
//         Node* back = head->next;
//         back->prev = p;
//         p->next = back;
//         p->prev = head;
//         head->next = p;
//     }

//     void del() {
//         // 哈希表和链表都要删
//         Node* prev = tail->prev;
//         tail->prev = prev->prev;
//         prev->prev->next = tail;
//         //
//         int k = prev->k;
//         mp.erase(k);
//         delete prev;
//     }
    
//     void put(int key, int value) {  
//         if(mp.count(key)) {
//             Node* p = mp[key];
//             p->v = value;
//             move_head(p);
//         } else {
//             if(size < cap) {
//                 size++;
//                 Node* p = new Node(key, value);
//                 mp[key] = p;
//                 insert(p);
//             } else {
//                 // 删一个再插入
//                 Node* p = new Node(key, value);
//                 mp[key] = p;
//                 insert(p);
//                 del();
//             }
//         }
//     }
// };