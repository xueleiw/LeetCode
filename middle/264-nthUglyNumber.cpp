#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
// 4-20 
// 99 ms

class Solution {
    public:
        int nthUglyNumber(int n) {
            priority_queue<long long, vector<long long>, greater<long long>> p; // 小根堆
            unordered_set<long long> s; // 乘法要用 long long 
            long long count = 0, tmp = 0;
            p.push(1);
            s.insert(1);

            while(count < n) {  // 从堆中取出的第n个数就是满足要求的，往堆里放的时候要去重
                tmp = p.top();
                count++;
                p.pop();
                if(!s.count(tmp * 2)) {
                    p.push(tmp * 2);
                    s.insert(tmp * 2);
                }
                if(!s.count(tmp * 3)) {
                    p.push(tmp * 3);
                    s.insert(tmp * 3);
                }
                if(!s.count(tmp * 5)) {
                    p.push(tmp * 5);
                    s.insert(tmp * 5);
                }
            }

            return tmp;
        }
    };

// 暴力超时
// class Solution {
//     public:
//         bool isugly(int x) {
//             vector<int> a = {2, 3, 5};
//             for(int i = 0; i < 3; i++) {
//                 while(x % a[i] == 0) {
//                     x /= a[i];
//                 }
//             }

//             return x == 1;
//         }

//         int nthUglyNumber(int n) {
//             int i = 1, count = 0, res = 0;

//             while(true) {
//                 if(isugly(i)) {
//                     count++;
//                     if(count == n) break;
//                 }
//                 i++;
//             }

//             return i;
//         }
//     };
