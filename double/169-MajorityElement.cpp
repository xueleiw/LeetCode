/**
 * 2025-1-6
 * 1-: 既然最多数一定比一半数量多，排序之后取中间的数即可
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*=================1-: 3ms=============================*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

int main() {
    Solution solu;
    return 0;
}