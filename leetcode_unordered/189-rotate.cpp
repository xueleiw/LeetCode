#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <array>
#include <queue>
using namespace std;
// 5-3
// 首先翻转数组，然后把前k个和后n-k个分别翻转就得到了结果
class Solution {
    public:
        void rev(vector<int>& a, int l, int r) { // 从 l - r进行翻转
            while(l < r) {
                swap(a[l], a[r]);
                l++;
                r--;
            }
            return;
        }
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            k %= n;
            if(k == 0) return;

            reverse(nums.begin(), nums.end());
            rev(nums, 0, k - 1);
            rev(nums, k, n - 1);
            return;
        }
    };