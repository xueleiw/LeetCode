/**
 * 2025-3-12
 * 1-：dp-完全背包问题，dp[i - j * j] + 1的时候要判断是不是真的能加
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*================1-: 55ms=====================*/
class Solution {
    public:
        int numSquares(int n) {
            vector<int> dp(n + 1, INT_MAX);
            dp[0] = 0;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j * j <= i; j++) {
                    if(dp[i - j * j] != INT_MAX) { // 加的时候要判断一下是否会超范围
                        dp[i] = min(dp[i - j * j] + 1, dp[i]);
                    }
                }
            }

            return dp[n];
        }
    };

int main() {

    return 0;
}