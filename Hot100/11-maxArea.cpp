#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 2025-4-2
// 0ms  双指针，谁小谁移动  
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int l = 0, r = height.size() - 1;
            int res = 0;

            while(l < r) {
                res = max(res, (r - l) * min(height[l], height[r]));
                if(height[l] < height[r]) {
                    l++;
                } else {
                    r--;
                }
            }

            return res;
        }
    };