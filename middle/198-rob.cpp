/**
 * 2025-3-11
 * 1-：dp
 */

#include<iostream>
#include<vector>
using namespace std;


/*================1-: 0ms=====================*/
class Solution {
    public:
        int rob(vector<int>& nums) {
            // dp[i]是什么 -> 递推公式 -> 初始化 -> 如何遍历 -> 手动模拟数组
            // 当前房间拿不拿取决于前一个或者前两个房间的情况
            if(nums.size() == 1) return nums[0];
            if(nums.size() == 2) return max(nums[0], nums[1]);

            vector<int> dp(nums.size() + 1);
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
            for(int i = 2; i <= nums.size(); i++) {
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            }

            return dp[nums.size() - 1];
        }
    };

int main() {

    return 0;
}