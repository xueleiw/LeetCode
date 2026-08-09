#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
// 5-3


// 超时版本
// class Solution {
//     public:
//         int longestConsecutive(vector<int>& nums) {
//             unordered_set<int> st(nums.begin(), nums.end());
//             int res = 0;

//             for(int i = 0; i < nums.size(); i++) {
//                 int tmp = 1;
//                 if(st.count(nums[i] - 1)) {
//                     continue; // 说明不是头
//                 } else {
//                     int num = nums[i];
//                     while(st.count(num + 1)) {
//                         tmp++;
//                         num++;
//                     }
//                 }
//                 res = max(res, tmp);
//             }

//             return res;
//         }
//     };


// 91ms
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> st(nums.begin(), nums.end());
            int res = 0;

            for(auto &x: st) {
                int tmp = 1;
                if(st.count(x - 1)) {
                    continue; // 说明不是头
                } else {
                    int num = x;
                    while(st.count(num + 1)) {
                        tmp++;
                        num++;
                    }
                }
                res = max(res, tmp);
            }

            return res;
        }
    };