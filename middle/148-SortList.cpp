/**
 * 2025-1-7
 * 2025-3-21
 * 1-： 及时终止的冒泡排序 O(n^2)
 * 2-:  使用小根堆存储每个节点，然后从堆中拿出节点进行顺序连接即可-O(nlogn)
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*==========及时终止的冒泡排序也是n^2 的复杂度，依然会超时=======================*/
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if(head == nullptr) {
//             return nullptr;
//         }

//         ListNode* p1 = head;
//         ListNode* prev = nullptr;
//         int len = 0;
//         for(p1; p1 != nullptr; p1 = p1->next) {
//             len++; // 链表长度
//         }

//         ListNode* new_head = new ListNode(-1); // 伪造一个假的链表头--以固定不变
        
//         new_head->next = head;
//         for(int i = 0; i < len; i++) {
//             p1 = new_head->next; 
//             prev = new_head;   // 记录前节点，以便交换后面的节点
//             int flag_stop = len - i;
//             while(p1->next != nullptr && flag_stop > 0) {
//                 if(p1->val > p1->next->val) {
//                     ListNode* back = p1->next->next; // 交换的两个节点后面的节点
//                     prev->next = p1->next;
//                     p1->next->next = p1;
//                     p1->next = back;
//                     prev = prev->next;
//                 } else {
//                     p1 = p1->next;
//                     prev = prev->next;
//                 }
//                 flag_stop--;
//             }
//         }

//         return new_head->next;
//     }
// };

// 2025-3-21
/*===============2-: 37ms=====================*/
class Solution {
    public:
        struct Compare {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };

        ListNode* sortList(ListNode* head) {
            if(head == nullptr) {
                return nullptr;
            }

            ListNode* p = head;
            ListNode* q = head;
            priority_queue<ListNode*, vector<ListNode*>, Compare> queue;
            while(p != nullptr) {
                queue.push(p);
                p = p->next;
            }

            ListNode* tmp = queue.top();
            queue.pop();
            head = tmp;
            p = head;
            p->next = nullptr;
            while(!queue.empty()) {
                tmp = queue.top();
                p->next = tmp;
                tmp->next = nullptr;
                p = tmp;
            }

            return head;
        }
    };

int main() {

    return 0;
}
