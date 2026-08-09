#include <iostream>
#include <stack>
#include <string>

using namespace std;

int countMatchedPairs(const string &s) {
    stack<char> st;
    int count = 0;

    for (char c : s) {
        if (c == '(' || c == '[') {
            st.push(c);  // 左括号入栈
        } 
        else if (c == ')' || c == ']') {
            if (st.empty()) {
                continue;  // 栈为空，无法匹配
            }
            char top = st.top();
            if ((c == ')' && top == '(') || (c == ']' && top == '[')) {
                st.pop();  // 匹配成功，弹出栈顶
                count++;   // 匹配对数 +1
            }
        }
    }
    return count;
}

int main() {
    string s = "())";
    int matchedPairs = countMatchedPairs(s);
    cout << "匹配的成对括号数量: " << matchedPairs << endl;
    return 0;
}