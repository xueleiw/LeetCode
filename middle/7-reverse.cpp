#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include <unordered_set>
using namespace std;
// 4-20

class Solution {
    public:
        int reverse(int x) {
            bool isflag = false;
            long long res = 0;
            queue<int> st;

            if(x < 0) {
                if(x == INT32_MIN) return 0;
                x = -x;
                isflag = true;
            }

            while(x > 0) {
                int tmp = x % 10;
                x /= 10;
                st.push(tmp);
            }

            while(!st.empty()) {
                res *= 10;
                res += st.front();
                st.pop();
                if(res > INT32_MAX) {
                    return 0;
                }
            }

            if(isflag) {
                return -res;
            } else {
                return res;
            }

        }
    };
