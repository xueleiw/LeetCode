#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;
// 5-3
// 340ms
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            unordered_map<int, int> st;
            vector<int> new_nums;
            for(int i = 0; i < nums.size(); i++) {
                st[nums[i]]++;
                if(st[nums[i]] <= 2) { 
                    new_nums.push_back(nums[i]);
                }
                
            }
            set<vector<int>> res;
            vector<vector<int>> ans;

            for(int i = 0; i < new_nums.size() - 1; i++) {
                for(int j = i + 1; j < new_nums.size(); j++) {
                    int x = 0 - new_nums[i] - new_nums[j];
                    if(st.count(x)) {
                        bool flag = false;
                        if(x != new_nums[i] && x != new_nums[j]) {
                            flag = true;
                        } else if(x == new_nums[i] && x != new_nums[j]) {
                            if(st[x] >= 2) {
                                flag = true;
                            }
                        } else if(x != new_nums[i] && x == new_nums[j]) {
                            if(st[x] >= 2) {
                                flag = true;
                            }
                        } else if(x == new_nums[i] && x == new_nums[j]) {
                            if(st[x] >= 3) {
                                flag = true;
                            }
                        }
                        if(flag) {
                            vector<int> tmp = {x, new_nums[i], new_nums[j]};
                            sort(tmp.begin(), tmp.end());
                            res.insert(tmp);
                        }
                        
                    }
                }
            }

            for(auto &x: res) {
                ans.push_back(x);
            }
            return ans;
        }
    };