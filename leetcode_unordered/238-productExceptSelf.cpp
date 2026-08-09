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
// 前缀和
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> res;
            vector<int> p(n + 2, 1);
            vector<int> b(n + 2, 1);

            for(int i = 1; i <= n; i++) {
                p[i] = p[i - 1] * nums[i - 1];
            }
            for(int j = n; j >= 1; j--) {
                b[j] = b[j + 1] * nums[j - 1];
            }
            for(int i = 1; i <= n; i++) {
                res.push_back(p[i - 1] * b[i + 1]);
            }

            return res;
        }
    };