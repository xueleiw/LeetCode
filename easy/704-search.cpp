#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
// 4-15 0ms


// class Solution {
//     public: 
//         int search(vector<int>& nums, int target) {
//             int l = 0, r = nums.size();
//             while(l < r) {
//                 int mid = (l + r) / 2;
//                 // cout << l << " " << r << " " << mid << " ";
//                 if(nums[mid] > target) {
//                     r = mid;
//                 } else if(nums[mid] < target) {
//                     l = mid + 1;
//                 } else {
//                     return mid;
//                 }
//             }

//             return -1;
//         }
//     };

// 26/8/9  左闭右开区间
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int l = 0, r = nums.size();   // 保证初始条件，即只有一个元素时
//         int mid = (l + r) / 2;
//         while(l < r) {
//             if(nums[mid] == target) {
//                 return mid;
//             }
//             if(nums[mid] > target) {
//                 r = mid;
//             } else {
//                 l = mid + 1;
//             }
//             mid = (l + r) / 2;
//         }

//         return -1;
//     }
// };

// 左右都是闭区间
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int l = 0, r = nums.size() - 1;
//         int mid = (l + r) / 2;
//         while(l <= r) {
//             if(nums[mid] == target) {
//                 return mid;
//             }
//             if(nums[mid] > target) {
//                 r = mid - 1;
//             } else {
//                 l = mid + 1;
//             }
//             mid = (l + r) / 2;  // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//         }
        
//         return -1;
//     }
// };

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        int mid = (l + r) / 2;
        while(l < r) {
            
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] < target) {
                l = mid + 1;
                // mid = (l + r) / 2;
            } else {
                r = mid;
                
            }
            mid = (l + r) / 2;
        }

        return -1;
    }
};