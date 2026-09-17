#include <iostream>
#include <vector>
#include <deque>
using namespace std;


// 0917 思路就是拿掉首尾单独做一次判断

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        bool flag = false;
        int res = 0;
        deque<int> q(nums.begin(), nums.end());
        vector<int> dp(n + 1, 0);
        dp[1] = q[0];
        if (n == 1) {
            return dp[n];
        }

        // dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        for(int i = 1; i < n; i++) {
            if (q[i] + dp[i - 1] > dp[i]) {
                dp[i + 1] = q[i] + dp[i - 1];
                if (i == n - 1) {
                    flag = true;
                }
            } else {
                dp[i + 1] = dp[i];
            }
        }

        if (flag) {
            int tmp = q[0];
            q[0] = 0;
            dp.assign(n + 1, 0);
            dp[1] = q[0];
            for(int i = 1; i < n; i++) {
                // dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
                dp[i + 1] = max(dp[i], q[i] + dp[i - 1]);
            }

            res = max(res, dp[n]);
            q[0] = tmp;
            tmp = q[n - 1];
            q[n - 1] = 0;
            dp.assign(n + 1, 0);
            dp[1] = q[0];
            for(int i = 1; i < n; i++) {
                dp[i + 1] = max(dp[i], q[i] + dp[i - 1]);
            }
            res = max(res, dp[n]);
            dp[n] = res;
        }
        
        return dp[n];
    }
};



int main() {
    Solution s;
    vector<int> nums = {2, 3, 2};
    int res = s.rob(nums);
    cout << res << endl;

    return 0;
}