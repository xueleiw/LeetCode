/** 2024-12-24
 * 1-标准的折半查找模版;需要在最后判断一下target应该插入的位置是区间左边，右边，还是中间。
 * 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        while(left + 1 < right) {
            mid = (left + right) / 2;
            if(target == nums[mid]) return mid;
            if(target < nums[mid]) {
                right = mid;
            }else {
                left = mid;
            }
        }
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        if(target < nums[left]) return left;
        if(target > nums[right]) return right + 1;
        return left + 1;
    }
};

int main() {
    vector<int> A = {1, 3, 5, 6};
    Solution solu;
    cout << solu.searchInsert(A, 2);

    return 0;
}