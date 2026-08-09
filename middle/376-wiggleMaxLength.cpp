#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
// 5-12

// 0ms
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 1;  // 波谷
        dp[0][1] = 1;  // 波峰
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + 1);
            } else if(nums[i] < nums[i - 1]) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + 1);
            }
        }

        return max(dp[n - 1][1], dp[n - 1][0]);
    }
};