#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;


// 0917

class Solution {
    public:
        void qsort(vector<int>& nums, const int l, const int r) {
            if (l >= r) {
                return;
            }

            // int pivot = nums[(l + r) / 2];
            int pivot = nums[l + rand() % (r - l + 1)];
            int left = l - 1;
            int right = r + 1;
            while (left < right) {
                do {left++;}while(nums[left] < pivot);
                do{right--;}while(nums[right] > pivot);
                if (left < right) {
                    swap(nums[left], nums[right]);
                }
            }
            qsort(nums, l, right);
            qsort(nums, right + 1, r);
        }

        vector<int> sortArray(vector<int>& nums) {
            if (nums.empty()) {
                return nums;
            }
            qsort(nums, 0, nums.size() - 1);

            return nums;
        }
};

int main() {
    Solution s;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> res = s.sortArray(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}