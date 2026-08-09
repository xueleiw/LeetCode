/**
 * 2024-12-31
 * 1-: 左括号入栈，右括号弹栈进行比对即可
 * 
 */

#include<iostream>
#include<stack>
using namespace std;


/*==============1-: 0ms=============*/
class Solution {
public:
    bool isValid(string s) {
        stack<int> tmp;
        if(s.length() == 0) return true;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '[' || s[i] == '{' || s[i] == '(') {
                tmp.push(s[i]);
            } else {
                if(tmp.empty()) return false; // 弹栈之前得确保栈不为空
                char x = tmp.top();
                tmp.pop();
                if(s[i] == ')') {
                    if(x != '(') {
                        return false;
                    }
                } else if(s[i] == ']') {
                    if(x != '[') {
                        return false;
                    }
                } else if(s[i] == '}') {
                    if(x != '{') {
                        return false;
                    }
                }

            }
        }
        if(!tmp.empty()) return false;
        return true;
    }
};

int mian() {

    return 0;
}