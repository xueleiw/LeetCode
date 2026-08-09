#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
//4-15

class Solution {
    public:
        int trap(vector<int>& height) {
            int l = 0, r = height.size() - 1;
            int left_max = height[0], right_max = height[r];
            int res = 0;

            while(l < r) {
                left_max = max(left_max, height[l]);
                right_max = max(right_max, height[r]);
                if(left_max < right_max) {
                    res += left_max - height[l];
                    l++;
                } else {
                    res += right_max - height[r];
                    r--;
                }
            }

            return res;
        }
    };

