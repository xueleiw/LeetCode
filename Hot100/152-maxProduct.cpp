// 4-8
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int res = INT_MIN;
            // 维护两个数组，dp[i] 代表当前i位置，连续乘积的最大值
            vector<int> dp(nums.size() + 1, 1);
            vector<int> gp(nums.size() + 1, 1);

            for(int i = 1; i <= nums.size(); i++) {
                dp[i] = max(nums[i - 1], max(dp[i - 1] * nums[i - 1], gp[i - 1] * nums[i - 1]));
                gp[i] = min(nums[i - 1], min(gp[i - 1] * nums[i - 1], dp[i - 1] * nums[i - 1]));
                res = max(res, dp[i]);
            }

            return res;
        }
    };