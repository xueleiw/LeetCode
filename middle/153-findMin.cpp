/**
 * 2025-3-6
 * 1-：O(n)遍历很简单；用了二分查找之后就比较巧妙的变成O(logn)了
 */ //

#include<iostream>
#include<vector>
using namespace std;


/*================1-: 0ms=====================*/
class Solution {
    public:
        int findMin(vector<int>& nums) {
            int left = 0;
            int right = nums.size() - 1;
            while(left < right) {
                int mid = (left + right) / 2; // 如果中间值小于右值，那么右端点需要收缩，反之左区间需要收缩
                // int mid = left + (right - left) / 2;
                if(nums[mid] < nums[right]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return nums[left];
        }
    };

int main() {

    return 0;
}