#include <iostream>
#include <stack>
using namespace std;
// 5-9

// 倒序遍历，遇到 ？ 就弹出栈顶两个元素进行比较 
// "T?T?F:5:3"
class Solution {
    public:
        string parseTernary(string expression) {
            string e = expression;
            stack<char> st;
            int n = expression.length();
            for(int i = n - 1; i >= 0; i--) {
                if(e[i] == '?') {
                    char a = st.top();
                    st.pop();
                    char b = st.top();
                    st.pop();
                    i--;
                    if(e[i] == 'T') {
                        st.push(a);
                    } else {
                        st.push(b);
                    }
                } else {
                    if(e[i] == ':')continue;
                    st.push(e[i]);
                }
            }
            // return st.top();
            string res;
            res.push_back(st.top());
            return res;
        }
    };