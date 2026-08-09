#include<iostream>
#include<vector>
using namespace std;
// 4-20 
// 0ms


class Solution {
    public:
        bool isUgly(int n) {
            if(n <= 0) return false;
            while(n > 0) {
                bool flag = true;
                if(n % 2 == 0) {
                    flag = false;
                    n /= 2;
                }
                if(n % 3 == 0) {
                    flag = false;
                    n /= 3;
                  
                } 
                if(n % 5 == 0) {
                    flag = false;
                    n /= 5;
                    
                }
                if(n == 1) return true; // 说明是丑数
                if(flag) {
                    return false;// 说明一次都没有除
                }

            }

            return true;
        }
    };
