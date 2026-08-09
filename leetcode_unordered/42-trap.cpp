#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// 4-28


class Solution {
    public:
        int trap(vector<int>& height) {
            int i = 0, j = height.size() - 1;
            int left_max = height[0];
            int right_max = height[j];
            int res = 0;

            while(i < j) {
                left_max = max(left_max, height[i]);
                right_max = max(right_max, height[j]);
                
                if(left_max < right_max) {
                    res += left_max - height[i];
                    i++;
                } else {
                    res += right_max - height[j];
                    j--;
                }
            }

            return res;

        }
    };


