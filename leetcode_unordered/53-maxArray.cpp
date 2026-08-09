#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <array>
#include <queue>
using namespace std;
// 5-3


class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int res = INT_MIN;
            int sum = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(sum + nums[i] > nums[i]) {
                    sum += nums[i];
                } else {
                    sum = nums[i];
                }

                res = max(res, sum);
            }
            return res;
        }
    };