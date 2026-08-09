#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// 5-17

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 使用双端队列存储节点，然后进行连接
// 0ms 
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         deque<ListNode*> q;
//         ListNode* p = head;
//         while(p != nullptr) {
//             q.push_back(p);
//             p = p->next;
//         }
//         int i = 0;
//         ListNode* dummy = new ListNode(-1);
//         p = dummy;
//         while(!q.empty()) {
//             if(i == 0) {    
//                 ListNode* tmp = q.front();
//                 q.pop_front();
//                 tmp->next = nullptr;
//                 p->next = tmp;
//                 p = p->next;
//                 i++;
//             } else {
//                 ListNode* tmp = q.back();
//                 q.pop_back();
//                 tmp->next = nullptr;
//                 p->next = tmp;
//                 p = p->next;
//                 i--;
//             }
//         }
//         p = dummy->next;
//         delete dummy;
        
//     }
// };

// 暴力超时
// class MedianFinder {
// private:
//     vector<int> a;
// public:
//     MedianFinder() {
//         a.clear();
//     }
    
//     void addNum(int num) {
//         a.push_back(num);
//     }
    
//     double findMedian() {
//         sort(a.begin(), a.end());
//         int n = a.size();
//         if(n % 2 != 0) {
//             double res = a[n / 2];
//             return res;
//         } else {
//             // cout << a[n / 2] << ' ' << a[(n / 2) - 1] << endl;
//             double res = (a[n / 2] + a[(n / 2) - 1]) / 2.0;
//             return res;
//         }
//     }
// };

// 61ms  用两个堆，堆顶表示中位数
class MedianFinder {
private:
    priority_queue<int> bq; // 大根堆
    priority_queue<int, vector<int>, greater<int>> sq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // cout << num << ' ';
        if(bq.empty()) {
            bq.push(num);
            return;
        }
        if(sq.empty()) {
            if(bq.top() < num) {
                sq.push(num);
            } else {
                int x = bq.top();  /// 刚开始要注意两个堆的有序性
                bq.pop();
                bq.push(num);
                sq.push(x);
            }
            return;
        }
        if(bq.size() == sq.size()) {
            if(num >= sq.top()) {
                int x = sq.top();
                sq.pop();
                sq.push(num);
                bq.push(x);
            } else {
                bq.push(num);
            }
        } else if(bq.size() > sq.size()) {
            if(num > bq.top()) {
                sq.push(num);
            } else {
                int x = bq.top();
                bq.pop();
                bq.push(num);
                sq.push(x);
            }
        } else if(bq.size() < sq.size()) {
            if(num > bq.top()) {
                int x = sq.top();
                sq.pop();
                bq.push(x);
                sq.push(num);
                
            } else {    
                bq.push(num);
            }
        }
    }
    
    double findMedian() {
        double res;
        if(sq.size() == bq.size()) {
            int x = bq.top();
            int y = sq.top();
            res = (x + y) / 2.0;
        } else {
            res = bq.top();
        }
        return res;
    }
};


