#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
// 5-3

// 双指针  4ms
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int l = 0, r = 0;
            while(r < nums.size()) {
                if(nums[r] != 0) {
                    swap(nums[l], nums[r]);
                    l++;
                }
                r++;
            }
        }
    };

// 62ms
// class Solution {
//     public:
//         void moveZeroes(vector<int>& nums) {
//             for(int i = 0; i < nums.size() - 1; i++) {
//                 if(nums[i] != 0) continue;
//                 for(int j = i + 1; j < nums.size(); j++) {
//                     if(nums[j] != 0) {
//                         swap(nums[i], nums[j]);
//                         break;
//                     }
//                 }
//             }
//         }
//     };