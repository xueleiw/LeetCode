#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 2025-4-2
// 94ms  暴力求解
// class Solution {
//     public:
//         vector<int> twoSum(vector<int>& nums, int target) {
//             vector<int> res;
//             for(int i = 0; i < nums.size() - 1; i++) {
//                 for(int j = i + 1; j < nums.size(); j++) {
//                     if(nums[i] + nums[j] == target) {
//                         res.push_back(i);
//                         res.push_back(j);
//                         break;
//                     }
//                 }
//             }
            
//             return res;
//         }
//     };


// 3ms  哈希表，存储下标
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> res;
            unordered_map<int, int> my_map;

            for(int i = 0; i < nums.size() - 1; i++) {
                my_map[nums[i]] = i;
            }

            for(int i = 0; i < nums.size(); i++) {
                if(my_map.count(target - nums[i])) {
                    if(i != my_map[target - nums[i]]) {
                        res.push_back(i);
                        res.push_back(my_map[target - nums[i]]);
                        break;
                    }
                    
                }
            }
            
            return res;
        }
    };

int main() {


    return 0;
}