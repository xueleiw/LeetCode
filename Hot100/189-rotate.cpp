// 2025-4-6
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


// 0ms 额外空间直接移动
class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            if(k > nums.size()) k %= nums.size();
            if(k == 0) return;
            int n = nums.size();

            vector<int> res(nums.size(), 0);
            for(int i = 0; i < nums.size(); i++) {
                res[(i + k) % n] = nums[i]; 
            }

            nums = res;
        }
    };