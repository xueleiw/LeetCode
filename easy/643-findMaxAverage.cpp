#include<iostream>
#include<vector>
using namespace std;
// 26/8/9


// 首先会考虑滑动窗口来解决； 换个思路用前缀和其实也能解
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        const int N = nums.size();
        int sum = 0;
        int l = 0;
        double res = (double)INT_MIN;

        for(int i = 0; i < N; i++) {
            if(i - l + 1 <= k) {
                sum += nums[i];
            } else {
                res = max(res, double(sum) / k);
                sum -= nums[l];
                l++;
                sum += nums[i];
            }
            // sum += nums[i];
            // if(i - l + 1 == k) {
            //     res = max(res, double(sum) / k);
            //     sum -= nums[l];
            //     l++;
            // }
        }
        // 最后一次处理边界
        res = max(res, double(sum) / k);

        return res;
    }
};

// 使用前缀和的方法
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<int> sum(N + 1, 0);
        double res = (double)INT_MIN;

        for(int i = 1; i <= N; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        for(int i = k - 1; i < N; i++) {
            res = max(res, double(sum[i + 1] - sum[i - k + 1]) / k);
        }

        return res;
    }
};