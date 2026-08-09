/**
 * 2025-2-25
 * 1-：回溯--把握宽度和深度的概念
 * $$$
 */

 #include<iostream>
 #include<vector>
 #include<string>
 #include<string.h>
 #include <algorithm> // std::reverse
 using namespace std;


/*================1-: 93ms=====================*/
class Solution {
    private:
        vector<vector<string>> result;
        string tmp;
        vector<string> tmp_set;
    public:
        bool isPalindrome(string str) { // 判断一个串是否是回文串
            string s1 = str;
            reverse(str.begin(), str.end());
            return s1 == str;
        }

        void backtrack(string s, int index) {
            
            if(index >= s.length()) {
                result.push_back(tmp_set);
                return;
            }

            for(int i = index; i < s.length(); i++) { // 循环是为了横向的长度，递归是为了纵向的深度
                // 
                string str = s.substr(index, i - index + 1);
                if(isPalindrome(str)) { // 从当前位置切割，把之前的子串存起来
                    tmp_set.push_back(str);
                    
                } else {
                    continue;
                }

                backtrack(s, i + 1); // 下一个元素开始 i + 1
                tmp_set.pop_back();
            }

        }

        vector<vector<string>> partition(string s) {
            result.clear();
            tmp.clear();
            tmp_set.clear();

            backtrack(s, 0);

            return result;
        }
    };
 
int main() {
    Solution solu;
    vector<vector<string>> res = solu.partition("aab");
    cout << "solu is\n";
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ' ' ;
        }
        cout << endl;
    }
    return 0;
}