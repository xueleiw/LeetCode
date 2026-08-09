/**
 * 2025-1-1
 * 1-: 该题的思想主要在于当前元素与后面所有元素发生一次交换或者选择不交换，然后通过递归实现
 * 
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/*===============1-: 0ms=====================*/
class Solution {
public:
    void perm(vector<int>& nums, int index, int len, vector<vector<int>>& res) {
        if(index == len - 1) {
            res.push_back(nums);
        }

        for(int i = index; i < len; i++) {
            swap(nums[index], nums[i]); // 当前元素和后面所有元素交换一遍
            perm(nums, index + 1, len, res);
            swap(nums[index], nums[i]); // 交换完之后保证数组不变，为了后续交换
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;

        perm(nums, 0, nums.size(), res);
        return res;
    }
};

int main() {

    return 0;
}