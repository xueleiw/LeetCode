#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// 5-1
// 思路是只能有一个字符是奇数个，其余必须是偶数个  0ms
class Solution {
    public:
        bool canPermutePalindrome(string s) {
            unordered_map<char, int> mp;
            unordered_set<char> st;

            for(int i = 0; i < s.length(); i++) {
                st.insert(s[i]);
                mp[s[i]]++;
            }

            // if(st.size() == 1) return true;
            int count = 0;
            for(const char &c: st) {
                if(mp[c] %2 == 1) {
                    if(count == 0) {
                        count++;
                    } else {
                        return false;
                    }
                }
            }
            return true;
        }
    };


