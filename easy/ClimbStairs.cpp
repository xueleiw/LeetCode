/**
 * 2024-12-27
 * 1-: 经典的dp，确定动态方程之后便可求解 dp[i] = dp[i-1] + dp[i-2]; dp[1] = 1; dp[2] = 2;
 */
#include<iostream>
#include<string.h>
using namespace std;

/*=======递归复杂度太高========*/
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n == 1) return 1;
//         if(n == 2) return 3;
//         return climbStairs(n-1) + climbStairs(n-2);
//     }
// };


/*============1-: 0ms=================*/
class Solution {
public:
    int climbStairs(int n) {
        int a[n + 5];
        memset(a, 0, sizeof(a));
        if(n == 1) return 1;
        if(n == 2) return 2;
        a[1] = 1;
        a[2] = 2;
        for(int i = 3; i <= n; i++) {
            a[i] = a[i - 1] + a[i - 2];
        }
        return a[n];
    }
};

int main() {
    Solution solu;
    cout << solu.climbStairs(3);

    return 0;
}