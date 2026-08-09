#include<iostream>
#include<vector>
using namespace std;
// 26/8/9

class NumArray {
private:
    vector<int> myNums;
public:
    NumArray(vector<int>& nums) {
        const int N = nums.size();
        myNums.resize(N + 1); // 默认初始化为0

        // 初始化前缀和，后续求区间和
        for(int i = 1; i <= N; i++) {
            myNums[i] = myNums[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        int res = myNums[right + 1] - myNums[left];
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */