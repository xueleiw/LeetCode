/**
 * 2025-3-23
 * 1-： 直接合并然后排序O(nlogn)
 * 2-： 双指针但是需要额外的空间 O(m + n)
 * 3-： 逆向双指针无需额外空间
 */ // 

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
using namespace std;


/*===============1-: 0ms=====================*/
// class Solution {
//     public:
//         void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//             for(int i = m; i <= m + n - 1; i++) {
//                 nums1[i] = nums2[i - m];
//             }
//             sort(nums1.begin(), nums1.end());
//         }
//     };

/*===============2-: 0ms=====================*/
// class Solution {
//     public:
//         void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//             vector<int> tmp(m + n);
//             int p = 0, q = 0;
//             int i = 0;

//             while(p < m && q < n) {
//                 if(nums1[p] > nums2[q]) {
//                     tmp[i++] = nums2[q];
//                     q++;
//                 } else {
//                     tmp[i++] = nums1[p];
//                     p++;
//                 }
//             }
//             if(p != m) {
//                 for(p; p < m; p++) {
//                     tmp[i++] = nums1[p];
//                 }
//             }
//             if(q != n) {
//                 for(q; q < n; q++) {
//                     tmp[i++] = nums2[q];
//                 }
//             }

//             for(int i = 0; i < tmp.size(); i++) {
//                 nums1[i] = tmp[i];
//             }
//         }
//     };

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int j = m + n - 1; // 从nums1的最后面倒着放，就不用额外空间了
            int p = m - 1, q = n - 1;
            while(p >= 0 && q >= 0) {
                if(nums1[p] > nums2[q]) {
                    nums1[j--] = nums1[p];
                    p--;
                } else {
                    nums1[j--] = nums2[q];
                    q--;
                }
            }

            // 还有剩的没排完
            if(p >= 0) {
                for(p; p >= 0; p--) {
                    nums1[j--] = nums1[p];
                }
            }
            if(q >= 0) {
                for(q; q >= 0; q--) {
                    nums1[j--] = nums2[q];
                }
            }
        }
    };

int main() {

    return 0;
}
 