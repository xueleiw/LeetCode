#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    int n = s.length();
    int i = 0;
    bool flag = true;

    while(i < n) {
        if(st.empty()) {
            st.push(s[i]);
            i++;
        } else {
            if(s[i] == '[' || s[i] == '(' || s[i] == '{') {
                st.push(s[i]);
                i++;
            } else {
                char c = st.top();
                if(s[i] == ')') {
                    if(c != '(') {
                        flag = false;
                        break;
                    }
                } else if(s[i] == ']') {
                    if(c != '[') {
                        flag = false;
                        break;
                    }
                } else if(s[i] == '}') {
                    if(c != '{') {
                        flag = false;
                        break;
                    }
                }
                st.pop();
                i++;
            }
        }
    }
    if(!st.empty() || !flag) {
        cout << "无效" << endl;
    } else {
        cout << "有效" << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")