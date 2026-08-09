#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
// 5-12

// 0ms
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0; int index = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                count++;
            } else {
                index = i;
                break;
            }
        }
        if(count >= k) {
            for(int i = 0; i < k; i++) {
                nums[i] = -nums[i];
            }
        } else {
            for(int i = 0; i < count; i++) {
                nums[i] = -nums[i];
            }
            sort(nums.begin(), nums.end());
            for(int i = 0; i < (k - count); i++) {
                nums[0] = -nums[0];
            }
        }
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        return sum;
    }
};

