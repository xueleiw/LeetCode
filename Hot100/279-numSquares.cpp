// 4-7
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

// 43ms 完全背包问题  外层循环遍历背包，内层循环遍历物品
class Solution {
    public:
        int numSquares(int n) {
            vector<int> dp(n + 1, INT_MAX);

            dp[0] = 0;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j * j <= i; j++) {
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }

            return dp[n];
        }
    };