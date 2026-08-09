#include<iostream>
#include<vector>
using namespace std;
// 4-24 300ms

class Solution {
    public:
        string longestPalindrome(string s) {
            if(s.length() <= 1) return s;
            int n = s.length();
            vector<vector<int>> dp(n, vector<int>(n, 0));
            int length = 1, start = 0; // 最坏的情况下返回第一个字符

            for(int i = 0; i < n; i++) {
                dp[i][i] = 1;
            }

            for(int i = n - 2; i >= 0; i--) { // i < j
                for(int j = i + 1; j < n; j++) {
                    if(s[i] == s[j]) {
                        if(i + 1 == j) {
                            dp[i][j] = 1;
                        } else {
                            if(dp[i + 1][j - 1] == 1) {
                                dp[i][j] = 1;
                            }
                        }
                    }

                    if(dp[i][j] == 1) {
                        if(j - i + 1 > length) {
                            length = j - i + 1;
                            start = i;
                        }
                    }
                }
            }

            string res = s.substr(start, length);
            return res;
        }
    };