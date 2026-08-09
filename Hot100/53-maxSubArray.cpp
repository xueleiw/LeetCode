// 2025-4-5

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 3ms // 如果之前的和大于0的话就加上之前的和，如果小于0就认为会拉低当前元素，不加之前的和
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int tmp = nums[0];
            int res = nums[0];
            // 如果之前的和大于0的话就加上之前的和，如果小于0就认为会拉低当前元素，不加之前的和
            for(int i = 1; i < nums.size(); i++) {
                if(tmp + nums[i] > nums[i]) {
                    tmp += nums[i];
                } else {
                    tmp = nums[i];
                }

                res = max(res, tmp);
            }

            return res;
        }
    };