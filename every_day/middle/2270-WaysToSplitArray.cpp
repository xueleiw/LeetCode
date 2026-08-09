/**
 * 2025-1-13
 * 1-：目的是求左区间的和大于右区间，使用前缀和处理即可
 */


#include<iostream>
#include<vector>
using namespace std;


/*================1-: 0ms=====================*/
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // 输入满足数组不为空，无需考虑
        int res = 0;
        long long a[nums.size() + 5]; // ==========> 求和之后会超出int的范围
        a[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
            a[i + 1] = nums[i] + a[i]; // 前缀和
        }

        for(int i = 1; i < nums.size(); i++) {
            if(a[i] >= a[nums.size()] - a[i]) {
                res++;
            }
        }

        return res;
    }
};


int main() {

    return 0;
}