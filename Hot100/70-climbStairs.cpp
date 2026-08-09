// 4-7
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;


// 0ms   dp 
// class Solution {
//     public:
//         int climbStairs(int n) {
//             if(n <= 2) return n;
//             vector<int> a(n + 1, 0);
//             a[1] = 1;
//             a[2] = 2;
//             for(int i = 3; i <= n; i++) {
//                 a[i] = a[i - 1] + a[i - 2];
//             }

//             return a[n];
//         }
//     };


// 递归超时了
class Solution {
    public:
        int backtrace(int n) {
            if(n <= 2) return n;
            return backtrace(n - 1) + backtrace(n - 2);
        }
        int climbStairs(int n) {
            return backtrace(n);
        }
    };