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
// 64ms 思路就是用大根堆存储<num, index>, 每次取出堆顶的时候判断当前的index是否在窗口里，如果不是的话就弹出堆，重新获得堆顶
class cmp {
    public:
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first;
        }
};

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // big
            vector<int> res;

            for(int i = 0; i < k; i++) {
                pq.push(pair<int, int>(nums[i], i));
            }
            pair<int, int> x = pq.top();
            res.push_back(x.first);
            for(int i = k; i < nums.size(); i++) {
                pq.push(pair<int, int>(nums[i], i));
                x = pq.top();
                while(!pq.empty() && x.second < i - k + 1) {
                    pq.pop();
                    x = pq.top();
                }
                res.push_back(x.first);
            }

            return res;
        }
    };