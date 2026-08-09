// 4-8
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;


// 73ms 理解dp[i]：当前i位置的最长子序列的值 O(n ^ 2)
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            vector<int> dp(nums.size() + 1, 1);
            int res = 0;

            for(int i = 0; i < nums.size(); i++) {
                for(int j = 0; j < i; j++) {
                    if(nums[i] > nums[j]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }

            for(int i = 0; i < nums.size(); i++) {
                res = max(res, dp[i]);
            }

            return res;
        }
    };