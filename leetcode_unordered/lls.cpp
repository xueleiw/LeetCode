#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;
// 5-3
// 19ms
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int res = 0;
            int start = 0;
            unordered_map<char, int> mp;
            
            for(int i = 0; i < s.length(); i++) {
                if(mp.count(s[i])) {
                    for(int j = start; j < i; j++) {
                        if(s[j] != s[i]) {
                            mp.erase(s[j]);
                            
                        } else {
                            start = j + 1; // 新的开始
                            break;
                        }
                        
                    }
                } else {
                    mp[s[i]] = 1;
                }
                res = max(res, i - start + 1);
            }

            return res;
        }
    };