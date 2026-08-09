#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
using namespace std;
// 5-12

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> mp;
//         vector<int> res;

//         for(int i = 0; i < nums.size(); i++) {
//             mp[nums[i]] = i;
//         }
//         for(int i = 0; i < nums.size(); i++) {
//             if(mp.count(target - nums[i]) && mp[target - nums[i]] != i) {
//                 res.push_back(i);
//                 res.push_back(mp[target - nums[i]]);
//                 break;
//             }
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> res;
//         unordered_map<string, vector<int>> mp;
//         for(int i = 0; i < strs.size(); i++) {
//             string s = strs[i];
//             sort(s.begin(), s.end());
//             mp[s].push_back(i);
//         }

//         for(auto &x: mp) {
//             vector<int> &a = x.second;
//             vector<string> tmp;
//             for(int i = 0; i < a.size(); i++) {
//                 tmp.push_back(strs[a[i]]);
//             }
//             res.push_back(tmp);
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> st(nums.begin(), nums.end());
//         int res = 0;

//         for(auto &x: st) {
//             int num = x;
//             int ct = 1;
//             if(st.count(x - 1)) {

//             } else {
//                 while(st.count(num + 1)) {
//                     num += 1;
//                     ct += 1;
//                 }
//             }
//             res = max(res, ct);
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
//         int i = 0, j = 0;
//         while(i <= j && j < n) {
//             if(nums[i] != 0) {
//                 i++;
//                 j++;
//             } else if(nums[i] == 0) {
//                 if(nums[j] != 0) {
//                     swap(nums[i], nums[j]);
//                     j++;
//                     i++;
//                 } else {
//                     j++;
//                 }
//             }
//         }   
//     }
// };

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int i = 0, j = height.size() - 1;
//         int res = 0;
//         while(i < j) {
//             res = max(res, min(height[i], height[j]) * (j - i));
//             if(height[i] < height[j]) {
//                 i++;
//             } else {
//                 j--;
//             }
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> res;
//         unordered_map<int, int> mp;
//         set<vector<int>> st;

//         for(int i = 0; i < nums.size(); i++) {
//             mp[nums[i]]++;
//         }

//         sort(nums.begin(), nums.end());
//         for(int i = 0; i < nums.size(); i++) {
//             if(i != 0) {
//                 if(nums[i] == nums[i - 1]) {
//                     continue;
//                 }
//             }
//             for(int j = i + 1; j < nums.size(); j++) {
//                 if(j != i + 1) {
//                     if(nums[j] == nums[j - 1]) {
//                         continue;
//                     }
//                 }
//                 int sum = 0 - nums[i] -nums[j];
//                 if(mp.count(sum)) {
//                     if(sum == nums[i]) {
//                         if(mp[sum] <= 1) continue;
//                     }
//                     if(sum == nums[j]) {
//                         if(mp[sum] <= 1) continue;
//                     }
//                     if(sum == nums[i] && sum == nums[j]) {
//                         if(mp[sum] <= 2) continue;
//                     }
//                     vector<int> tmp = {nums[i], nums[j], sum};
//                     sort(tmp.begin(), tmp.end());
//                     st.insert(tmp);
//                 }
//             }
//         }

//         for(auto &x: st) {
//             res.push_back(x);
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int left_max = 0;
//         int right_max = 0;
//         int i = 0, j = height.size() - 1;
//         int res = 0;

//         while(i < j) {
//             left_max = max(left_max, height[i]);
//             right_max = max(right_max, height[j]);
//             if(left_max < right_max) {
//                 res += left_max - height[i];
//                 i++;
//             } else {
//                 res += right_max - height[j];
//                 j--;
//             }
//         }

//         return res;
//     }
// };

// "pwwkew"
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int start = 0;
//         int res = 0;
//         unordered_map<char, int> mp;

//         for(int i = 0; i < s.length(); i++) {
            
//             if(mp.count(s[i])) {
//                 int end = mp[s[i]];
//                 for(int j = start; j <= end; j++) {
//                     mp.erase(s[j]);
//                 }
//                 start = end + 1;
//             }
//             mp[s[i]] = i;
//             res = max(res, i - start + 1);
//             // cout << i << " " << start << endl;
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> res;
//         if(s.length() < p.length()) return res;

//         vector<int> sv(26, 0);
//         vector<int> pv(26, 0);

//         for(int i = 0; i < p.length(); i++) {
//             pv[p[i] - 'a']++;
//             sv[s[i] - 'a']++;
//         }
//         if(sv == pv) {
//             res.push_back(0);
//         }
//         for(int i = p.length(); i < s.length(); i++) {
//             sv[s[i - p.length()] - 'a']--;
//             sv[s[i] - 'a']++;
//             if(sv == pv) {
//                 res.push_back(i - p.length() + 1);
//             }
//         }
        
//         return res;
//     }
// };

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         int sum = 0;
//         int res = 0;

//         mp[0] = 1;
//         for(int i = 0; i < nums.size(); i++) {
//             sum += nums[i];
//             if(mp.count(k - sum)) {
//                 res += mp[k - sum];
//             }
//             mp[sum]++;
//         }
//         return res;
//     }
// };

// class cmp {
//     public:
//         bool operator()(pair<int, int> &a, pair<int, int> &b) {
//             return a.first < b.first;
//         }
// };
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> res;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

//         for(int i = 0; i < k; i++) {
//             pq.push(pair<int, int>(nums[i], i));
//         }
//         res.push_back(pq.top().first);
//         for(int i = k; i < nums.size(); i++) {
//             pair<int, int> t = pq.top();
//             while(!pq.empty() && t.second <= i - k) {
//                 pq.pop();
//                 t = pq.top();
//             }
//             pq.push(pair<int, int>(nums[i], i));
//             t = pq.top();
//             res.push_back(t.first);
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int low = prices[0];
//         int res = 0;

//         for(int i = 0; i < prices.size(); i++) {
//             low = min(low, prices[i]);
//             res = max(res, prices[i] - low);
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int index = 0;
//         for(int i = 0; i < nums.size() && i <= index; i++) {
//             index = max(index, i + nums[i]);
//         }
//         if(index >= nums.size()) return true;
//         return false;
//     }
// };

// nums = [2,3,1,1,4]
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int cur = 0;
//         int next = 0;
//         int res = 0;

//         for(int i = 0; i < nums.size() - 1; i++) {
//             next = max(next, i + nums[i]);
//             if(i == cur) {
//                 res++;
//                 cur = next;
//             }
            
//         }

//         return res;
//     }
// };

// [1,2,3,1]
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1) return nums[0];
//         vector<int> dp(n, 0);
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);

//         for(int i = 2; i < n; i++) {
//             dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//         }
//         return dp[n - 1];
//     }
// };

// 12 = 4 + 4 + 4  3个 
// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> dp(n + 1, INT_MAX);
        
//         dp[0] = 0;
//         for(int i = 1; i <= n; i++) {
//             for(int j = 1; j * j <= i; j++) {
//                 if(dp[i - j * j] != INT_MAX) {
//                     dp[i] = min(dp[i], dp[i - j * j] + 1);
//                 } else {

//                 }
//             }
//         }


//         return dp[n];
//     }
// };

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int res = -1;
//         vector<int> dp(amount + 1, INT_MAX);

//         dp[0] = 0;
//         for(int i = 1; i <= amount; i++) {
//             for(int j = 0; j < coins.size(); j++) {
//                 if(coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
//                     dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//                 }
//             }
//         }

//         return dp[amount] == INT_MAX ? -1 : dp[amount];
//     }
// };

// s = "leetcode", wordDict = ["leet", "code"]
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> st(wordDict.begin(), wordDict.end());
//         vector<bool> dp(s.length() + 1, false);

//         dp[0] = true;
//         for(int i = 1; i <= s.length(); i++) {
//             for(int j = 0; j < wordDict.size(); j++) {
//                 if(i >= wordDict[j].length()) {
//                     string tmp = s.substr(i - wordDict[j].length(), wordDict[j].length());
//                     if(st.count(tmp) && dp[i - wordDict[j].length()] == true) {
//                         dp[i] = true;
//                     }
//                 }
//             }
//         }
//         return dp[s.length()];
//     }
// };

// [10,9,2,5,3,7,101,18]   [2,3,7,101]   4 
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 1);
//         int res = 1;

//         for(int i = 0; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 if(nums[j] > nums[i]) {
//                     dp[j] = max(dp[j], dp[i] + 1);
//                 }
//             }
//             res = max(res, dp[i]);
//         }

//         // for(auto &x: dp) {
//         //     cout << x << ' ';
//         // }cout << endl;

//         return res;
//     }
// };

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         vector<long long> min_(n, 0), max_(n, 0);
//         long long res = nums[0];

//         min_[0] = max_[0] = nums[0];
//         for(int i = 1; i < n; i++) {
//             min_[i] = min(min_[i - 1] * (long long)nums[i], min((long long)nums[i] ,max_[i - 1] * (long long)nums[i]));
//             max_[i] = max(min_[i - 1] * (long long)nums[i], max((long long)nums[i] ,max_[i - 1] * (long long)nums[i]));
//             res = max(res, max_[i]);
//         }
//         return res;
//     }
// };

// nums = [1,5,11,5]
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         int n = nums.size();

//         for(int i = 0; i < n; i++) {
//             sum += nums[i];
//         }
//         if(sum % 2 != 0) return false;

//         sum = sum / 2;

//         vector<vector<int>> dp(n, vector<int>(sum + 1, 0)); // 0/1 背包
//         for(int i = nums[0]; i <= sum; i++) {
//             dp[0][i] = nums[0];
//         }
//         // cout << " sss " << endl;
//         for(int i = 1; i < n; i++) {
//             for(int j = 1; j <= sum; j++) {
//                 if(j >= nums[i]) {
//                     dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
//                 } else {
//                     dp[i][j] = max(dp[i][j], dp[i - 1][j]);
//                 }
//             }
//         }
//         // cout << " sss " << endl;
//         if(dp[n - 1][sum] == sum) return true;
//         return false;        
//     }
// };

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 0));

//         for(int i = 0; i < m; i++) {
//             dp[i][0] = 1;
//         }
//         for(int i = 0; i < n; i++) {
//             dp[0][i] = 1;
//         }

//         for(int i = 1; i < m; i++) {
//             for(int j = 1; j < n; j++) {
//                 dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
//             }
//         }

//         // for(int i = 0; i < m; i++) {
//         //     for(int j = 0; j < n; j++) {
//         //         cout << dp[i][j] << ' ';
//         //     }cout << endl;
//         // }

//         return dp[m - 1][n - 1];
//     }
// };

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         dp[0][0] = grid[0][0];
//         for(int i = 1 ; i < m; i++) {
//             dp[i][0] += dp[i - 1][0] + grid[i][0];
//         }
//         for(int j = 1; j < n; j++) {
//             dp[0][j] += dp[0][j - 1] + grid[0][j];
//         }

//         for(int i = 1; i < m; i++) {
//             for(int j = 1; j < n; j++) {
//                 dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
//             }
//         }

//         return dp[m - 1][n - 1];
//     }
// };

//  "babad" 
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.length();

//         vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
//         int start = 0;
//         int len = 1; // 最短是1

//         for(int i = 1; i <= n; i++) {
//             dp[i][i] = true;
//         }
//         for(int i = n - 1; i >= 1; i--) { // i < j
//             for(int j = i + 1; j <= n; j++) {
//                 if(s[i - 1] == s[j - 1]) {
//                     if(j == i + 1) {
//                         dp[i][j] = true;
//                         if(j - i + 1 > len) {
//                                 start = i - 1;
//                                 len = j - i + 1;
//                             }
//                     } else {
//                         if(dp[i + 1][j - 1]) {
//                             dp[i][j] = true;
//                             if(j - i + 1 > len) {
//                                 start = i - 1;
//                                 len = j - i + 1;
//                             }
//                         }
//                     }
//                 }
                
//             }
            
//         }
//         // for(int i = 0; i <= n; i++) {
//         //     for(int j = 0; j <= n; j++) {
//         //         cout << dp[i][j] << ' ';
//         //     }cout << endl;
//         // }
//         string res = s.substr(start, len);
//         return res;
//     }
// };

// ########################################################################################################################
// 5-14
//text1 = "abcde", text2 = "ace" 
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.length(), m = text2.length();

//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//         for(int i = 1; i <= n; i++) {
//             for(int j = 1; j <= m; j++) {
//                 if(text1[i-1] == text2[j-1]) {
//                     dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
//                 } else {
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                 }
//             }
//         }

//         return dp[n][m];
//     }
// };

// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.length();
//         int m = word2.length();

//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//         for(int i = 1; i <= n; i++) {
//             dp[i][0] = i;
//         }
//         for(int i = 1; i <= m; i++) {
//             dp[0][i] = i;
//         }

//         for(int i = 1; i <=n; i++) {
//             for(int j = 1; j <= m; j++) {
//                 if(word1[i - 1] == word2[j - 1]) {
//                     dp[i][j] = dp[i - 1][j - 1];
//                 } else {
//                     dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };

// ")()())"  // 5ms
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int n = s.length();
//         vector<bool> vis(n, false);
        
//         stack<pair<char, int>> st;
//         for(int i = 0; i < n; i++) {
//             if(st.empty()) {
//                 st.push(pair<char, int>(s[i], i));
//             } else {
//                 pair<char, int> t = st.top();
//                 if(t.first == '(') {
//                     if(s[i] == ')') {
//                         st.pop();
//                         vis[i] = true;
//                         vis[t.second] = true;
//                     } else {
//                         st.push(pair<char, int>(s[i], i));
//                     }
//                 } else {
//                     st.push(pair<char, int>(s[i], i));
//                 }
//             }
//         }
        
//         int res = 0;
//         int count = 0;
//         for(int i = 0; i < n; i++) {
//             if(vis[i]) {
//                 count++;
//             } else {
//                 res = max(res, count);
//                 count = 0;
//             }
//         }
//         res = max(res, count);
//         return res;
//     }
// };

// aabbabccdd  // 2ms 
// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         unordered_map<char, pair<int, int>> mp;
//         vector<int> res;
//         if(s.length() == 0) {
//             return res;
//         }

//         for(int i = 0; i < s.length(); i++) {
//             if(!mp.count(s[i])) {
//                 mp[s[i]].first = i;
//                 mp[s[i]].second = i;
//             } else {
//                 mp[s[i]].second = i;
//             }
//         }
//         // for(int i = 0; i < s.length(); i++) {
//         //     cout << mp[s[i]].first << ' ' << mp[s[i]].second << endl;
//         // }

//         for(int i = 0; i < s.length(); i++) {
//             int start = mp[s[i]].first;
//             int end = mp[s[i]].second;
            
            
//             for(int j = start; j <= end; j++) {
//                 end = max(end, mp[s[j]].second);
//             }
//             i = end;
//             // cout << start << " " << end << endl;
//             res.push_back(end - start + 1);
//         }
        
//         return res;
//     }
// };

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         for(int i = 0; i < n; i++) {
//             if(i == 0 && matrix[i][0] > target) {
//                 return false;
//             }
//             if(i == n - 1) {
//                 for(int j = 0; j < m; j++) {
//                     if(matrix[i][j] == target) {
//                         return true;
//                     }
//                 }
//                 return false;
//             }

//             if(target < matrix[i + 1][0]) {
//                 for(int j = 0; j < m; j++) {
//                     if(matrix[i][j] == target) {
//                         return true;
//                     }
//                 }
//                 return false;
//             } 
//         }
//         return false;
//     }
// };

// n皇后的复杂度是 n！  // 3ms
// class Solution {
// private:
//     vector<vector<string>> res;
// public:
//     bool judge(int n, int row, int col, vector<string>& tmp) {
//         // 遍历列
//         for(int i = 0; i < row; i++) {
//             if(tmp[i][col] == 'Q') return false; 
//         }

//         // 遍历斜线，没有必要遍历行，因为每行有且只有一个
//         for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
//             if(tmp[i][j] == 'Q') return false;
//         }
//         for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
//             if(tmp[i][j] == 'Q') return false;
//         }
//         return true;
//     }

//     void back(int n, int row, vector<string>& tmp) {
//         if(row == n) {
//             res.push_back(tmp);
//             return;
//         }

//         for(int col = 0; col < n; col++) {
//             if(judge(n, row, col, tmp)) {
//                 tmp[row][col] = 'Q';
//                 back(n, row + 1, tmp);
//                 tmp[row][col] = '.'; // 回溯
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<string> tmp(n, string(n, '.')); // 棋盘
//         back(n, 0, tmp);
//         return res;
//     }
// };

// class Solution {
// public:
//     int qsort(vector<int>& nums, int l, int r, int k) {
//         if(l == r) {
//             return nums[k];
//         }
//         int i = l - 1, j = r + 1;
//         int pt = nums[rand() % (r - l + 1) + l];
//         while(i < j) {
//             do{i++;} while(nums[i] < pt);
//             do{j--;} while(nums[j] > pt);
//             if(i < j) {
//                 swap(nums[i], nums[j]);
//             }
//         }
//         if(k <= j) {
//             return qsort(nums, l, j, k);
//         } else {    
//             return qsort(nums, j + 1, r, k);
//         }
//     }
//     int findKthLargest(vector<int>& nums, int k) {
//         int res = qsort(nums, 0, nums.size() - 1, nums.size() - k);
//         return res;
//     }
// };

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         for(int i = 0; i < s.length(); i++) {
//             if(st.empty()) {
//                 st.push(s[i]);
//             } else {
//                 char c = st.top();
//                 if(c == '(') {
//                     if(s[i] == ')') {
//                         st.pop();
//                     } else {
//                         st.push(s[i]);
//                     }
//                 } else if(c == '[') {
//                     if(s[i] == ']') {
//                         st.pop();
//                     } else {
//                         st.push(s[i]);
//                     }
//                 } else if(c == '{') {
//                     if(s[i] == '}') {
//                         st.pop();
//                     }  else {
//                         st.push(s[i]);
//                     }
//                 }
//             }
//         }
//         if(st.empty()) return true;
//         return false;
//     }
// };

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         stack<int> st;
//         vector<int>& a = temperatures;
//         int n = a.size();
//         vector<int> res(n, 0);

//         for(int i = 0; i < n; i++) {
//             if(st.empty()) {
//                 st.push(i);
//             } else {
//                 while(!st.empty() && a[i] > a[st.top()]) {
//                     int index = st.top();
//                     res[index] = i - index;
//                     st.pop();
//                 }
//                 st.push(i);
//             }
//         }
//         return res;
//     }
// };

// heights = [2,1,5,6,2,3]heights = [2,1,5,6,2,3]
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         stack<int> st;
//         vector<int> l(n, 0), r(n, 0);

//         for(int i = 0; i < n; i++) {
//             while(!st.empty() && heights[i] <= heights[st.top()]) {
//                 st.pop();
//             }
//             if(st.empty()) {
//                 l[i] = -1;
//             } else {
//                 l[i] = st.top();
//             }
//             st.push(i);
//         }
        
//         for(int i = n - 1; i >= 0; i--) {
//             while(!st.empty() && heights[i] <= heights[st.top()]) {
//                 st.pop();
//             }
//             if(st.empty()) {
//                 l[i] = -1;
//             } else {
//                 l[i] = st.top();
//             }
//             st.push(i);
//         }

//         int res = 0;
//         for(int i = 0; i < n; i++) {
//             res = max(res, heights[i] * (r[i] - l[i] - 1));
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int l = 0, r = nums.size();
//         while(l < r) {
//             int mid = (l + r) / 2;
//             if(nums[mid] > target) {
//                 r = mid;
//             } else if(nums[mid] < target) {
//                 l = mid + 1;
//             } else {
//                 return mid;
//             }
//         }
//         return l;
//     }
// };

// class Solution {
// public:
//     const vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
//     void dfs(vector<vector<char>>& g, int n, int m, int i, int j) {
//         if(i < 0 || j < 0 || i >= n || j >= m || g[i][j] == '0') {
//             return;
//         }
//         g[i][j] = '0';
//         for(int k = 0; k < 4; k++) {
//             dfs(g, n, m, i + d[k][0], j + d[k][1]);
//         }
//         return;
//     }

//     int numIslands(vector<vector<char>>& grid) {
//         int res = 0;
//         int n = grid.size(), m = grid[0].size();

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(grid[i][j] == '1') {
//                     // cout << i << ' ' << j << endl;
//                     dfs(grid, n, m, i, j);
//                     res++;
//                 }
                
//             }
//         }
//         return res;
//     }
// };