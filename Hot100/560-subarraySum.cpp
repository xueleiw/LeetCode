// 2025-4-5

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;


// 36ms 利用哈希表进行优化，记录前缀和的时候记录pre[i] - k这个和是否存在过，如果存在说明从pre[i] - k这个点到现在这个点满足 区间和为K
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> my_map;
            my_map.insert(pair<int, int>(0, 1)); // 和为0的区间存在一个

            int count = 0;
            int sum = 0;
            for(int i = 0; i < nums.size(); i++) {
                sum += nums[i]; // 前缀和
                
                if(my_map.count(sum - k)) {
                    count += my_map[sum - k];
                }
                my_map[sum]++;
            }

            return count;
        }
    };


// 此题暴力应该不超时
// class Solution {
//     public:
//         int subarraySum(vector<int>& nums, int k) {
//             int count = 0;
//             for(int i = 0; i < nums.size(); i++) {
//                 int sum = 0;
//                 for(int j = i; j < nums.size(); j++) {
//                     sum += nums[j];
//                     if(sum == k) {
//                         count++;
//                     }
//                 }
//             }

//             return count;
//         }
//     };