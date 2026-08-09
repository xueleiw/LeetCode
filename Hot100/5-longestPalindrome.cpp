// 4-8
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// dp[i][j]代表在这个区间内是一个回文串，用1表示真 --- 而且要注意遍历顺序是从左下开始往上

class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.length();
            vector<vector<int>> dp(n, vector<int>(n, 0));

            for(int i = 0; i < n; i++) {
                dp[i][i] = 1; // 自己本身就是一个回文串，长度为1
            }

            int start = 0;
            int length = 1; // 如果找不到回文就输出第一个字符
            for(int i = n - 2; i >= 0; i--) {
                for(int j = i + 1; j < n; j++) {
                    if(s[i] == s[j]) {
                        if(i + 1 == j) { // 说明区间长度是2
                            dp[i][j] = 1;
                        } else {
                            if(dp[i + 1][j - 1]) dp[i][j] = 1; // 长度大于2
                        }
                    }

                    if(dp[i][j]) { // 取最大的长度
                        if(j - i + 1 > length) {
                            start = i;
                            length = j - i + 1;
                        }
                    }
                }
            }

            string res = s.substr(start, length);
            return res;
        }
    };



int main() {

    return 0;
}