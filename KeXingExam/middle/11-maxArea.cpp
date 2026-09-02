#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 0902
// 双指针：如果左边的高度小于右边左指针++，反之右指针--

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int left = 0;
        int right = height.size() - 1;

        while(left < right) {
            res = max(res, (right - left) * min(height[left], height[right]));
            if(height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return res;
    }
};