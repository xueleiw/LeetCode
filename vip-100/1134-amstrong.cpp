#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<math.h>
using namespace std;
// 4-18

class Solution {
    public:
        bool isArmstrong(int n) {
            int k = 0, sum = 0;
            int tmp = n;
            while(tmp > 0) {
                k++;
                tmp = tmp / 10;
            }

            tmp = n;
            while(tmp > 0) {
                sum += pow(tmp % 10, k);
                tmp = tmp / 10;
            }
            
            // cout << k << ' ' << sum << endl;
            if(sum == n) {
                
                return true;
            } else {
                return false;
            }

        }
    };
