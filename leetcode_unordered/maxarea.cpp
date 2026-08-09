#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
// 5-3 双指针
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int l = 0, r = height.size() - 1;
            int res = 0;

            while(l < r) {
                int h = min(height[l], height[r]);
                // cout << r << " " << l;
                int tmp = (r - l) * h;
                res = max(res, tmp);
                if(height[l] < height[r]) {
                    l++;
                } else {
                    r--;
                }
            }

            return res;
        }
    };