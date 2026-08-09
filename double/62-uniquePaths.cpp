/**
 * 2025-3-17
 * 1-：dp[i][j]代表到达[i][j]位置有多少条路，然后反推dp[i][j]是如何得到的，确定初始化条件，确定循环方向即可
 */ 

#include<iostream>
#include<vector>
using namespace std;


/*===============1-: 0ms=====================*/
class Solution {
    public:
        int uniquePaths(int m, int n) {
            // dp[i][j]代表到达[i][j]位置有多少条路，然后反推dp[i][j]是如何得到的，确定初始化条件，确定循环方向即可
            int dp[m][n]; // m行 n列
            // 到达第一行第一列的任何位置只能是一条路
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

int main() {

    return 0;
}