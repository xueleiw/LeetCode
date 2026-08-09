#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <array>
using namespace std;
// 5-3 
// 2776ms  暴力
// class Solution {
//     public:
//         int subarraySum(vector<int>& nums, int k) {
//             int sum = 0, res = 0;
//             int n = nums.size();
            
//             for(int i = 0; i < n; i++) {
//                 sum = 0;
//                 for(int j = i; j < n; j++) {
//                     sum += nums[j];
//                     if(sum == k) {
//                         res++;
//                     }
//                 }
//             }

//             return res;
//         }
//     };

// 30ms 前缀和 + 哈希表
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            int res = 0;
            int sum = 0;

            mp[0] = 1; // 前缀和为0的情况有初始化的时候就一个
            for(int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                if(mp.count(sum - k)) {
                    res += mp[sum - k];
                }
                mp[sum]++;
            }

            return res;
        }
    };