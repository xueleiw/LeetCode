// 2025-4-6
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 7ms
// 按照区间左端点排序，维护一个l r ；不断和下一个区间比较能否合并，直到不能合并就加入res
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>> res;
            sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
                return a[0] < b[0];
            });

            int left = intervals[0][0];
            int right = intervals[0][1];
            for(int i = 1; i < intervals.size(); i++) {
                if(right >= intervals[i][0]) {
                    // 合并
                    right = max(right, intervals[i][1]);
                } else {
                    vector<int> tmp = {left, right};
                    res.push_back(tmp);
                    left = intervals[i][0];
                    right = intervals[i][1];
                }
            }
            vector<int> tmp = {left, right};
            res.push_back(tmp);

            return res;
        }
    };