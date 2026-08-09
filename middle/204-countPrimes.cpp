#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
// 4-18
// 227 ms
// 埃氏筛
int a[5000005];
class Solution {
    public:
        int countPrimes(int n) {
            // 5 * 10 ^ 6
            int res = 0;

            a[2] = 0;
            for(long long i = 2; i < n; i++) {
                if(a[i] == 1) continue;
                for(long long j = i; i * j < n; j++) {
                    a[i * j] = 1; // 标记所有非质数
                }
            }
            //
            for(int i = 2; i < n; i++) {
                if(a[i] == 0) {
                    res++;
                }
            }

            return res;
        }
    };

// n * 根号(n) 的复杂度
class Solution {
    public:
        bool isPrime(int x) {
            for(int i = 2; i * i <= x; i++) {
                if(x % i == 0) return false;
            }
            
            return true;
        }

        int countPrimes(int n) {
            int res = 0;
            for(int i = 2; i < n; i++) {
                if(isPrime(i)) res++;
            }

            return res;
        }
    };
