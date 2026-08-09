#include <iostream>
#include <vector>
using namespace std;


// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int i = 0, j = height.size() - 1;
//         int res = 0;
//         int left = 0, right = 0;
//         while(i < j) {
//             left = max(left, height[i]);
//             right = max(right, height[j]);

//             if(left < right) {
//                 res += left - height[i];
//                 i++;
//             } else {
//                 res += right - height[j];
//                 j--;
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        int res = 0;

        for(int i = 0; i < n; i++) {
            if(nums1[0] == nums2[i]) {
                dp[0][i] = 1;
                res = 1;
            }
        }

        for(int i = 0; i < m; i++) {
            if(nums2[0] == nums1[i]) {
                dp[i][0] = 1;
                res = 1;
            }
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};