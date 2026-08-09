/**
 * @file 912-sorrtArray.cpp
 * @brief LeetCode 912. Sort an Array
 * @version 1.0
 * @date 2026-8-8
 * @copyright Copyright (c) 2023
 */ 

#include <iostream>
#include <vector>
#include <random>
using namespace std;


class Solution {
public:
    void quickSort(vector<int>& nums, int l, int r) {
        if(l >= r) {
            return;
        }

        // 取中间
        // int privot = nums[(l + r) / 2];
        // 取随机数
        int privot = nums[(rand() % (r - l + 1)) + l];
        int left = l;
        int right = r;
        while(true) {
            while(nums[left] < privot) {
                left++;
            }
            while(nums[right] > privot) {
                right--;
            }
            if(left < right) {
                swap(nums[left], nums[right]);
                left++;right--;  // 关键的是这里，为了防止死循环一直交换，需要在每次交换完之后进1
            } else {
                break;
            }
        }
        quickSort(nums, l, right);
        quickSort(nums, right + 1, r);
        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;  // 会拷贝出一个全新的对象
    }
};


int main() {
    Solution* solu = new Solution();
    vector<int> nums = {5,1,1,2,0,0};
    vector<int> res = solu->sortArray(nums);

    for(auto &x: nums) {
        cout << x << ' ';
    }
    return 0;
}