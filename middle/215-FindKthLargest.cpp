/**
 * 2024-12-31
 * 1-: 经过sort排序之后直接输出第K大元素
 * 
 */

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;



/*==============1-: 24ms=============*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k]; //注意是第K大的，不是第K个顺序的元素
    }
};

int main() {
    Solution solu;
    vector<int> x = {2, 1, 3, 5, 4};
    cout << solu.findKthLargest(x, 2);
    return 0;
}