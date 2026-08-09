#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
// 4-21
// 使用双端队列， O(n) 
// 23ms
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> res;
            deque<int> q;
            for(int i = 0; i < k; i++) {
                while(!q.empty() && nums[i] > nums[q.back()]) {
                    q.pop_back();
                }
                q.push_back(i);
            }
            //
            res.push_back(nums[q.front()]);
            for(int i = k; i < nums.size(); i++) {
                while(!q.empty() && nums[i] > nums[q.back()]) {
                    q.pop_back();
                }
                q.push_back(i);
                while(!q.empty() && q.front() <= i - k) {
                    q.pop_front();
                }
                res.push_back(nums[q.front()]);
            }

            return res;
        }
    };

// // 63ms 使用堆排序 n(logn)
// class cmp {
//     public:
//         // bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
//         //     return a.second < b.second; 
//         // }
//         bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
//             return a.second < b.second;
//         }
// };
// class Solution {
//     public:
//         vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//             priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
//             vector<int> res;
//             // 放入前K个
//             for(int i = 0; i < k; i++) {
//                 pq.emplace(i, nums[i]);
//             }
            
//             res.push_back(pq.top().second);
//             for(int i = k; i < nums.size(); i++) {
//                 pq.emplace(i, nums[i]);
//                 // 如果堆顶在窗口外，那么就删除堆顶
//                 while(!pq.empty() && pq.top().first <= i - k) {
//                     pq.pop();
//                 }

//                 res.push_back(pq.top().second);
//             }

//             return res;

//         }
//     };

// 暴力 n*k 超时
// class Solution {
//     public:
//         vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//             if(nums.size() == 1) return nums;
//             vector<int> res;

//             for(int i = 0; i <= nums.size() - k; i++) {
//                 int tmp = nums[i];
//                 for(int j = i; j < i + k; j++) {
//                     tmp = max(tmp, nums[j]);
//                 }
//                 res.push_back(tmp);
//             }

//             return res;
//         }
//     };