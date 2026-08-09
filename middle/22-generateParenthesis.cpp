/**
 * 2025-2-24
 * 1-：回溯-一定要弹出，这里也是回溯的关键;左括号满的时候也还要考虑添加右括号的情况
 */

#include<iostream>
#include<vector>
using namespace std;


/*================1-: 0ms=====================*/
class Solution {
    private:
        vector<string> result;
        string tmp;

    public:
        void backtrack(int n, int left_num, int right_num) {
            if(left_num == n && right_num == n) {
                // cout << "tmp is " << tmp << endl;
                result.push_back(tmp);
                // tmp = "";
                return;
            }

            
            if(left_num - right_num >= 1) { // 这种情况下左右括号都要考虑一下
                // 左括号
                if(left_num + 1 <= n) {
                    tmp.push_back('(');
                    backtrack(n, left_num + 1, right_num);
                    tmp.pop_back(); // 一定要弹出，这里也是回溯的关键
                    //if()
                    
                    tmp.push_back(')');
                    backtrack(n, left_num, right_num + 1);
                    tmp.pop_back(); // 一定要弹出，这里也是回溯的关键
                } else {// 保证单边括号数量不大于n,但是这里不能返回，还要留给右括号选择的机会
                    // 说明这里左括号已满，只能放右括号
                    if(right_num + 1 <= n) {
                        tmp.push_back(')');
                        backtrack(n, left_num, right_num + 1);
                        tmp.pop_back(); // 一定要弹出，这里也是回溯的关键
                    }
                }  
            } else {
                if(left_num + 1 <= n) {
                    tmp.push_back('(');
                    backtrack(n, left_num + 1, right_num);
                    tmp.pop_back(); // 一定要弹出，这里也是回溯的关键
                } // 保证单边括号数量不大于n
                
            }
            //tmp.clear();
        }

        vector<string> generateParenthesis(int n) {
            result.clear();
            tmp.clear(); // 刚开始一定是一个左括号
            // if(n == 0) return result;

            backtrack(n, 0, 0);
            return result;
        }
    };

int main() {

    Solution solu;
    vector<string> res = solu.generateParenthesis(3);
    cout << "solu is\n";
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}