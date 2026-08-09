#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 0) return 0;

        int count = 1;
        int res = 0;
        int j = 0;
        int i = 0;
        for(i; i < chars.size() - 1; i++) {
            if(chars[i] == chars[i + 1]) {
                count++;
            } else {
                // res += count + 1;
                if(count == 1) {
                    chars[j] = chars[i];
                    j++;
                    //
                } else {
                    chars[j] = chars[i];
                    j++;
                    stack<int> st;
                    while(count > 0) {
                        st.push(count % 10);
                        count /= 10;
                    }
                    while(!st.empty()) {
                        int x = st.top();
                        st.pop();
                        chars[j] = x + '0';
                        j++;
                    }
                }
                count = 1;
            }
        }
        // res += count + 1;
        chars[j] = chars[i];
        if(count == 1) {
            j++;
        } else {
            j++;
            stack<int> st;
            while(count > 0) {
                st.push(count % 10);
                count /= 10;
            }
            while(!st.empty()) {
                int x = st.top();
                st.pop();
                chars[j] = x + '0';
                j++;
            }
        }

        return j;
    }
};