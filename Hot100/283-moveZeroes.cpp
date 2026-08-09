#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 2025-4-2
// 76ms  双循环往后放，注意及时终止
class Solution {
    public:
        
        void moveZeroes(vector<int>& nums) {
            for(int i = 0; i < nums.size() - 1; i++) {
                if(nums[i] == 0) {
                    for(int j = i + 1; j < nums.size(); j++) {
                        if(nums[j] != 0) {
                            swap(nums[i], nums[j]);
                            break;
                        }
                        
                    }
                }
                
            }
        }
    };