/**
 * 2025-3-11
 * 1-：递归O(2 ^ n)
 * 2-: dp O(n)
 */

#include<iostream>
#include<vector>
using namespace std;


/*================1-: 15ms=====================*/
// class Solution {
//     public:
//         int fi(int n) {
//             if(n < 2) return n;

//             return fi(n - 1) + fi(n - 2);
//         }

//         int fib(int n) {
//             return fi(n);
//         }
//     };

/*================1-: 0ms=====================*/
class Solution {
    public:

        int fib(int n) {
            if(n < 2) return n;
            vector<int> a(n + 1);
            a[0] = 0;
            a[1] = 1;
            for(int i = 2; i <= n; i++) {
                a[i] = a[i - 1] + a[i - 2];
            }
            return a[n];
        }
    };


int main() {

    return 0;
}