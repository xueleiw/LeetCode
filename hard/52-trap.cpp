/**
 * 2025-3-21
 * 1-： 按照每一列能存储的高度进行计算； 要求数组i位置可以存储的水量，
 *      需要先求出0到i位置的最大值max(arr[0...i])，再求出i到n-1位置的最大值max(arr[i...n-1])，两个值中取最小与arr[i]做差
 */ // $$$

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*===============1-: 0ms=====================*/
class Solution {
    public:
        int trap(vector<int>& height) {
            int left = 0, right = 0, leftmax = 0, rightmax = 0;
            int res = 0;
            right = height.size() - 1;
            while(left < right) {
                leftmax = max(leftmax, height[left]); // 如果当前的左值小于右值，那么leftmax一定小于rightmax
                rightmax = max(rightmax, height[right]);
                if(height[left] <= height[right]) {
                    res += leftmax - height[left];
                    left++;
                } else {
                    res += rightmax - height[right];
                    right--;
                }
            }

            return res;
        }
    };

int main() {
    Solution solu;
    vector<int> x = {4,2,0,3,2,5};
    cout << solu.trap(x);

    return 0;
}