// 4-7
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;


// 39ms 还是完全背包，需要注意的是要对物品排序，而且要确保dp[i - coins[j]]一定存在
// class Solution {
//     public:
//         int coinChange(vector<int>& coins, int amount) {
//             // if(amount == 0) return 0;
//             vector<int> dp(amount + 1, INT_MAX);

//             dp[0] = 0;
//             sort(coins.begin(), coins.end());
//             for(int i = 1; i <= amount; i++) {
//                 for(int j = 0; j < coins.size() && i >= coins[j]; j++) {
//                     // cout << i << ' ' << j << endl;
//                     if(dp[i - coins[j]] != INT_MAX) {
//                         dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//                     }
//                 }
//             }

//             if(dp[amount] != INT_MAX) return dp[amount];
//             return -1;
//         }
//     };

// 31ms 不排序的做法
class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            // if(amount == 0) return 0;
            vector<int> dp(amount + 1, INT_MAX);

            dp[0] = 0;
            // sort(coins.begin(), coins.end());
            for(int i = 1; i <= amount; i++) {
                for(int j = 0; j < coins.size(); j++) {
                    // cout << i << ' ' << j << endl;
                    if(i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }

            if(dp[amount] != INT_MAX) return dp[amount];
            return -1;
        }
    };
