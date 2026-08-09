// 4-8
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// 0ms dp[i][j] 只能从 dp[i-1][j] + dp[i][j - 1] 这两个位置过来，路径之和就是结果
class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for(int i = 0; i < m; i++) {
                dp[i][0] = 1;
            }
            for(int i = 0; i < n; i++) {
                dp[0][i] = 1;
            }

            for(int i = 1; i < m; i++) {
                for(int j = 1; j < n; j++) {
                    dp[i][j] = dp[i-1][j] + dp[i][j - 1];
                }
            }

            return dp[m - 1][n - 1];
        }
    };