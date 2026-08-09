#include<iostream>
#include<vector>
using namespace std;
// 4-19


int main() {
    string s;
    int n;

    cin >> n >> s;
    long long res = 0;
    vector<vector<int>> dp(n, vector<int>(26, 0)); // dp[i][0] 就是记录当前 i~n-1 一共有多少个a字符，然后使用组合公式 C-n-2 计算

    dp[n - 1][s[n - 1] - 'a']++; // 初始化条件
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < 26; j++) {
            if(s[i] - 'a' == j) {
                dp[i][j] = dp[i + 1][j] + 1;
            } else {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < 26; j++) {
    //         cout << dp[i][j] << ' ';
    //     }cout << endl;
    // }
    //
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < 26; j++) {
            if(s[i] - 'a' != j) {
                if(dp[i + 1][j] >= 1) {
                    res += (dp[i + 1][j] * (dp[i + 1][j] - 1)) / 2; 
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}
