#include<iostream>
#include<vector>
using namespace std;
// 4-19
// 找两个有序数组中的第 k 小的数，其中 k 为 (m+n)/2 或 (m+n)/2+1。
// 比较两个数组的 k/2 - 1位置的数，谁小就排除小的那部分数，然后更新K的值  --  O(log(m + n))
// 45 ms
class Solution {
    public:
        int delivery(vector<int>& nums1, vector<int>& nums2, int k, int m, int n) {
            int start1 = 0, start2 = 0;
            // 需要注意超出边界问题，k=1的问题
            while(1) {
                // 处理边界，k=1的情况
                
                if(start1 == m) {
                    return nums2[start2 + k - 1];
                }
                if(start2 == n) {
                    return nums1[start1 + k - 1];
                }
                cout << start1 << ' ' << start2 << endl;
                if(k == 1) {
                    // cout << "ss" << endl;
                    return min(nums1[start1], nums2[start2]);
                }
                

                // 正常情况,开始比较值
                int new1 = min(start1 + k/2 - 1, m - 1);
                int new2 = min(start2 + k/2 - 1, n - 1);
                int x = nums1[new1];
                int y = nums2[new2];
                if(x < y) {
                    k = k - (new1 - start1 + 1);
                    start1 = new1 + 1;
                } else {
                    k = k - (new2 - start2 + 1);
                    start2 = new2 + 1;
                }
               
            }

        }

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size();
            int n = nums2.size();
            if((m + n) % 2 == 1) {
                return delivery(nums1, nums2, (m + n) / 2 + 1, m, n);
            } else {
                int x = delivery(nums1, nums2, (m + n) / 2, m, n);
                int y = delivery(nums1, nums2, (m + n) / 2 + 1, m, n);
                return (x + y) / 2.0;
            }
        }
    };



// 归并排序之后找出中位数 O(m + n)  88 ms
// class Solution {
//     public:
        
//         double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//             int m = nums1.size();
//             int n = nums2.size();
//             vector<int> tmp;
//             int i = 0, j = 0;
//             while(i < m && j < n) {
//                 if(nums1[i] < nums2[j]) {
//                     tmp.push_back(nums1[i]);
//                     i++;
//                 } else {
//                     tmp.push_back(nums2[j]);
//                     j++;
//                 }
//             }
//             if(i < m) {
//                 for(i; i < m; i++) {
//                     tmp.push_back(nums1[i]);
//                 }
//             }
//             if(j < n) {
//                 for(j; j < n; j++) {
//                     tmp.push_back(nums2[j]);
//                 }
//             }
//             for(i = 0; i < tmp.size(); i++) {
//                 cout << tmp[i] << ' ';
//             }
//             // tmp.insert(tmp.end(), nums1.begin(), nums1.end()); // 追加
//             // tmp.insert(tmp.end(), nums2.begin(), nums2.end());
//             if((m + n) % 2 == 0) {
//                 return (tmp[(m + n) / 2] + tmp[(m + n) / 2 - 1]) / 2.0;
//             } else {
//                 return tmp[(m + n) / 2];
//             }
//         }
//     };
