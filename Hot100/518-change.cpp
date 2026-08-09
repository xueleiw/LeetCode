// 4-7
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;


// 7ms 完全背包求组合数，外层物品数，内层组合数
// 外层的每一轮循环代表放当前物品进去会新增加多少种组合
// 这里需要用到 unsigned long long int
class Solution {
    public:
        int change(int amount, vector<int>& coins) {
            vector<unsigned long long int> dp(amount + 1, 0);
            dp[0] = 1; // 表示数量为0的情况有1种

            for(int i = 0; i < coins.size(); i++) {
                for(int j = 1; j <= amount; j++) {
                    if(j >= coins[i]) {
                        dp[j] += dp[j - coins[i]];
                    }
                }
            }

            return dp[amount];
        }
    };

