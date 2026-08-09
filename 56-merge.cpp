/** 2024-12-24
 * 1-比较第一个区间的右边界和后面区间的左边界，不断扩大右边界，这样便能合并所有重叠区间; 这里的初始化排序需要注意一下
 * 
*/

#include<bits/stdc++.h>
using namespace std;

/*=======1-: 4ms==========*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int array[10005];
        memset(array, 0 ,sizeof(array));
        /****************************************************************************************/
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; // 按第一个元素升序
        });
        /****************************************************************************************/
        // 先记录第一个区间，看看后面是否需要合并
        int a = intervals[0][0];
        int b = intervals[0][1]; // b其实记录的是右边界的最大值,如果比b大的左边界说明不会重合
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size() - 1; i++) {
            if(b >= intervals[i + 1][0]) {
                b = max(intervals[i + 1][1], b); // 扩展b到右边界到最大
            } else {
                res.push_back({a, b});
                // 修改a b为下一个区间的值
                a = intervals[i + 1][0];
                b = intervals[i + 1][1];
            }
        }
        res.push_back({a, b});
        return res;
    }
};

int main() {
    vector<vector<int>> A = {{1, 3}, {2, 6}};
    Solution solu;
    

    return 0;
}