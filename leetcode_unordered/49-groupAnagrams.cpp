#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// 5-3

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mp;
            vector<vector<string>> res;
            for(int i = 0; i < strs.size(); i++) {
                string tmp = strs[i];
                sort(tmp.begin(), tmp.end());
                mp[tmp].push_back(strs[i]);
                // if(mp.count(tmp)) {
                //     mp[tmp].push_back(strs[i]);
                // } else {    
                //     mp[tmp].push_back(strs[i]);
                // }
            }

            for(auto &x: mp) {
                res.push_back(x.second);
            }

            return res;
        }
    };
