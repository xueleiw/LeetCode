#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <stack>
using namespace std;

//5-5

// class Solution {
//     public:
//         int climbStairs(int n) {
//             vector<int> dp(n + 1, 0);
//             dp[0] = 1;
//             dp[1] = 1;
//             for(int i = 2; i <= n; i++) {
//                 dp[i] = dp[i - 1] + dp[i - 2];
//             }
//             return dp[n];
//         }
//     };

// 3ms
// class Solution {
//     public:
//         vector<vector<int>> generate(int numRows) {
//             int n = numRows;
//             vector<vector<int>> res(n, vector<int>(n, 0));
//             vector<vector<int>> ans;
//             vector<int> tmp;

//             for(int i = 0; i < n; i++) {
//                 res[i][0] = 1;
//             }
//             //
//             for(int i = 1; i < n; i++) {
//                 for(int j = 1; j <= i; j++) {
//                     res[i][j] = res[i - 1][j] + res[i - 1][j -1];
//                 }
//             }
            
//            for(int i = 0; i < n; i++) {
//                 for(int j = 0; j <= i; j++) {
//                     tmp.push_back(res[i][j]);
//                 }
//                 ans.push_back(tmp);
//                 tmp.clear();
//            }

//            return ans;
//         }
//     };


// class Solution {
//     public:
//         int rob(vector<int>& nums) {
//             vector<int> dp(nums.size() + 1, 0);
//             dp[1] = nums[0];
//             for(int i = 2; i <= nums.size(); i++) {
//                 dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
//             }

//             return dp[nums.size()];
//         }
//     };

// 55ms
// class Solution {
//     public:
//         int numSquares(int n) {
//             vector<int> dp(n + 1, INT_MAX);
//             dp[0] = 0;
//             for(int i = 1; i <= n; i++) {
//                 for(int j = 1; j * j <= i; j++) {
//                     if(dp[i - j * j] != INT_MAX) {
//                         dp[i] = min(dp[i], dp[i - j * j] + 1);
//                     }
//                 }
//             }
//             return dp[n];
//         }
//     };

// 14ms
// class Solution {
//     public:
//         int coinChange(vector<int>& coins, int amount) {
//             vector<int> dp(amount + 1, INT_MAX);
//             dp[0] = 0; // 和为0需要0个硬币
//             for(int i = 0; i < coins.size(); i++) {
//                 for(int j = 1; j <= amount; j++) {
//                     if(j < coins[i]) continue;
//                     if(dp[j - coins[i]] != INT_MAX) {
//                         dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
//                     }
//                 }
//             }
//             return dp[amount] == INT_MAX ? -1 : dp[amount];
//         }
//     };

// 0ms
// class Solution {
//     public:
//         bool wordBreak(string s, vector<string>& wordDict) {
//             unordered_set<string> st(wordDict.begin(), wordDict.end());
//             int n = s.length();
//             vector<bool> dp(n + 1, false);
//             dp[0] = true; // 空串的情况是true
//             for(int i = 1; i <= n; i++) {
//                 for(int j = 0; j < wordDict.size(); j++) {
//                     if(wordDict[j].length() > i) continue;
//                     int len = wordDict[j].length();
//                     string t = s.substr(i - len, len);
//                     if(st.count(t)) {
//                         if(dp[i - len]) {
//                             dp[i] = true;
//                         }
//                     }
//                 }
//             }
//             return dp[n];
//         }
//     };


// 10,9,2,5,3,7,101,18
// class Solution {
//     public:
//         int lengthOfLIS(vector<int>& nums) {
//             int n = nums.size();
//             vector<int> dp(n + 1, 1);
//             int res = 1;

//             for(int i = 0; i < n - 1; i++) {
//                 for(int j = i + 1; j < n; j++) {
//                     if(nums[j] > nums[i]) {
//                         dp[j] = max(dp[j], dp[i] + 1);
//                     }
//                 }
//                 res = max(res, dp[i + 1]);
//             }

//             return res;
//         }
//     };


// 1 -2 3 -4 == 24
// class Solution {
//     public:
//         int maxProduct(vector<int>& nums) {
//             int n = nums.size();
//             int res = nums[0];
//             vector<int> ma(n + 1, INT_MIN); // 以i结尾的区间内最大乘积
//             vector<int> mi(n + 1, INT_MAX);
//             ma[1] = nums[0];
//             mi[1] = nums[0];

//             for(int i = 2; i <= n; i++) {
//                 ma[i] = max(nums[i - 1], max(nums[i - 1] * mi[i - 1], nums[i - 1] * ma[i - 1]));
//                 mi[i] = min(nums[i - 1], min(nums[i - 1] * mi[i - 1], nums[i - 1] * ma[i - 1]));
//                 res = max(res, ma[i]);
//             }
//             return res;
//         }
//     };
// class Solution {
//     public:
//         int maxProduct(vector<int>& nums) {
//             int fu = 0;
//             for(int i = 0; i < nums.size(); i++) {
//                 if(nums[i] < 0)
//             }
//         }
//     };


// 226ms
// class Solution {
//     public:
//         bool canPartition(vector<int>& nums) {
//             int sum = 0;
//             int n = nums.size();
//             for(int i = 0; i < n; i++) {
//                 sum += nums[i];
//             }
//             if(sum % 2 != 0) return false;
//             sum = sum / 2;
//             vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
            
//             for(int i = nums[0]; i <= sum; i++) {
//                 dp[1][i] = nums[0];
//             }
//             for(int i = 0; i < n; i++) {
//                 if(nums[i] <= 1) {
//                     dp[i + 1][1] = 1;
//                 }
//             }

//             for(int i = 2; i <= n; i++) {
//                 for(int j = 2; j <= sum; j++) {
//                     if(j - nums[i - 1] >= 0) {
//                         dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
//                     }// else {
//                         dp[i][j] = max(dp[i][j], dp[i - 1][j]);
//                     // }
//                 }
//             }
//             // for(int i = 0; i <= n; i++) {
//             //     for(int j = 0; j <= sum; j++) {
//             //         cout << dp[i][j] << ' ';
//             //     }cout <<endl;
//             // }
//             if(dp[n][sum] == sum) return true;
//             return false;
//         }
//     };


// 4ms
// class Solution {
//     public:
//         int maxProfit(vector<int>& prices) {
//             int _min = INT_MAX;
//             int index = -1;
//             int res = 0;
//             for(int i = 0; i < prices.size(); i++) {
//                 if(prices[i] < _min) {
//                     _min = prices[i];
//                     index = i;
//                 }
//                 res = max(res, prices[i] - _min);
//             }

//             return res;
//         }
//     };
// class Solution {
//     public:
//         int maxProfit(vector<int>& prices) {
//             if(prices.size() <= 1) return 0;
//             int res =0;
//             vector<int> dp;
//             for(int i = 1; i < prices.size(); i++) {
//                 dp.push_back(prices[i] - prices[i - 1]);
//             }
//             for(int i = 0; i < dp.size(); i++) {
//                 if(dp[i] > 0) {
//                     res += dp[i];
//                 }
//             }
//             return res;
//         }
//     };


// class Solution {
//     public:
//         bool canJump(vector<int>& nums) {
//             int max_position = 0;
//             for(int i = 0 ; i < nums.size(); i++) {
//                 if(i <= max_position) {
//                     max_position = max(max_position, nums[i] + i);
//                 } else {
//                     return false;
//                 }
//             }
//             return true;
//         }
//     };

// class Solution {
//     public:
//         int jump(vector<int>& nums) {
//             int n = nums.size();
//             int res = 0;
//             int next_position = 0;
//             int cur = 0;
//             for(int i = 0; i < n - 1; i++) {
//                 next_position = max(next_position, nums[i] + i);
//                 if(cur == i) {
//                     cur = next_position;
//                     res++;
//                 }
//             }
//             return res;
//         }
//     };

// 5-6
// class Solution {
//     public:
//         int uniquePaths(int m, int n) {
//             vector<vector<int>> dp(m, vector<int>(n, 0));
            
//             for(int i = 0; i < m; i++) {
//                 dp[i][0] = 1;
//             }
//             for(int i = 0; i < n; i++) {
//                 dp[0][i] = 1;
//             }

//             for(int i = 1; i < m; i++) {
//                 for(int j = 1; j < n; j++) {
//                     dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1];
//                 }
//             }

//             return dp[m - 1][n - 1];
//         }
//     };


    // class Solution {
    //     public:
    //         int minPathSum(vector<vector<int>>& grid) {
    //             int m = grid.size();
    //             int n = grid[0].size();
    //             for(int i = 1; i < m; i++) {
    //                 grid[i][0] += grid[i - 1][0];
    //             }
    //             for(int i = 1; i < n; i++) {
    //                 grid[0][i] += grid[0][i - 1];
    //             }

    //             for(int i = 1; i < m; i++) {
    //                 for(int j = 1; j < n; j++) {
    //                     grid[i][j] = min(grid[i - 1][j] + grid[i][j], grid[i][j - 1] + grid[i][j]);
    //                 }
    //             }

    //             return grid[m - 1][n - 1];
    //         }
    //     };

// 290 ms
// class Solution {
//     public:
//         string longestPalindrome(string s) {
//             if(s.length() <= 1) return s;
            
//             int n = s.length();
//             vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//             for(int i = 0; i < n; i++) {
//                 dp[i][i] = 1;
//             }

//             int start = 0, length = 1; // 最坏也返回1个
//             for(int i = n - 2; i >= 0; i--) {  // i < j
//                 for(int j = i + 1; j < n; j++) {
//                     if(s[i] == s[j]) {
//                         if(i + 1 == j) {
//                             dp[i][j] = 1;
//                         } else {
//                             if(dp[i + 1][j - 1] == 1) {
//                                 dp[i][j] = 1;
//                             }
//                         }
//                     }
//                     if(dp[i][j] == 1) {
//                         if(j - i + 1 > length) {
//                             start = i;
//                             length = j - i + 1;
//                         }
//                     }
//                 }
//             }
    
//             string res = s.substr(start, length);
//             return res;
//         }
//     };

// 27ms
// class Solution {
//     public:
//         int longestCommonSubsequence(string text1, string text2) {
//             int n = text2.length();
//             int m = text1.length();
            
//             vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//             for(int i = 1; i <= n; i++) {
//                 for(int j = 1; j <= m; j++) {
//                     if(text2[i - 1] == text1[j - 1]) {
//                         dp[i][j] = dp[i - 1][j - 1] + 1;
//                     } else {    
//                         dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//                     }
//                 }
//             }

//             return dp[n][m];
//         }
//     };


// 29ms 
// class Solution {
//     public:
//         vector<int> dailyTemperatures(vector<int>& temperatures) {
//             int n = temperatures.size();
//             vector<int> ans(n, 0);
//             stack<int> st;

//             for(int i = 0; i < n; i++) {
//                 int x = temperatures[i];
//                 while(!st.empty()) {
//                     int t = st.top();
//                     if(x <= temperatures[t]) {
//                         st.push(i);
//                         break;
//                     } else {
//                         st.pop();
//                         ans[t] = i - t;
//                     }
//                 }
//                 if(st.empty()) {
//                     st.push(i);
//                     continue;
//                 }
//             }

//             return ans;
//         }
//     };