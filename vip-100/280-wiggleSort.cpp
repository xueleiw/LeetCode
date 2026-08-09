#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
// 4-18
// 7 ms
// class Solution {
//     public:
//         void wiggleSort(vector<int>& nums) {
//             if(nums.size() == 1) return;

//             sort(nums.begin(), nums.end());
//             vector<int> tmp(nums.begin(), nums.end());

//             int i = 0, j = nums.size() - 1, k = 0;
//             while(i < j) {
//                 nums[k] = tmp[i];
//                 i++;k++;
//                 nums[k] = tmp[j];
//                 j--;k++;
//             }
//             if(nums.size() % 2 != 0) {
//                 nums[k] = tmp[i];
//             }


//             return;
//         }
//     };

//  贪心算法，O(n) 确实快
class Solution { 
    public:
        void wiggleSort(vector<int>& nums) {
            for(int i = 0; i < nums.size() - 1; i++) {
                if(i % 2 == 0 && nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                }
                if(i % 2 == 1 && nums[i] < nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                }
            }

        }
    };

