// 4-7
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;


// 0ms 思路是dp[i] 代表偷到当前房屋可以获得的最大利润
class Solution {
    public:
        int rob(vector<int>& nums) {
            int res = 0;
            if(nums.size() <= 2) {
                for(auto &x: nums) {
                    res = max(res, x);
                }
            }

            vector<int> dp(nums.size(), 0);
            dp[0] = nums[0];
            dp[1] = max(dp[0], nums[1]);
            for(int i = 2; i < nums.size(); i++) {
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            }

            return dp[nums.size() - 1];
        }
    };