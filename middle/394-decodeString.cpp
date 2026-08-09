/**
 * 2025-3-5
 * 1-：递归+栈实现；需要注意的是从一个栈到另一个复制是需要仔细考虑的，不是简单的弹栈入栈而已；其次需要考虑很多倍数的情况
 */

#include<iostream>
#include<vector>
#include<cctype>
#include<stack>
#include<algorithm>
using namespace std;

/*================1-: 0ms=====================*/
class Solution {
    public:
        stack<char> backtrace(string s, int& index, int times) { // 连同倍数一起传进去
            stack<char> result;
            int total_times = 0;
            int total_ = 1;
            for(index; index < s.length(); index++) {
                if(!isdigit(s[index])) {
                    if(s[index] == ']') {
                        //index++;
                        break;
                    }
                    if(s[index] != '[') {
                        result.push(s[index]);
                    }
                } else { // 遇到数字
                    int tmp_times = s[index] - '0';
                    if(isdigit(s[index + 1])) {
                        total_times += tmp_times;  // 加下一位再乘10
                        total_times *= 10;
                        continue; 
                    }
                    total_times += tmp_times;
                    index++; // 跳过数字
                    stack<char> tmp_res = backtrace(s, index, total_times); // 这里一个栈往另一个栈放的时候要特别注意
                    total_times = 0;
                    vector<char> tmp_;
                    while(!tmp_res.empty()) {
                        tmp_.push_back(tmp_res.top());
                        tmp_res.pop();
                    }
                    for(int i = tmp_.size() - 1; i >= 0; i--) {
                        result.push(tmp_[i]);
                    }
                }
            }

            vector<char> tmp_res;
            while(!result.empty()) {
                tmp_res.push_back(result.top());
                result.pop();
            }
            // 此时result为空
            for(int i = 0; i < times; i++) {
                for(int j = tmp_res.size() - 1; j >= 0; j--) {
                    result.push(tmp_res[j]);
                }
            }

            return result;
        }

        string decodeString(string s) {
            if(s.length() == 1) return s;

            int x = 0;
            stack<char> tmp_res =  backtrace(s, x, 1);
            string res = "";
            while(!tmp_res.empty()) {
                res.push_back(tmp_res.top());
                tmp_res.pop();
            }
            cout << "x is " << x << endl;
            reverse(res.begin(), res.end());
            return res;
        }
};

int main() {
    // string s = "3[a]2[bc]";
    // string s = "3[a2[c]]";
    string s = "12[ab]";
    // cout << s;
    Solution solu;
    string res = solu.decodeString(s);
    cout << res;
    return 0;
}