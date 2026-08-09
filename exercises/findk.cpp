#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
// 4-17

class Solution {
    public:
        int qsort(vector<int>& nums, int l, int r, int k) {
            if(l == r) return nums[k]; // 找到了第k个位置

            int i = l - 1, j = r + 1;
            int privot = nums[(l + r) / 2];
            while(true) {
                do{i++;} while(nums[i] < privot);
                do{j--;} while(nums[j] > privot);
                if(i < j) {
                    swap(nums[i], nums[j]);
                } else {
                    break;
                }
            }
            if(k <= j) {
                return qsort(nums, l, j, k);
            } else {
                return qsort(nums, j + 1, r, k);
            }
        }
        int findKthLargest(vector<int>& nums, int k) {
            int res = qsort(nums, 0, nums.size() - 1, nums.size() - k); // 第k个最大
            return res;
        }
    };