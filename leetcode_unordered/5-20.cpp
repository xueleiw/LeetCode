#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;
// 5-20

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n + 1, 0);
//         dp[1] = nums[0];
//         for(int i = 2; i <= n; i++) {
//             dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
//         }
//         return dp[n];
//     }
// };

// 12 = 4 + 4 + 4   3个
// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> dp(n + 1, INT_MAX);
//         dp[0] = 0;
//         for(int i = 1; i <= n; i++) {
//             for(int j = 1; j * j <= i; j++) {
//                 if(dp[i - j* j] != INT_MAX) {
//                     dp[i] = min(dp[i], dp[i - j * j] + 1);
//                 }
//             }
//         }
//         return dp[n];
//     }
// };

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount + 1, INT_MAX);
        
//         dp[0] = 0;
//         for(int i = 1; i <= amount; i++) {
//             for(int j = 0; j < coins.size(); j++) {
//                 if(i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
//                     dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//                 }
//             }
//         }

//         if(dp[amount] == INT_MAX) return-1;
//         return dp[amount];
//     }
// };

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.length();
//         vector<bool> dp(n + 1,false);
//         dp[0] = true;
//         unordered_set<string> st(wordDict.begin(), wordDict.end());

//         for(int i = 1; i <= n; i++) {
//             for(int j = 0; j < wordDict.size(); j++) {
//                 int x = i - wordDict[j].length();
//                 if((x) >= 0) {
//                     // cout << i << ' ' <<  wordDict[j].length() << endl;
//                     string tmp = s.substr(i - wordDict[j].length(), wordDict[j].length());
//                     // cout << tmp << endl;
//                     if(st.count(tmp) && dp[i - wordDict[j].length()] == true) {
//                         dp[i] = true;
//                     }
//                 }
//             }
//         }
//         return dp[n];
//     }
// };

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 1);
//         int res = 0;

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < i; j++) {
//                 if(nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//             res = max(res, dp[i]);
//         }
        
//         return res;
//     }
// };

// 1 -1 -2 3
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> _max(n, INT_MIN);
//         vector<int> _min(n, INT_MAX);
//         _max[0] = nums[0];
//         _min[0] = nums[0];
//         int res = INT_MIN;

//         for(int i = 1; i < n; i++) {
//             _max[i] = max(nums[i], max(nums[i] * _max[i - 1], nums[i] * _min[i - 1]));
//             _min[i] = min(nums[i], min(nums[i] * _max[i - 1], nums[i] * _min[i - 1]));
//             res = max(res, _max[i]);
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for(int i = 0; i < nums.size(); i++) {
//             sum += nums[i];
//         }
//         if(sum % 2 != 0) return false;
//         sum = sum / 2;
//         vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, 0));

//         for(int i = nums[0]; i <= sum; i++) {
//             dp[0][i] = nums[0];
//         }

//         for(int i = 1; i < nums.size(); i++) {
//             for(int j = 1; j <= sum; j++) {
//                 if(j >= nums[i]) {
//                     dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
//                 } else {
//                     dp[i][j] = dp[i - 1][j];
//                 }
//             }
//         }
//         // for(int i = 0; i < nums.size(); i++) {
//         //     for(int j = 0; j <= sum; j++) {
//         //         cout << dp[i][j] << ' ';
//         //     } cout << endl;
//         // }
//         if(dp[nums.size() - 1][sum] == sum) return true;
//         return false;
//     }
// };

// ")()())"
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int n = s.length();
//         vector<bool> dp(n, false);
//         stack<pair<char, int>> st;

//         for(int i = 0; i < n; i++) {
//             if(st.empty()) {
//                 st.push(pair<char, int>(s[i], i));
//             } else {    
//                 pair<char, int> p = st.top();
//                 if(s[i] == ')' && p.first == '(') {
//                     st.pop();
//                     dp[i] = true;
//                     dp[p.second] = true;
//                 } else {
//                     st.push(pair<char, int>(s[i], i));
//                 }
//             }
//         }

//         int res = 0;
//         int count = 0;
//         for(int i = 0; i < n; i++) {
//             if(dp[i]) {
//                 count++;
//             } else {
//                 res = max(res, count);
//                 count = 0;
//             }
//         }res = max(res, count);

//         return res;
//     }
// };