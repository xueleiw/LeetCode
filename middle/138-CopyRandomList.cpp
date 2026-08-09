/**
 * 2025-1-6
 * 1-: 首先不考虑随机指针深拷贝原链表 --> new 方法； 
 *     然后通过pair<node*, index> 映射随机指针和指向节点的索引；通过两层循环遍历新链表复现该映射即可
 */

#include<iostream>
#include<vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};



/*=================1-: 11ms=============================*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return nullptr;
        }

        vector<pair<Node*, int>> node_map;
        Node* p = head;
        Node* q = head;
        Node* res = new Node(0); // new
        Node* res_next = res;
        int index = 0;
        int len = 0;
        for(p; p != nullptr; p = p->next) {
            Node* tmp = new Node(p->val);
            res_next->next = tmp;
            res_next = res_next->next;
        }
        res = res->next; // 复制的链表头结点
        index = 0;
        p = head;
        for(p; p != nullptr; p = p->next) {
            for(q; q != nullptr; q = q->next) {
                index++; // 从1开始
                if(p->random == nullptr || p->random == q) {
                    node_map.push_back(pair<Node*, int>(p->random, len)); // 记录random指针和索引index的映射
                }
            }
        }

        p = res;
        q = res;
        index = 0;
        for(p; p != nullptr; p = p->next) {
            int j = 0;
            pair<Node*, int> tmp = node_map[index];
            index++;
            if(tmp.first == nullptr) {
                p->random = nullptr;
                continue;
            }
            for(q; q != nullptr; q = q->next) {
                if(j + 1 == tmp.second) {
                    p->random = q;
                    break;
                }
                j++;
            }
        } 

        return res;
    }
};

int main() {
    Solution solu;
    return 0;
}