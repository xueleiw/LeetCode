#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <array>
#include <queue>
using namespace std;
// 5-3 要特别注意区间包含的情况，不是重叠

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
                // if(a[0] < b[0]) {
                //     return a[0] < b[0];
                // } else {
                //     return a[1] < b[1];
                // }
                return a[0] < b[0];
            });
            vector<vector<int>> res;
            int start = intervals[0][0];
            int end = intervals[0][1];
            // cout << start << " s " << endl;
            for(int i = 1; i < intervals.size(); i++) {
                if(end >= intervals[i][0]) {
                    end = max(intervals[i][1], end);  // 这里要特别注意区间包含的情况，不是重叠
                } else {
                    res.push_back({start, end});
                    start = intervals[i][0];
                    end = intervals[i][1];
                }
            }

            // cout << start << " " << endl;
            res.push_back({start, end});
            return res;
        }
    };