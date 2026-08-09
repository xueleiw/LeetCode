// 4-8
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// 129ms  01 背包 dp[i][j] 代表 从0~i物品中选放到容量为j的背包中所能获得的最大价值是多少;使用的时候需要注意首列和首行初始化，而且要多一列
// 外层物品内层背包

class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            if(nums.size() == 1) return false;
            int sum = 0;
            for(int i = 0; i < nums.size(); i++) {
                sum += nums[i];
            }
            if(sum % 2 != 0) return false; // 不是偶数不能平分

            vector<vector<int>> dp(nums.size(), vector<int>((sum / 2) + 1, 0));
            // 首行初始化
            int n = (sum / 2);
            for(int i = 0; i <= n; i++) {
                if(i >= nums[0]) {
                    dp[0][i] = nums[0];
                }
            }

            for(int i = 1; i < nums.size(); i++) {
                for(int j = 1; j <= n; j++) {
                    if(j < nums[i]) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                    }
                }
            }

            if(dp[nums.size() - 1][n] == n) return true;
            return false;

        }
    };