/**
 * 2025-1-12
 * 1-：递归算法超时--双指针递归
 * 2-：暴力解法也会超时
 * 3-：前缀和 + 哈希表 : 通过当前位置的前缀和 current_sum查找哈希表中 current_sum-k 的前缀和存在的次数，即可获得到当前位置满足要求的数组个数
 */


#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;

/*=========1-: 递归算法超时====================*/
// class Solution {
// public:
//     void search(vector<int>& nums, int k, int i, int j, int sum, map<int, int>& result) {
//         // cout << i << ' ' << j << endl;
//         if(i < j) {
//             sum -= nums[i];
//             if(sum == k) {
//                 cout << i << ' ' << j << endl;
//                 if(result.count(i + 1)) { //首先判断是否存在起点
//                     if(result[i + 1] == j) {
//                         // 如果已经在map里面则不重复计数
//                     } else {
//                         result.insert(pair<int, int>(i + 1, j));
//                     }
//                 } else {
//                     result.insert(pair<int, int>(i + 1, j));
//                 }
//             }
//             // search(nums, k, i++, j, res, sum); // 这句会发生死循环，并未传递修改后的值
//             search(nums, k, i + 1, j, sum, result);

//             sum += nums[i];
//             sum -= nums[j];
//             if(sum == k) {
//                 cout << i << ' ' << j << endl;
//                 if(result.count(i)) { //首先判断是否存在起点
//                     if(result[i] == j - 1) {
//                         // 如果已经在map里面则不重复计数
//                     } else {
//                         result.insert(pair<int, int>(i, j - 1));
//                     }
//                 } else {
//                     result.insert(pair<int, int>(i, j - 1));
//                 }
//             }
//             // search(nums, k, i, j--, res, sum);
//             search(nums, k, i, j - 1, sum, result);
//         }
//         return;
//     }
//     int subarraySum(vector<int>& nums, int k) {
//         int sum = 0;
//         int res = 0;
//         map<int, int> result;
//         for(int i = 0; i < nums.size(); i++) {
//             sum += nums[i];
//         }
//         if(sum == k) res++;

//         int i = 0, j = nums.size() - 1;
//         search(nums, k, i, j, sum, result);



//         return result.size() + res;
//     }
// };

/*================1-: 32ms=====================*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        hash_map.insert(pair<int, int>(0, 1)); // 默认前缀和为0的连续数组有一个
        int current_sum = 0;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            if(hash_map.count(current_sum - k)) { // 如果存在前缀和为current_sum - k的区间数组，说明到当前位置的连续数组是满足要求的
                count += hash_map[current_sum - k];
            }
            hash_map[current_sum]++;
        }

        return count;
    }
};

int main() {
    Solution solu;
    vector<int> x = {1};
    cout << solu.subarraySum(x, 1);
    return 0;
}