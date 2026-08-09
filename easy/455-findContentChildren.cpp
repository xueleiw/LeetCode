#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
// 5-12

// 11ms 
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size();
        int m = s.size();
        int i = 0, j = 0;
        int res = 0;

        while(i < n && j < m) {
            if(g[i] <= s[j]) {
                res++;
                i++;
                j++;
            } else {
                j++;
            }
        }


        return res;
    }
};