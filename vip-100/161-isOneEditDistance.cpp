#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
// 5-13


//  s 中插入 恰好一个 字符得到 t
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.length(); 
        int m = t.length();
        if(s == t) return false;
        // if(n > m) return false;
        if(abs(m - n) > 1) return false;
        unordered_map<char, int> a, b;
        

        for(int i = 0; i < s.length(); i++) {
            a[s[i]]++;
        }
        for(int i = 0; i < t.length(); i++) {
            b[t[i]]++;
        }

        for(auto &x: b) {
            char c = x.first;
            int num = x.second;
            if(a.count(c)) {
                if(num >= a[c]) {
                    x.second -= a[c];
                    a[c] = 0;
                    // count += num - a[c];
                } else {
                    x.second = 0;
                    a[c] -= x.second;
                }
                 
            } else {
                // count += num;
            }
        }

        int count = 0;int ct = 0;
        for(auto &x: b) {
            count += x.second;
        }   
        for(auto &x: a) {
            ct += x.second;
        }

        // if(count <= 1) return true;
        if(ct == 0 && count == 0) return false;
        if(ct == 1 && count == 0) return true;
        if(count <= 1) return true;
        return false;
    }
};