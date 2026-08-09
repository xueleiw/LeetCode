/**
 * 2025-3-29
 * 1-: 这道题的精髓在于长度为n的全0数组，按照题目要求可以返回的个数是 res = n + (n - 1) + (n - 2) + ... + 2 + 1
 */

#include<iostream>
#include<vector>
using namespace std;

/*===============1-: 4ms=====================*/
class Solution {
    public:
        long long zeroFilledSubarray(vector<int>& nums) {
            long long res = 0;
            long long count = 0;
            bool prev = true;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0) {
                    count++;
                    res += count;
                } else {
                    count = 0;
                }
            }
            return res;
        }
    };

int main() {


    return 0;
}