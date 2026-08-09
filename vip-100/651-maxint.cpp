#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// 5-9



class Solution {
    public:
        int maxA(int n) {
            vector<int> dp(n + 1, 0);
            for(int i = 1; i <= n; i++) {
                if(i <= 3) {
                    dp[i] = i;
                } else {
                    if(i >= 7) {
                        dp[i] = max(dp[i - 1] + 1, dp[i - 1] + dp[i - 4]);
                        dp[i] = max(dp[i], dp[i - 3] * 2);
                    } else {
                        dp[i] = max(dp[i - 1] + 1, dp[i - 3] * 2);
                    }
                    
                }
            }
            
            return dp[n];
        }
    };


int main() {
    int x =2346543;
    string s = to_string(x);
    cout << s << endl;

    return 0;   
}