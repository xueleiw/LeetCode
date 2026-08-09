#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
// 4-20 


class Solution {
    public:
        string removeDuplicates(string s) {
            // abbaca
            if(s.length() < 2) return s;
            stack<char> st;
        
            for(int i = 0; i < s.length(); i++) {
                if(st.empty()) {
                    st.push(s[i]);
                } else {
                    char c = st.top();
                    // cout << c << endl;
                    if(c == s[i]) {
                        st.pop();
                    } else {
                        st.push(s[i]);
                    }
                }
            }

            string res = "";
            while(!st.empty()) {
                res.push_back(st.top());
                st.pop();
            }

            reverse(res.begin(), res.end());
            return res;
        }
    };



int main() {
    Solution solu;
    cout << solu.removeDuplicates("abbaca") << endl;

    return 0;
}