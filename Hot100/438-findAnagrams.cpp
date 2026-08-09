// 2025-4-5

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;



// 578ms 手动实现哈希，存储每个字符出现的个数vector<int> sv(26, 0);，使用滑动窗口向右移动进行判断
class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            
            vector<int> sv(26, 0);
            vector<int> pv(26, 0);
            for(int i = 0; i < p.length(); i++) {
                pv[p[i] - 'a']++;
            }
            vector<int> res;
            if(p.length() > s.length()) {
                return res;
            }

            for(int i = 0; i < s.length() - p.length() + 1; i++) {
                for(int j = i; j < i + p.length(); j++) {
                    sv[s[j]- 'a']++;
                }
                if(sv == pv) {
                    res.push_back(i);
                }
                sv.assign(sv.size(), 0);
                // sv.resize(26, 0);
            }

            return res;
        }
    };

// // 暴力解法超时
// class Solution {
//     public:
//         vector<int> findAnagrams(string s, string p) {
//             vector<int> res;
//             int m = s.length(), n = p.length();
//             string _p = p;
//             sort(_p.begin(), _p.end());

//             for(int i = 0; i < m - n; i++) {
//                 string tmp = s.substr(i, n);
//                 sort(tmp.begin(), tmp.end());
//                 if(tmp == _p) {
//                     res.push_back(i);
//                 }
//             }

//             return res;
//         }
//     };