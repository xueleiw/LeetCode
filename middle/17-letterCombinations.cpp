/**
 * 2025-2-21
 * 1-：回溯-与子集问题类似
 */

#include<iostream>
#include<vector>
using namespace std;


/*================1-: 0ms=====================*/
class Solution {
    private:
        const string number_map[10] = {
            "",
            "",
            "abc",  // 2
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz", // 9
        };
    public:
        vector<string> result;
        string tmp;

        void backtrack(string digits, int index) {
            if(index == digits.size()) {
                result.push_back(tmp);
                return;
            }

            int tmp_i = digits[index] - '0'; // 先判断是数字几？
            string abc = number_map[tmp_i];  // 取出当前数字对应的字母组合
            for(int i = 0; i < abc.size(); i++) {
                tmp.push_back(abc[i]);
                backtrack(digits, index + 1); // 一定注意这里是index + 1，取下一个数字
                tmp.pop_back();
            }
        }

        vector<string> letterCombinations(string digits) {
            result.clear();
            tmp = "";

            if(digits.empty()) return result;
            backtrack(digits, 0);
            return result;
        }
    };

int main() {

    return 0;
}