#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 0902
// 维护双指针的长度，重点是左指针每次修改的位置是右指针指向字符的前一个位置
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len <= 1) {
            return len;
        }

        // unordered_map<char, int> mp;
        unordered_set<char> st;
        int left = 0;
        int res = 0;

        for(int i = 0; i < len; i++) {
            if(!st.count(s[i])) {
                st.insert(s[i]);
            } else {
                for(left; left < i; left++) {
                    if(s[left] == s[i]) {  // 注意这里，相同的字符就不用删除了，还得留一个
                        left++;
                        break;
                    } else {
                        st.erase(s[left]);
                    }
                }
            }

            res = max(res, i - left + 1);
        }

        return res;
    }
};