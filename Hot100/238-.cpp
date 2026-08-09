// 2025-4-6
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


// 0ms
// 采用前缀和的思想，将左区间与右区间的积相乘即可
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> res(nums.size(), 0);
            vector<int> left(nums.size() + 1, 1);
            vector<int> right(nums.size() + 1, 1);

            for(int i = 0; i < nums.size(); i++) {
                left[i + 1] = left[i] * nums[i]; 
            }

            for(int i = nums.size() - 1; i >= 0; i--) {
                right[i] = nums[i] * right[i + 1];
            }

            for(int i = 0; i < nums.size(); i++) {
                res[i] = left[i] * right[i + 1];
            }

            return res;
        }
    };