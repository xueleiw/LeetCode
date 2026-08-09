#include<iostream>
#include<vector>
using namespace std;


// class Solution {
// public:
//     vector<vector<int>> res;
//     vector<int> tmp;

//     void recu(vector<int>& nums, vector<bool>& vis, int n) {
//         if(tmp.size() == n) {
//             res.push_back(tmp);
//             return;
//         }

//         for(int i = 0; i < n; i++) {
//             if(vis[i]) continue;
//             vis[i] = true;
//             tmp.push_back(nums[i]);
//             recu(nums, vis, n);
//             vis[i] = false;
//             tmp.pop_back();
            
//         }
//         return;
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> vis(n, false);

//         recu(nums, vis, n);
//         return res;
//     }
// };

// [3,2,1,5,6,4], k = 2  res=5
// class Solution {
// public:
//     int qsort(vector<int>& nums, int l, int r, int k) {
//         if(l >= r) return nums[k];
//         int i = l - 1;
//         int j = r + 1;
//         int mid = nums[(l + r) / 2];
//         int t = (l + r) / 2;

//         while(1) {
//             do{i++;}while(nums[i] < mid);
//             do{j--;}while(nums[j] > mid);
//             if(i < j) {
//                 swap(nums[i], nums[j]);
//             } else {
//                 break;
//             }
//         }
//         if(k <= j) {
//             return qsort(nums, l, j, k);
//         } else {
//             return qsort(nums, j + 1, r, k);
//         }
//     }

//     int findKthLargest(vector<int>& nums, int k) {
//         int x = nums.size() - k;
//         int res = qsort(nums, 0, nums.size() - 1, x);
//         return res;
//     }
// };

// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n + 10, 0);
//         dp[1] = 1;
//         dp[2] = 2;

//         for(int i = 3; i <= n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }

//         return dp[n];
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         int n = numRows;
//         vector<vector<int>> res;
//         vector<int> tmp;
//         vector<vector<int>> dp(n, vector<int>(n, 0));

//         for(int i = 0; i < n; i++) {
//             dp[i][0] = 1;
//         }

//         for(int i = 1; i < n; i++) {
//             for(int j = 1; j < n; j++) {
//                 dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
//             }
//         }

//         for(int i = 0;  i < n; i++) {
//             for(int j = 0; j <= i; j++) {
//                 tmp.push_back(dp[i][j]);
//             }
//             res.push_back(tmp);
//             tmp.clear();
//         }

//         return res;
//     }
// };


// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1) {
//             return nums[0];
//         }
//         if(n == 2) {
//             return max(nums[0], nums[1]);
//         }
//         vector<int> dp(n + 1, 0);

//         dp[1] = nums[0];
//         for(int i = 2; i <= n; i++) {
//             dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
//         }

//         return dp[n];
//     }
// };


// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> dp(n + 1, INT_MAX);
//         dp[0] = 0;

//         for(int i = 1; i <= n; i++) {
//             for(int j = 1; j * j <= i; j++) {
//                 if(dp[i - j * j] != INT_MAX && dp[i - j * j] + 1 < dp[i]) {
//                     dp[i] = dp[i - j * j] + 1;
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
//             for(auto &x: coins) {
//                 if(i >= x && dp[i -x] != INT_MAX) {
//                     dp[i] = min(dp[i], dp[i - x] + 1);
//                 }
//             }
//         }

//         return dp[amount] != INT_MAX?dp[amount] : -1 ;
//     }
// };

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.length();
//         vector<bool> dp(n + 1, false);
//         dp[0] = true;

//         for(int i = 1; i <= n; i++) {
//             for(auto &x: wordDict) {
//                 if(x.length() <= i) {
//                     string t = s.substr(i - x.length(), x.length());
//                     if(t == x && dp[i - x.length()]) {
//                         dp[i] = true;
//                     }
//                 }
//             }
//         }

//         return dp[n];
//     }
// };


// [10,9,2,5,3,7,101,18]   0,1,0,3,2,3
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n + 1, 1);
//         dp[0] = 0;
//         int res = 1;

//         for(int i = 1; i < n; i++) {
//             for(int j = i + 1; j <= n; j++) {
//                 if(nums[j-1] > nums[i-1]) {
//                     dp[j] = max(dp[j], dp[i] + 1);
//                 }
//              }
//             res = max(res, dp[i + 1]);
//         }

//         return res;
//     }
// };


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
    }
};