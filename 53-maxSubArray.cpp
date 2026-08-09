/**
 * 2024-12-23
 * 1- 前缀和 + 差分 复杂度太高
 * 2- 动态规划
 */ //: $$$

#include<bits/stdc++.h>
using namespace std;

/*========= 1:前缀和，双循环不能通过OJ===============*/
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum[500004], a[500004];
//         int result = -1e5;
//         memset(sum, 0, sizeof(sum));
//         memset(a, 0, sizeof(a));
//         for(int i = 0; i < nums.size(); i++) {
//             a[i + 1] = nums[i];
//         }
//         for(int i = 1; i <= nums.size(); i++) {
//             sum[i] = sum[i - 1] + a[i];
//         }
//         //
//         for(int i = 1; i <= nums.size(); i++) {
//             for(int j = i; j <= nums.size(); j++) {
//                 result = max(result, sum[j] - sum[i - 1]); // a[i]~a[j] 的区间和
//             }
//         }
//         return result;
//     }
// };

/*=============动态规划: 4ms===================*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int a[500005];
        // memset(a, 0, sizeof(a));
        int result = nums[0];
        int res = result;
        for(int i = 1; i < nums.size(); i++) {
            if(result + nums[i] > nums[i]) {
                result += nums[i];
            } else {
                result = nums[i];
            }
            res = max(res, result);
            //cout << result << ' ';
        }
        return res;
    }
};

int main() {
    vector<int> A = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solu;
    cout << solu.maxSubArray(A);
    return 0;
}