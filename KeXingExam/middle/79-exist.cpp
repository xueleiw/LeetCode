#include <iostream>
#include <vector>
using namespace std;
// 0908  回溯：选择-寻找-回退

class Solution {
    private:
        string tmp;
        vector<vector<bool>> vis;
        bool res = false;

    public:
        void backTrace(vector<vector<char>>& board, string& word, int m, int n, int i, int j) {
            if (tmp.length() == word.length()) {
                // res = (tmp == word);  // 如果这里这样用的话会覆盖原来的值，跟下面的if完全不等价
                if (tmp == word) {
                    res = true;
                }
                return;
            }
            // 先判断再返回
            if (i < 0 || i >= m || j < 0 || j >= n) {
                return;
            }
            
            // if (board[i][j] != word[tmp.length()]) {  // 这里是剪枝操作
            //     return;
            // }

            if (!vis[i][j]) {
                tmp.push_back(board[i][j]);
                vis[i][j] = true;

                backTrace(board, word, m, n, i + 1, j);

                backTrace(board, word, m, n, i - 1, j);

                backTrace(board, word, m, n, i, j + 1);
           
                backTrace(board, word, m, n, i, j - 1);

                tmp.pop_back();
                vis[i][j] = false;
            }
            return;
        }

        bool exist(vector<vector<char>>& board, string word) {
            int m = board.size();
            int n = board[0].size();
            

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    tmp = "";
                    vis.resize(m, vector<bool>(n, false));
                    backTrace(board, word, m, n, i, j);
                    if (res) {
                        return true;
                    }
                }
            }

            return false;
        }
};