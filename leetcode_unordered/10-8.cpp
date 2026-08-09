#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


// class Solution {
// public:
//     int qsort(vector<int>& nums, int l, int r, int k) {
//         if(l == r) {
//             return nums[k];
//         }
//         int mid = (l + r) / 2;
//         int p = nums[mid];
//         int i = l - 1;
//         int j = r + 1;
//         while(1) {
//             do{i++;}while(nums[i] < p);
//             do{j--;}while(nums[j] > p);
//             if(i < j) {
//                 swap(nums[i], nums[j]);
//             } else {
//                 break;
//             }
//         }

//         if(j < k) {
//             return qsort(nums, j + 1, r, k);
//         } else {
//             return qsort(nums, l, j, k);
//         }
        
//     }

//     int findKthLargest(vector<int>& nums, int k) {
//         int res = qsort(nums, 0, nums.size() - 1, nums.size() - k);
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int>  res(n, 0);
//         stack<int> st;

//         for(int i = 0; i < n; i++) {
//             if(st.empty()) {
//                 st.push(i);
//             } else {
//                 while(!st.empty()) {
//                     int x = st.top();
//                     if(temperatures[x] < temperatures[i]) {
//                         st.pop();
//                         res[x] = i - x;
//                     } else {
//                         break;
//                     }
//                 }
//                 st.push(i);
//             }
//         }

//         return res;
//     }
// };


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int res = 0;
//         int mi = INT_MAX;
//         int ma = INT_MIN;
//         int mi_index = 0;
//         int ma_index = 0;
//         for(int i = 0; i < prices.size(); i++) {
//             if(mi > prices[i]) {
//                 mi = prices[i];
//                 mi_index = i;
//             }
//             if(ma > prices[i]) {
//                 ma = prices[i];
//                 ma_index = i;
//             }
//             if(mi < ma && mi_index < ma_index) {
//                 res = max(res, ma - mi);
//             }
//             if(mi_index > ma_index) {
//                 ma = mi;
//                 ma_index = mi_index;
//             }

//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int position = nums[0];
//         int n = nums.size();
//         for(int i = 0; i < n && i <= position; i++) {
//             position = max(position, nums[i] + i);
//             if(position >= n - 1) return true;
//         }
//         return false;
//     }
// };

