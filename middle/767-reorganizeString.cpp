#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
// 4-22
// 0ms  通过哈希表记录当前字母以及对应出现的次数，将次数从大到小排序，间隔放到res中，最后再判断是否符合要求。  

class Solution {
    public:
        string reorganizeString(string s) {
            if(s.length() == 1) return s;
            priority_queue<char> pq;
            // map<char, int> mp;
            vector<pair<int, int>> mp(26);
            string res(s.length(), ' ');

            for(int i = 0; i < s.length(); i++) {
                // pq.push(s[i]);
                // mp[s[i]]++;
                mp[s[i] - 'a'].first = s[i] - 'a'; // 记录个数
                mp[s[i] - 'a'].second++;
            } 

            sort(mp.begin(), mp.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.second > b.second;
            });

            int i = 0;
            for(int j = 0; j < mp.size(); j++) {
                for(int k = 0; k < mp[j].second; k++) {
                    res[i] = char(mp[j].first + 'a');
                    i = (i + 2) % s.length();
                    if(i == 0) i = 1;
                }
            }

            cout << res << endl;
            for(i = 0; i < s.length() - 1; i++) {
                if(res[i] == res[i + 1]) {
                    return "";
                }
            }

            return res;
        }
    };
