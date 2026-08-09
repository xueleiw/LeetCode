#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// 5-8

// 8ms 
class Node {
    public:
        int val;
        Node* next;
    
        Node() {}
    
        Node(int _val) {
            val = _val;
            next = NULL;
        }
    
        Node(int _val, Node* _next) {
            val = _val;
            next = _next;
        }
    };
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == nullptr) {
            Node* res = new Node(insertVal, nullptr);
            res->next = res;
            return res;
        }
        vector<int> s;

        Node* tmp = head;
        while(1) {
            s.push_back(tmp->val);
            tmp = tmp->next;
            if(tmp == head) {
                break;
            }
        }
        sort(s.begin(), s.end());
        int insert_index = -1;
        if(insertVal <= s[0] || insertVal >= s[s.size() - 1]) {
            
            insert_index = s[s.size() - 1];
            // cout << insert_index << endl;
        } else {
            for(int i = 0; i < s.size() - 1; i++) {
                // if(s[i] == s[i + 1]) {
                //     continue;
                // }
                if(insertVal >= s[i] && insertVal < s[i + 1]) {

                    insert_index = s[i];
                    break;
                }
            }
        }

        tmp = head;
        int count = 0;
        while(true) {
            if(tmp->val == insert_index) {
                if(tmp->next->val == insert_index && count < s.size()) {
                    count++;
                    tmp = tmp->next;
                    continue;
                }
                Node* next = tmp->next;
                Node* cur = new Node(insertVal, nullptr);
                tmp->next = cur;
                cur->next = next;
                break;
            }
            tmp = tmp->next;
        }

        return head;
    }
};
 

