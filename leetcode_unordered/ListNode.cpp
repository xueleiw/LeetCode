#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <array>
#include <queue>
using namespace std;
// 5-3

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

// 51ms
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode*> st;
//         ListNode* res = nullptr;
//         ListNode* pa = headA;
//         ListNode* pb = headB;
//         while(pa != nullptr) {
//             st.insert(pa);
//             pa = pa->next;
//         }
//         while(pb != nullptr) {
//             if(st.count(pb)) {
//                 res = pb;
//                 break;
//             } else {
//                 pb = pb->next;
//             }
//         }
//         return res;
//     }
// };


// class Solution {
//     public:
//         ListNode* reverse(ListNode* root) {
//             ListNode* prev = nullptr;
//             ListNode* tmp = nullptr;
//             while(root != nullptr) {
//                 tmp = root->next;
//                 root->next = prev;
//                 prev = root;
//                 root = tmp;
//             }
//             return prev;
//         }
//         ListNode* reverseList(ListNode* head) {
//             return reverse(head);
//         }
//     };

// 不使用额外空间的方法是把链表从中间分开，反转后半部分，然后进行比较
// class Solution {
//     public:
//         ListNode* reverse(ListNode* root) {
//             ListNode* prev = nullptr;
//             ListNode* tmp = nullptr;
//             while(root != nullptr) {
//                 tmp = root->next;
//                 root->next = prev;
//                 prev = root;
//                 root = tmp;
//             }
//             return prev;
//         }
//         bool isPalindrome(ListNode* head) {
//             vector<int> s;
//             ListNode* p = head;
//             while(p != nullptr) {
//                 s.push_back(p->val);
//                 p = p->next;
//             }
//             p = head;
//             ListNode* tmp = reverse(p);
//             int i = 0;
//             while(tmp != nullptr) {
//                 if(s[i] != tmp->val) {
//                     return false;
//                 }
//                 i++;
//                 tmp = tmp->next;
//             }

//             return true;
//         }
//     };

// 22ms
// class Solution {
//     public:
//         bool hasCycle(ListNode *head) {
//             ListNode* p = head;
//             unordered_set<ListNode*> s;
//             while(p != nullptr) {
//                 if(s.count(p)) {
//                     return true;
//                 }
//                 s.insert(p);
//                 p = p->next;
//             }

//             return false;
//         }
//     };
// 快慢指针，无需额外空间
// class Solution {
//     public:
//         bool hasCycle(ListNode *head) {
//             ListNode* s = head;
//             ListNode* f = nullptr;
//             if(head != nullptr && head->next != nullptr) {
//                 f = head->next;
//             } else {
//                 return false;
//             }

//             while(s != f) {
//                 s = s->next;
//                 if(f->next != nullptr && f->next->next != nullptr) {
//                     f = f->next->next;
//                 } else {
//                     return false;
//                 }
//             }

//             return true;
//         }
//     };


// class Solution {
//     public:
//         ListNode *detectCycle(ListNode *head) {
//             ListNode* s = head;
//             ListNode* f = head;
//             if(head != nullptr) {
//                 // f = head->next;
//             } else {
//                 return nullptr;
//             }

            
//             while(f != nullptr) {
//                 if(f->next != nullptr && f->next->next != nullptr) {
//                     f = f->next->next;
//                 } else {
//                     return nullptr;
//                 }
//                 s = s->next;

//                 if(s == f) break;
                
//             }
//             ListNode* p = head;
//             if(s == f) {
//                 // cout << s->val << " e " << endl;
                
//                 while(p != s) {
//                     p = p->next;
//                     s = s->next;
//                 }
//             }
            

//             return p;
//         }
//     };

// 5-4
// class Solution {
//     public:
//         ListNode* removeNthFromEnd(ListNode* head, int n) {
//             ListNode* p = head;
//             int len = 0;
//             while(p != nullptr) {
//                 len++;
//                 p = p->next;
//             }

//             p = head;
//             int k = len - n + 1; // 相当于删除正数第k个
//             // if(k == 1) {
//             //     return head->next;
//             // }
//             ListNode* prev = nullptr; // 前节点
//             for(int i = 1; i < k; i++) {
//                 prev = p;
//                 p = p->next;
//             }
//             // delete p
//             if(p == head) {
//                 return p->next;
//             } else {
//                 prev->next = p->next;
//             }
//             return head;
//         }
//     };
// 双指针，更优 通过假的头结点保证快慢指针之间相差n个节点，当快指针为空的时候，慢指针的下一个节点就是要删除的节点
// class Solution {
//     public:
//         ListNode* removeNthFromEnd(ListNode* head, int n) {
//             ListNode* dummy = new ListNode(0, head);
//             ListNode* fast = head;
//             ListNode* slow = dummy;
//             for(int i = 0; i < n; i++) {
//                 fast = fast->next;
//             }
//             while(fast != nullptr) {
//                 fast = fast->next;
//                 slow = slow->next;
//             }
//             slow->next = slow->next->next;
//             head = dummy->next;
//             delete dummy;
//             return head;
//         }
//     };

// 5-4  自创：使用两个队列进行交替链接
// class Solution {
//     public:
//         ListNode* swapPairs(ListNode* head) {
//             if(head == nullptr || head->next == nullptr) return head;
//             queue<ListNode*> first, second;
//             ListNode* p = head;
//             int i = 1;

//             while(p != nullptr) {
//                 if(i % 2 == 1) {
//                     first.push(p);
//                 } else {
//                     second.push(p);
//                 }
//                 p = p->next;
//                 i++;
//             }
            
//             ListNode* ans = second.front();
//             ListNode* tmp = ans;
//             second.pop();
//             while(!first.empty() && !second.empty()) {
//                 ListNode* h = second.front();
//                 ListNode* t = first.front();
//                 tmp->next = t;
//                 t->next = h;
//                 tmp = h;
//                 first.pop();
//                 second.pop();
//             }
//             while(!first.empty()) {
//                 ListNode* x = first.front();
//                 tmp->next = x;
//                 x->next = nullptr;
//                 tmp = x;
//                 first.pop();
//             }
            
//             return ans;
//         }
//     };
// 递归方法解决，很妙
// class Solution {
//     public:
//         ListNode* swapPairs(ListNode* head) {
//             if(head == nullptr && head->next == nullptr) {
//                 return head; // 保证能有2个节点
//             }
//             ListNode* new_head = head->next;
//             head->next = swapPairs(new_head->next);
//             new_head->next = head;
//             return new_head;
//         }
//     };

// 使用递归的思想
// class Solution {

//     public:
//         ListNode* reverse(ListNode* root) {
//             ListNode* prev = nullptr;
//             ListNode* tmp = nullptr;
//             while(root != nullptr) {
//                 tmp = root->next;
//                 root->next = prev;
//                 prev = root;
//                 root = tmp;
//             }
//             return prev;
//         }

//         ListNode* reverseKGroup(ListNode* head, int k) {
//             ListNode* dummy = new ListNode(0, head);
//             ListNode* p = dummy;
//             int count = 0;
//             while(count < k && p != nullptr) {
//                 if(p->next == nullptr) break; // p 不能指向空     
//                 count++;
//                 p = p->next;
//             }
//             delete dummy;
//             if(count < k) return head;
//             ListNode* back = p->next;
//             p->next = nullptr;
//             ListNode* new_head = head;
//             ListNode* res = reverse(new_head);
            
//             head->next = reverseKGroup(back, k);
//             return res;
//         }
//     };

// 4ms
// class Node {
//     public:
//         int val;
//         Node* next;
//         Node* random;
        
//         Node(int _val) {
//             val = _val;
//             next = NULL;
//             random = NULL;
//         }
//     };
// class Solution {
//     public:
//         Node* copyRandomList(Node* head) {
//             Node* dummy = new Node(0);
//             unordered_map<Node*, Node*> mp;
//             Node* p =dummy;
//             Node* q = head;
//             while(q != nullptr) {
//                 Node* tmp = new Node(q->val);
//                 mp[q] = tmp;
//                 p->next = tmp;
//                 p = p->next;
//                 q = q->next;
//             }

//             q = head;
//             p = dummy->next;
//             while(q != nullptr) {
//                 if(q->random == nullptr) {
//                     //
//                 } else {
//                     Node* tmp = q->random;
//                     p->random = mp[tmp];
//                 }
//                 p = p->next;
//                 q = q->next;
//             }

//             p = dummy->next;
//             delete dummy;
//             return p;
//         }
//     };


// 39ms
// class cmp {
//     bool operator()(ListNode* a, ListNode* b) {
//         return a->val > b->val;
//     }
// };
// class Solution {
//     public:
//         ListNode* sortList(ListNode* head) {
//             if(head == nullptr) return head;
//             priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
//             ListNode* p = head;
//             while(p != nullptr) {
//                 pq.push(p);
//                 p = p->next;
//             }

//             ListNode* new_head = pq.top();
//             pq.pop();
//             p = new_head;
//             while(!pq.empty()) {
//                 p->next = pq.top();
//                 pq.pop();
//                 p = p->next;
//             }
//             p->next = nullptr;  // 链表的最后一定是空

//             return new_head;
//         }
//     };


// 76ms 1-删除链表的同时也要删除哈希表；get方法访问之后也要移动到头部。
// struct Node {
//     Node* prev;
//     Node* next;
//     int val;
//     int key;
//     Node (int x, int y): key(x), val(y), prev(nullptr), next(nullptr) {}
// };
// class LRUCache {
//     private:
//         Node* head;
//         Node* tail;
//         unordered_map<int, Node*> mp;
//         int cap;
//         int size;
//     public:
//         LRUCache(int capacity) {
//             cap = capacity;
//             size = 0;
//             head = new Node(-1, -1);
//             tail = new Node(-1, -1);
//             head->next = tail;
//             tail->prev = head;
//         }
        
//         int get(int key) {
//             if(mp.count(key)) {
//                 Node* tmp = mp[key];
//                 move(tmp);
//                 return tmp->val;
//             } else {
//                 return -1;
//             }
//         }

//         void move(Node* x) {
//             Node* prev = x->prev;
//             Node* back = x->next;
//             prev->next = back;
//             back->prev = prev;
//             move_head(x);
//         }

//         void move_head(Node* x) {
//             Node* tmp = head->next;
//             head->next = x;
//             x->prev = head;
//             x->next = tmp;
//             tmp->prev = x;
//         }

//         void del() {
//             Node* de = tail->prev;
//             Node* tmp = de->prev;
//             mp.erase(de->key);
//             delete de;
//             tmp->next = tail;
//             tail->prev = tmp;
//             // 链表删除之后mp也得删
//         }
        
//         void put(int key, int value) {
//             if(mp.count(key)) {
//                 mp[key]->val = value; // move
//                 Node* tmp = mp[key];
//                 move(tmp);
//             } else {
//                 if(size < cap) {
//                     size++;
//                     Node* x = new Node(key, value);
//                     mp[key] = x;
//                     move_head(x);
//                 } else {
//                     del();
//                     mp.erase(key);
//                     Node* x = new Node(key, value);
//                     mp[key] = x;
//                     move_head(x);
//                 }
//             }
//         }
//     };


class cmp {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
};
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
            for(int i = 0; i < lists.size(); i++) {
                ListNode* tmp = lists[i];
                while(tmp != nullptr) {
                    pq.push(tmp);
                    tmp = tmp->next;
                }
            }

            ListNode* dummy = new ListNode(-1);
            ListNode* ans = dummy;
            while(!pq.empty()) {
                ans->next = pq.top();
                pq.pop();
                ans = ans->next;
            }
            ans->next = nullptr;  // ##########链表尾节点一定是空#############################
            ans = dummy->next;
            return ans;
        }
    };