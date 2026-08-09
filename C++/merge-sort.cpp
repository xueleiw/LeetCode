#include<iostream>
#include<vector>
using namespace std;
// 4-15
// 300ms
class Solution {
    public:
        void merge(vector<int>& a, int l, int mid, int r) {
            vector<int> tmp(r - l + 1, 0);
            int i = l, j = mid + 1, k = 0;
            while(i <= mid && j <= r) {
                if(a[i] < a[j]) {
                    tmp[k++] = a[i++];
                } else {
                    tmp[k++] = a[j++];
                }
            }
            // 可能没合并完
            while(i <= mid) {
                tmp[k++] = a[i++];
            }
            while(j <= r) {
                tmp[k++] = a[j++];
            }
            // 放到原数组中
            k = 0;
            for(i = l; i <= r; i++) {
                a[i] = tmp[k++];
            }
        }

        void mergesort(vector<int> &nums, int l, int r) {
            if(l < r) {
                int mid = (l + r) / 2; // 向下取整
                mergesort(nums, l, mid);
                mergesort(nums, mid + 1, r);
                merge(nums, l, mid, r); // 把两个有序数组合并
            }
        }

        vector<int> sortArray(vector<int>& nums) {
            mergesort(nums, 0, nums.size() - 1);
            return nums;
        }
    };

int main() {


    return 0;
}
