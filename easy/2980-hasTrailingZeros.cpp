#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
// 4-15 
// 奇偶性判断
class Solution {
    public:
        bool hasTrailingZeros(vector<int>& nums) {
            int count = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] % 2 == 0) {
                    count++;
                }
                
            }
            if(count >= 2) {
                return false;
            }
            return true;
        }
    };
