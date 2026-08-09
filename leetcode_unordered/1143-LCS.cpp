#include<iostream>
#include<vector>
using namespace std;
// 9-17

// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.length();
//         int n = text2.length();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

//         for(int i = 1; i <= m; i++) {
//             for(int j = 1; j <= n; j++) {
//                 if(text1[i - 1] == text2[j - 1]) {
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 } else {
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                 }
//             }
//         }

//         return dp[m][n];
//     }
// };

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

//         dp[0][0] = grid[0][0];
//         for(int i = 1; i < n; i++) {
//             dp[0][i] += grid[0][i] + dp[0][i-1];
//         }
//         for(int i = 1; i < m; i++) {
//             dp[i][0] += dp[i - 1][0] + grid[i][0];
//         }

//         for(int i = 1; i < m; i++) {
//             for(int j = 1; j < n; j++) {
//                 dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.length();
//         if(n == 1) return s;
//         if(n == 2) {
//             if(s[0] == s[1]) {
//                 return s;
//             } else {
//                 string res;
//                 res.push_back(s[0]);
//                 return res;
//             }
//         }
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//         for(int i = 0; i <= n; i++) {
//             dp[i][i] = 1;
//         }

//         string res;
//         int length = 1;
//         res.push_back(s[0]);
//         int st = 0;
//         for(int i = n - 2; i >= 0; i--) {
//             for(int j = i + 1; j < n; j++) {
//                 if(s[i] == s[j]) {
//                     if(j == i + 1) {
//                         dp[i][j] = 1;
//                     } else {
//                         if(dp[i+1][j-1] == 1) {
//                             dp[i][j] = 1;
//                         }
//                     }
//                 } else {
//                     // dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
//                 }
//                 if(dp[i][j] == 1) {
//                     if(j - i + 1 > length) {
//                         st = i;
//                         length = j - i + 1;
//                     }
//                 }
//             }
//             // if(dp[i][i+1] > length) {
//             //     length = dp[i][i+1];
//             //     res = s.substr(i, length);
//             // }
//         }

        
//         res = s.substr(st, length);
//         return res;
//     }
// };

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= n; i++) {
            dp[0][i] = i;
        }
        for(int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1));
                }
            }
        }

        return dp[m][n];
    }
};