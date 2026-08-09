/**
 * 2024-12-30
 * 1-: 将每个子串排序之后比较，超时O(n * n * logn)
 * 2-: 统计每个子串的字母个数，通过比较个数是否相等判断是否包含异位串
 * 3-: 第2种方法的改良版-->> 滑动窗口,每次向后移动一位统计数量，比较元素数量是否相等
 */

#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
using namespace std;


/*============1: 暴力求解，会超时====================*/
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int len = p.length();
//         vector<int> result;
//         int res = 0;
//         if(s.length() < p.length()) {
//             return result;
//         }

//         //
//         sort(p.begin(), p.end());

//         for(int i = 0; i <= s.length() - len; i++) {
//             string tmp = s.substr(i, len);
//             sort(tmp.begin(), tmp.end());
//             if(tmp == p) {
//                 result.push_back(i);
//             }
//         }

//         return result;
//     }
// };


/*=============2- 741ms===============*/
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int len = p.length();
//         vector<int> result;
//         vector<int> sv(26);
//         vector<int> pv(26);
//         if(s.length() < p.length()) {
//             return result;
//         }

//         for(int i = 0; i < len; i++) {
//             pv[p[i] - 'a']++;
//         }

//         for(int i = 0; i <= s.length() - len; i++) {
//             for(int j = i; j < i + len; j++) {
//                 sv[s[j] - 'a']++;
//             }
//             if(sv == pv) {
//                 result.push_back(i);
//             }
//             sv.assign(sv.size(), 0);  // vector比较常用的赋值方法
//         }

//         return result;
//     }
// };

/*=============2- 3ms===============*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len = p.length();
        vector<int> result;
        vector<int> sv(26);
        vector<int> pv(26);
        if(s.length() < p.length()) {
            return result;
        }

        for(int i = 0; i < len; i++) {
            pv[p[i] - 'a']++;
            sv[s[i] - 'a']++;
        }
        if(sv == pv) {
            result.push_back(0);
        }

        for(int i = 0; i < s.length() - len; i++) {
            sv[s[i] - 'a']--; // 去除头
            sv[s[i + len] - 'a']++; // 添加尾
            if(sv == pv) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};


int main() {

    int x = 'a' + 'f';
    int y = 'b' + 'e';
    cout << x << ' ' << y << endl;
    return 0;
}