/**
 * 2024-12-28
 * 1-: 数据量较小，所以先排序，每两个一组进行判断，直到找到不同的数据
 * 2-: 异或运算可以在O(1)的空间和O(n)的时间复杂度下实现，具有很强的技巧性
 */ //$

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*==========1-: 7ms===============*/
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int i = 0;
//         for(i = 0; i < nums.size() - 1; i = i + 2) {
//             if(nums[i] != nums[i + 1]) { // 如果两个数不同的话只可能是前面的数不相同
//                 return nums[i];
//             }
//         }
//         return nums[nums.size() - 1]; // 如果循环到了最后说明最后一个数就是出现一次的数
//     }
// };

/*==========2-: 0ms===============*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(auto e: nums) {
            ret ^= e;
        }
        return ret;
    }
};

int main() {

    Solution solu;
    vector<int> x = {1, 0, 1};
    cout << solu.singleNumber(x);

    return 0;
}