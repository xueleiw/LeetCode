#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;
// 5-7

// 15ms
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int res = 0;
            int start = 0;
            unordered_map<char, int> mp;

            for(int i = 0; i < s.length(); i++) {
                if(!mp.count(s[i])) {
                    mp[s[i]] = i;
                } else {
                    int end = mp[s[i]];
                    for(int j = start; j <= end; j++) {
                        mp.erase(s[j]);
                    }
                    mp[s[i]] = i;
                    start = end + 1;
                }
                res = max(res, i - start + 1);
            }
            return res;
        }
    };