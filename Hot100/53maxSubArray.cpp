#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include <unordered_set>
using namespace std;
// 4-20
// 4ms
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int res = INT_MIN;
            int tmp = 0;
            for(int i = 0; i < nums.size(); i++) {
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
