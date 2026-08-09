#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
// 5-12
// 11 ms
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    set<vector<int>> st;
    // int sum;

    void back(vector<int>& a, int target, int index, int sum, vector<int>& _sum) {
        if(sum > target) return;
        if(sum == target) {
            // sort(tmp.begin(), tmp.end());
            st.insert(tmp);
            return;
        }
        if(_sum[a.size()] - _sum[index] + sum < target){
            // cout << _sum[a.size()] << " " << index << " " <<  _sum[index] << " " << sum << endl;
            return;
        } 
        if(index >= a.size()) return;

        for(int i = index; i < a.size(); i++) {
            sum += a[i];
            tmp.push_back(a[i]);
            back(a, target, i + 1, sum, _sum);
            sum -= a[i];
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 这里一定要排序
        unordered_map<int, int> mp;
        for(int i = 0; i < candidates.size(); i++) {
            if(mp.count(candidates[i])) {
                if(mp[candidates[i]] * candidates[i] >= target) {

                } else {
                    mp[candidates[i]]++;
                }
            } else {
                mp[candidates[i]] = 1;
            }
        }

        vector<int> x;
        for(auto &t: mp) {
            int num = t.first;
            int n = t.second;
            for(int i = 0; i < n; i++) {
                x.push_back(num);
            }
        }
        sort(x.begin(), x.end());
        // cout << x.size() << endl;
        vector<int> _sum(x.size() + 1, 0);
        for(int i = 0; i < x.size(); i++) {
            _sum[i + 1] = _sum[i] + x[i];
        }
        
        back(x, target, 0, 0, _sum);
        
        for(auto &x: st) {
            res.push_back(x);
        }
        return res;
    }
};