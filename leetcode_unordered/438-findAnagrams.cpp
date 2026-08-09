#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <array>
using namespace std;
// 5-3
// 7ms
class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
        //    int a[26] = {0}, b[26] = {0};
            vector<int> a(26, 0);
            vector<int> b(26, 0);
            vector<int> res;
            if(s.length() < p.length()) return res;

            for(int i = 0; i < p.length(); i++) {
                b[p[i] - 'a']++;
            }

            for(int i = 0; i < p.length() - 1; i++) {
                a[s[i] - 'a']++;
            }
            // for(int i = 0; i < 26; i++) {
            //     cout << a[i] << " " << b[i] << endl;
            // }
            for(int i = p.length() - 1; i < s.length(); i++) {
                a[s[i] - 'a']++;
                if(a == b) {
                    
                    res.push_back(i - p.length() + 1);
                }
                a[s[i - p.length() + 1] - 'a']--;
            }

            return res;
        }
    };

int main() {
    array<int, 5> a;
    a[0] = 123;
    for(auto &x: a) {
        cout << x << " ";
    }

    return 0;
}