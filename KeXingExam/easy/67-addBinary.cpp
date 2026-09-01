#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 
class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.length();
        int lenb = b.length();
        string res = "";

        if(lena == 0) {
            return b;
        }
        if(lenb == 0) {
            return a;
        }
        
        int plus = 0;
        int tmp = 0;
        // int i = min(lena - 1, lenb - 1);
        lena--;
        lenb--;
        for(lena, lenb; lena >=0 && lenb >=0; lena--, lenb--) {
            tmp = (a[lena] - '0') + (b[lenb] - '0') + plus;
            if(tmp > 2) {
                plus = 1;
                res.push_back('1');
            } else if(tmp > 1) {
                plus = 1;
                res.push_back('0');
            } else {
                plus = 0;
                res.push_back(char(tmp + '0'));
            }
        }

        if(lenb >= 0) {
            for(lenb; lenb >= 0; lenb--) {
                tmp = (b[lenb] - '0') + plus;
                if(tmp > 2) {
                    plus = 1;
                    res.push_back('1');
                } else if(tmp > 1) {
                    plus = 1;
                    res.push_back('0');
                }  else {
                    plus = 0;
                    res.push_back(char(tmp + '0'));
                }
            }
        } else {
            for(lena; lena >= 0; lena--) {
                tmp = (a[lena] - '0') + plus;
                if(tmp > 2) {
                    plus = 1;
                    res.push_back('1');
                } else if(tmp > 1) {
                    plus = 1;
                    res.push_back('0');
                } else {
                    plus = 0;
                    res.push_back(char(tmp + '0'));
                }
            }
        }

        if(plus > 0) {
            res.push_back('1');
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string a = "100";
    string b = "110010";
    Solution solu;
    string res = solu.addBinary(a, b);
    cout << res << endl;
    Solution d;
    cout << d.addBinary("11", "1") << endl;

    return 0;
}