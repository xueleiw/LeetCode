/**
 * 2024-12-18
 * 双指针：一次遍历即可
 */
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pa = 0, pb =0;
        while (pb < nums.size()) {
            if (nums[pb] != 0) {
                swap(nums[pa], nums[pb]);
                pa++;
            }
            pb++;
        }
    }
};

int main() {
    // vector<int> a = {0, 0, 1};
    vector<int> a = {1, 0, 0, 0, 0, 1, 0};
    Solution solu;
    solu.moveZeroes(a);
    for(int i = 0; i < a.size(); i++) {
        printf("%d ", a[i]);
    }

    return 0;
}