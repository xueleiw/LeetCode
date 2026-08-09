// 4-8
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// 20ms
class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> se(wordDict.begin(), wordDict.end());
            vector<bool> dp(s.length() + 1, false);
            dp[0] = true;
            // 本题是求排列，不是组合，所以外层循环背包，内层循环物体
            for(int i = 1; i <= s.length(); i++) {
                for(int j = 0; j < i; j++) {
                    string tmp = s.substr(j, i - j);
                    if(dp[j] && se.count(tmp)) {
                        dp[i] = true;
                    }
                }
            }

            return dp[s.length()];
        }
    };