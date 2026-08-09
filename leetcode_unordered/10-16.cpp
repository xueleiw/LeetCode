#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> res;
//         unordered_map<int, int> mp;

//         for(int i = 0; i < nums.size(); i++) {
//             mp[nums[i]] = i;
//         }
//         for(int i = 0; i < nums.size(); i++) {
//             if(mp.count(target - nums[i]) && mp[target - nums[i]] != i) {
//                 res.push_back(i);
//                 res.push_back(mp[target - nums[i]]);
//                 break;
//             }
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> mp;
//         vector<vector<string>> res;

//         for(int i = 0; i < strs.size(); i++) {
//             string s = strs[i];
//             sort(s.begin(), s.end());

//             if(mp.count(s)) {
//                 mp[s].push_back(strs[i]);
//             } else {
//                 mp[s].push_back(strs[i]);
//             }
//         }

//         // for(auto& x: mp) {
//         //     vector<string> tmp;
//         //     for(int i = 0; i < x.second.size(); i++) {
//         //         tmp.push_back(x.second[i]);
//         //     }
//         //     res.push_back(tmp);
//         // }
//         for(auto& x: mp) {
            
//             res.push_back(x.second);
//         }
//         return res;
//     }
// };


// [100,4,200,1,3,2]
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         // unordered_map<int, int> mp;
//         // vector<bool> vis(nums.size(), false);
//         unordered_set<int> mp;

//         for(int i = 0; i < nums.size(); i++) {
//             // if(!mp.count(nums[i])) mp[nums[i]] = i;
//             mp.insert(nums[i]);
//         }

//         int res = 0;
//         for(auto& x: mp) {
//             int num = x + 1;
//             int tmp = 1;
//             if(mp.count(x - 1)) {

//             } else {
//                 while(mp.count(num)) {
//                     num++;
//                     tmp++;
//                 }
//             }
//             res = max(res, tmp);
//         }

//         return res;
//     }   
// };

// [0,1,0,3,12]   
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
//         int i = 0, j = 0;
        
//         while(i < n && j < n) {
//             while(nums[j] == 0 && j < n) {
//                 j++;
//             }
//             if(j < n) {
//                 nums[i] = nums[j];
//                 i++;
//                 j++;
//             }
//         }
//         for(i; i < n; i++) {
//             nums[i] = 0;
//         }

//         return;
//     }
// };