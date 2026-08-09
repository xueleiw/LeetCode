// 2025-4-5

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// 230ms   无重复最长子串  哈希表记录索引，双指针向右滑动； 重点在于哈希表的添加删除以及左指针的移动
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<int, int> my_map;
            int res = 0;
            int left = 0, right = 0;

            int tmp = 0;
            for(int i = 0; i < s.length(); i++) {
                if(!my_map.count(s[i])) {
                    my_map[s[i]] = i; // 记录是否存在该字符
                } else {
                    res = max(res, i - left);
                    int x = my_map[s[i]];
                    for(int j = left; j < x; j++) {
                        my_map.erase(s[j]);
                    }
                    left = x + 1;
                    my_map[s[i]] = i; 
                }
            }
            int n = s.length();
            res = max(res, n - left);

            return res;
        }
    };