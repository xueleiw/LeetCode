#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
// 5-3

class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            int l_m = height[0], r_m = height[n - 1];
            int l = 0, r = n - 1;
            int res = 0;

            while(l < r) {
                l_m = max(l_m, height[l]);
                r_m = max(r_m, height[r]);
                if(l_m < r_m) {
                    res += l_m - height[l];
                    l++;
                } else {
                    res += r_m - height[r];
                    r--;
                }
            }
            
            return res;
        }
    };