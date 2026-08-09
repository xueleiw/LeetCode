#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// 4-30
//

class Solution {
    public:
        int lengthOfLongestSubstringTwoDistinct(string s) {
            if(s.length() <= 2) {
                return s.length();
            }

            unordered_map<char, int> st;
            int res = 2;
            int count = 0;
            int start = 0;

            int tmp_length = 0;
            for(int i = 0; i < s.length(); i++) {
                if(st.count(s[i])) {
                    tmp_length++;
                    st[s[i]]++;
                    // end = i;    
                } else {
                    if(count < 2) {
                        count++;
                        tmp_length++;
                        st[s[i]] = 1;
                        // end = i;
                    } else if(count == 2) {
                        res = max(tmp_length, res);
                        // cout << start << " " << tmp_length << endl;
                        for(int j = start; j < i; j++) {
                            st[s[j]]--;
                            if(st[s[j]] == 0) {
                                st.erase(s[j]);
                                count--;
                                tmp_length -= (j - start + 1);
                                // cout << "111  " << tmp_length << endl;
                                start = j + 1;
                                break;
                            }
                        }
                        tmp_length++;
                        count++;
                        // cout << tmp_length << " 222" << endl;
                        st[s[i]] = 1;  
                    }
                }

                // cout << start << endl;

                // if(count == 2) {
                    res = max(tmp_length, res);
                // }
            }

            return res;
        }
    };

