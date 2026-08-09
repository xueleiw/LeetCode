/**
 * 2025-3-12
 * 1-：暴力解法
 * 2-: 需要维护两个数组，当前位置之前的最大乘积和最小乘积，需要根据当前位置的正负来判断，是乘最大值还是乘最小值。
 */ // $$ 

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

/* 1- 超时 */
// class Solution {
//     public:
//         int maxProduct(vector<int>& nums) {
//             int res = 0;
//             for(int i = 0; i < nums.size(); i++) {
//                 int tmp = 1;
//                 for(int j = i; j < nums.size(); j++) {
//                     tmp *= nums[j];
//                     res = max(res, tmp);
//                 }
//             }

//             return res;
//         }
//     };

/*================1-: 122ms=====================*/
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            // dp[i] 代表到 nums[i]所能获得的最大乘积，且以nums[i] 为终点
            // gp[i] 代表到 nums[i]所能获得的最小乘积，且以nums[i] 为终点
            vector<int> dp(nums.size() + 1);
            vector<int> gp(nums.size() + 1);
            dp[0] = nums[0];
            gp[0] = nums[0];

            int res = nums[0];
            
            for(int i = 1; i < nums.size(); i++) {
                dp[i] = max(nums[i], max(dp[i - 1] * nums[i], gp[i - 1] * nums[i]));
                gp[i] = min(nums[i], min(gp[i - 1] * nums[i], dp[i - 1] * nums[i]));
                res = max(dp[i], res);
            }
            
            for(int i = 0; i < nums.size(); i++) {
                cout << dp[i] << ' ';
            }
            cout << endl;
            for(int i = 0; i < nums.size(); i++) {
                cout << gp[i] << ' ';
            }
            return res;
        }
    };

int main() {

    return 0;
}