/**
 * 2025-3-12
 * 1-：dp-完全背包问题，两层循环不要动了，把判断条件直接放到循环里面
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
 
 /*================1-: 37ms=====================*/
 class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            vector<int> dp(amount + 1, INT_MAX);
            dp[0] = 0;
            for(int i = 1; i <= amount; i++) {
                for(int j = 0; j < coins.size(); j++) {
                    if(i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                        dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                    }
                }
            }
    
            if(dp[amount] == INT_MAX) return -1;
            return dp[amount];
        }
    };
 
 int main() {
 
     return 0;
 }