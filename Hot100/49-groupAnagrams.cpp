#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 2025-4-2
// 11ms 哈希表存储
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> res;
            unordered_map<string, int> my_map;
            vector<string> tmp = strs;
            vector<int> a(strs.size(), 0);

            res.clear();
            if(strs.empty()) {
                return res;
            }

            
            
            for(int i = 0; i < tmp.size(); i++) {
                sort(tmp[i].begin(), tmp[i].end());
            }
            
            int max_group = 0;
            int j = 0;
            for(int i = 0; i < tmp.size(); i++) {
                if(!my_map.count(tmp[i])) {
                    my_map[tmp[i]] = j;
                    a[i] = j;
                    j++;
                } else {
                    a[i] = my_map[tmp[i]];
                }

                max_group = max(max_group, a[i]);
            }

            res.resize(max_group + 1);
            for(int i = 0; i < strs.size(); i++) {
                res[a[i]].push_back(strs[i]);
            }

            return res;
        }
    };