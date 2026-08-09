// 2025-4-5

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 0ms  双指针，维护一个左边的最大值，右边的最大值，然后算出每一列能够存储的雨水值
class Solution {
    public:
        int trap(vector<int>& height) {
            int left = 0, right = height.size() - 1, left_max = 0, right_max = 0;
            int res = 0;
            while(left != right) {
                left_max = max(left_max, height[left]);
                right_max = max(right_max, height[right]);
                if(height[left] < height[right]) {
                    res += left_max - height[left];
                    left++;
                } else {
                    res += right_max - height[right];
                    right--;
                }
            }

            return res;
        }
    };
