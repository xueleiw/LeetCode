/**
 * 2025-3-23
 * 1-：就是回溯+剪枝判断所有符合长度和3个点要求的情况；回溯那里需要判断放点和不放点递归；然后就是判断字符串是否满足ip格式要求即可
 */ // 

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<cmath>
using namespace std;


/*===============1-: 167ms=====================*/
class Solution {
    private:
        vector<string> res; // 最后返回的结果
        string tmp; // 记录当前插入 3个 . 的字符串
        int count; // 记录插入的点的个数
    public:
        void backtrace(string s, int index) {
            if(count > 3) return;
            if(index >= s.length()) {
                
                if(tmp.length() != s.length() + 3) return;
                
                // 判断tmp是否符合要求
                int n = tmp.length();
                if(tmp[n - 1] == '.') return; // 最后一个是.直接返回 第一个不可能是 .
                int sum = 0;
                int po = 0; // 幂次
                for(int i = n - 1; i >= 0; i--) {
                    if(isdigit(tmp[i])) {
                        sum += (tmp[i] - '0') * pow(10, po);
                        po++;
                    } else if(tmp[i] == '.') {
                        
                        // cout << "sum is " << sum << endl;
                        if(sum > 255) return;
                        if(tmp[i + 1] == '0' && po >= 2) return;
                        po = 0;
                        sum = 0;
                    }
                }
                if(sum > 255) return;
                if(tmp[0] == '0' && po >= 2) return;
                // cout << tmp << endl;
                res.push_back(tmp);

            }

            for(int i = index; i < s.length(); i++) {
                tmp.push_back(s[i]);
                {
                    tmp.push_back('.'); // 放点
                    count++;
                    backtrace(s, i + 1);
                }
                tmp.pop_back(); // 不放点
                count--;
                backtrace(s, i + 1);
                
               
                tmp.pop_back(); // 这里要弹两次
                
                
            }
        }

        vector<string> restoreIpAddresses(string s) {
            res.clear();
            count = 0;
            tmp = "";
            if(s.length() < 4 || s.length() > 12) return res;

            backtrace(s, 0);

            return res;
        }
    };

int main() {
    Solution solu;
    vector<string> res = solu.restoreIpAddresses("101023");
    for(auto &x: res) {
        cout << "res is " << ' ' <<  x << endl;
    }

    return 0;
}