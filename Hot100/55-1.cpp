#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include <unordered_set>
using namespace std;
// 4-20




class Solution {
    public:
        bool canJump(vector<int>& nums) {
            // vector<bool> vis(nums.size(), false);
            // vis[0] = true;
            int max_index = nums[0];

            for(int i = 0; i < nums.size(); i++) {
                if(max_index >= i) {
                    max_index = max(max_index, nums[i] + i);
                }
            }

            if(max_index >= nums.size() - 1) {
                return true;
            } else {
                return false;
            }
        }
    };