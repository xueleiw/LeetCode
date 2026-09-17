#include <iostream>
#include <vector>
using namespace std;


// 0917
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        int mid = (l + r) / 2;

        while (l < r) {
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
            mid = (l + r) / 2;
        }

        return -1;
    }
};