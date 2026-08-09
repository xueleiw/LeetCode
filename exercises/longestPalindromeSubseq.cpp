#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
// 4-17 dp

class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            // if(s.length() == 2) return 1;
            int n = s.length();
            vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
            for(int i = 1; i <= n; i++) {
                dp[i][i] = 1;
            }

            for(int i = n - 1; i >= 1; i--) {
                for(int j = i + 1; j <= n; j++) { // i < j
                    if(s[i - 1] == s[j - 1]) {
                        dp[i][j] = dp[i+1][j-1] + 2;
                    } else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }

            return dp[1][n];

        }
    };
