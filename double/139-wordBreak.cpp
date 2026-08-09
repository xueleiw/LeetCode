/**
 * 2025-3-12
 * 1-：dp-还有待理解
 */ // $$

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;


/*================1-: 20ms=====================*/
class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> dict(wordDict.begin(), wordDict.end());
            vector<bool> dp(s.length() + 1, false);
            dp[0] = true;
            for(int i = 1; i <= s.length(); i++) {
                for(int j = 0; j < i; j++) {
                    string x = s.substr(j, i - j);
                    if(dict.find(x) != dict.end() && dp[j]) {
                        dp[i] = true;
                    }
                }
            }

            return dp[s.length()];
        }
    };

int main() {

    return 0;
}