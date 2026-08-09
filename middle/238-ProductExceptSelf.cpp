/**
 * 2025-1-3
 * 1-: 通过两个数组存正向乘积（前缀积）和反向乘积；这样当前元素左右两边的乘积便可轻松得到，以O(n) 时间解决；
 * 2-：如何通过O(1) 的空间实现该题？
 */

#include<iostream>
#include<vector>
using namespace std;


/*===============1-: 0ms=====================*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(nums.size());
        int a[n + 5]; // 正向前缀乘积
        int b[n + 5]; // 反向前缀乘积
        a[0] = 1;
        b[n] = 1;

        for(int i = 0; i < n; i++) {
            a[i + 1] = a[i] * nums[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            b[i] = b[i + 1] * nums[i];
        }

        for(int i = 0; i < n; i++) {
            res[i] = a[i] * b[i + 1];
        }

        return res;

    }
};

int main() {
    vector<int> x = {1, 2, 3, 4};
    Solution solu;
    vector<int> res = solu.productExceptSelf(x);
    for(auto x: res) {
        cout << x << ' ';
    }

    return 0;
}