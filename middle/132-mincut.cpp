#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
// 5-12

class Solution {
private:
    vector<vector<string>> res;
    vector<string> tmp;
public:
    bool judge(string& s) {
        
        int n = s.length();
        int i = 0, j = n - 1;
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        // cout << s << endl;
        return true;
    }

    void back(string &s, int index) {
        if(index >= s.length()) {
            // for(auto &x: tmp) {
            //     cout << x << " ";
            // }cout << endl;
            
            res.push_back(tmp);
            return;
        }

        for(int i = index; i < s.length(); i++) {
            string x = s.substr(index, i - index + 1);
           
            if(judge(x)) {
                // cout << x << ' ';
                tmp.push_back(x);
            } else {
                continue;
            }
            back(s, i + 1);
            tmp.pop_back();
        }
    }

    int minCut(string s) {
        back(s, 0);
        // return res;
        int ans = INT_MAX;
        for(int i = 0; i < res.size(); i++) {
            int x = res[i].size() - 1;
            ans = min(ans, x);
            // ans =  min(ans, res[i].size());
        }
        return ans;
    }
};