#include <iostream>
#include <vector>
using namespace std;
// 4-28
// 0ms 快排一定是边界外溢的
class Solution {
    public:
        int qsort(vector<int> &nums, int l, int r, int k) {
            if(l == r) return nums[k];

            int i = l - 1, j = r + 1, privot = nums[(l + r) / 2];
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
            int res = qsort(nums, 0, nums.size() - 1, nums.size() - k);
            return res;
        }
    };