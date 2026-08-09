#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;

// 4-15
// 75ms   n ^ 2
// class Solution {
//     public:
//         int lengthOfLIS(vector<int>& nums) {
//             vector<int> dp(nums.size(), 1);  //  以nums[i]结尾的最长递增子序
//             int res = 0;
//             // dp[0] = 1; // 初始化

//             for(int i = 0; i < nums.size(); i++) {
//                 for(int j = 0; j < i; j++) {
//                     if(nums[i] > nums[j]) {
//                         dp[i] = max(dp[i], dp[j] + 1);
//                     }
//                 }
//                 res = max(res, dp[i]);
//             }

//             return res;
//         }
//     };

