/**
 * 2025-3-12
 * 1-：0/1 背包问题，求容量为sum/2的时候背包最大值，因为价值=重量；所以容量为sum/2的时候背包最多能装 sum/2
 */ // 

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;


/*================1-: 194ms=====================*/
class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum = 0;

            for(int i = 0; i < nums.size(); i++) {
                sum += nums[i];
            }
            if(sum % 2 != 0) return false;
            vector<vector<int>> dp(nums.size(), vector<int>((sum / 2) + 1 , 0));

            // 还需要把第一行初始化 !!!
            for(int i = nums[0]; i <= sum / 2; i++) {
                dp[0][i] = nums[0]; // 注意细节
            }

            for(int i = 1; i < nums.size(); i++) { // 物品数
                for(int j = 1; j <= sum/2; j++) {  // 包的容积
                    //               不拿当前物品  拿当前物品且留出对应的容积  
                    if(j < nums[i]) dp[i][j] = dp[i - 1][j];  // 一定要注意留出容积之后dp[i][j] 在数组里面
                    else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                }
            }

            if(dp[nums.size() - 1][sum / 2] == sum / 2) return true;
            return false;
        }
    };




int main() {

    return 0;
}