#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include <unordered_set>
#include<algorithm>
using namespace std;
// 4-20 期望为 O(n) ，证明过程很繁琐
// 0ms 利用快排的思想，只排序前K个元素
class Solution {
    public:
        void qsort(vector<int>& arr, int l, int r, int k) {
            if(l >= r) return;
            int i = l - 1, j = r + 1;
            int pt = arr[(l + r) / 2];
            while(true) {
                do{i++;} while(arr[i] < pt);
                do{j--;} while(arr[j] > pt);
                if(i < j) {
                    swap(arr[i], arr[j]);
                } else {
                    break;
                }
            }

            if(k <= j) {
                return qsort(arr, l, j, k);
            } else {
                return qsort(arr, j + 1, r, k);
            }
        }

        vector<int> smallestK(vector<int>& arr, int k) {
            qsort(arr, 0, arr.size() - 1, k);
            vector<int> res(arr.begin(), arr.begin() + k);
            return res;
        }   
    };

// 7ms 排序之后直接返回
// class Solution {
//     public:
//         vector<int> smallestK(vector<int>& arr, int k) {
//             sort(arr.begin(), arr.end());
//             vector<int> res(arr.begin(), arr.begin() + k);
//             return res;
//         }
//     };