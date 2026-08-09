#include<iostream>
#include<vector>
using namespace std;
// 4-17


class Solution {
    public:
        void qsort(vector<int> &nums, int l, int r) {
            if(l >= r) return;

            int i = l - 1, j = r + 1; // ###// 超出边界选择
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

            qsort(nums, l, j);
            qsort(nums, j + 1, r);
        }

        vector<int> sortArray(vector<int>& nums) {
            qsort(nums, 0, nums.size() - 1);
            return nums;
        }
    };



