#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 4-30
// 0 ms
class Solution {
    public:
        string stringShift(string s, vector<vector<int>>& shift) {
            if(shift.empty() || s.length() == 0) {
                return s;
            }
            deque<char> dq;
            int n = s.length();
            for(int i = 0; i < n; i++) {
                dq.push_back(s[i]);
            }

            for(int i = 0; i < shift.size(); i++) {
                int direct = shift[i][0];
                int amount = shift[i][1];
                if(direct == 0) {
                    for(int j = 0; j < amount; j++) {
                        char tmp = dq.front();
                        dq.pop_front();
                        dq.push_back(tmp);
                    }
                } else {
                    for(int j = 0; j < amount; j++) {
                        char tmp = dq.back();
                        dq.pop_back();
                        dq.push_front(tmp);
                    }
                }
            }

            for(int i = 0; i < n; i++) {
                char tmp = dq.front();
                dq.pop_front();
                s[i] = tmp;
            }

            return s;
        }
    };




