#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 2025-4-2
// 11ms 简单模拟，需注意连续数字相同的情况
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if(nums.size() < 2) return nums.size();

            int res = 1;
            int tmp = 1;
            sort(nums.begin(), nums.end());

            for(int i = 0; i < nums.size() - 1; i++) {
                if(nums[i] + 1 == nums[i + 1]) {
                    // cout << "1111  " << i << endl;
                    tmp++;
                } else {
                    if(nums[i] != nums[i + 1]) {
                        // cout << "222  " << i << endl;
                        tmp = 1;
                    } else {
                        // cout << "3333  " << i << endl;
                    }
                }
                res = max(res, tmp);
            }

            return res;
        }
    };