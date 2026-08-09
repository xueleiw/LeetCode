#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
// 5-11


// 0ms
// class Solution {
// public:
//     vector<vector<int>> res;
//     vector<int> tmp;
//     int sum;

//     void back(int index, int n, int k) {
//         if(tmp.size() == k && sum == n) {
//             res.push_back(tmp);
//         }

//         if(index > 9) {
//             return;
//         }
//         for(int i = index; i <= 9; i++) {
//             tmp.push_back(i);
//             sum += i;
//             back(i + 1, n, k);
//             sum -= i;
//             tmp.pop_back();
//         }

//     }

//     vector<vector<int>> combinationSum3(int k, int n) {
//         if(k > n) return res;
//         back(1, n, k); // k个数的和为n
//         return res;
//     }
// };


// candidates = [2,3,6,7], target = 7
// 4ms
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    set<vector<int>> st;
    // int sum;

    void back(vector<int>& a, int target, int index, int sum) {
        if(sum > target) return;
        if(sum == target) {
            sort(tmp.begin(), tmp.end());
            st.insert(tmp);
            return;
        }
        if(index >= a.size()) return;

        for(int i = index; i < a.size(); i++) {
            sum += a[i];
            tmp.push_back(a[i]);
            back(a, target, i, sum);
            sum -= a[i];
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 这里一定要排序
        back(candidates, target, 0, 0);
        for(auto &x: st) {
            res.push_back(x);
        }
        return res;
    }
};