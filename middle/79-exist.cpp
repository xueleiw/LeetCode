/**
 * 2025-2-24
 * 1-：回溯--从矩阵的每个字母为头开始回溯，按照元素的四个方向进行递归即可；
 * 2-：剪枝--
 */

 #include<iostream>
 #include<vector>
 #include<string>
 #include<string.h>
 using namespace std;


 /*================1-: 2819ms=====================*/
 class Solution {
    private:
        string tmp;
        bool res;
        bool vis[10][10];
    public:
        void backtrack(vector<vector<char>>& board, int m, int n, string word, int i, int j) {
            if(tmp == word) {
                res = true;
                return;
            }
            if(tmp.length() > word.length()) return;

            // 四个方向都要考虑
            if(i - 1 >= 0 && vis[i - 1][j] == false) {
                tmp.push_back(board[i - 1][j]);
                vis[i - 1][j] = true;
                backtrack(board, m, n, word, i - 1, j);
                tmp.pop_back();
                vis[i - 1][j] = false;
            }
            if(i + 1 < m && vis[i + 1][j] == false) {
                tmp.push_back(board[i + 1][j]);
                vis[i + 1][j] = true;
                backtrack(board, m, n, word, i + 1, j);
                tmp.pop_back();
                vis[i + 1][j] = false;
            }
            if(j - 1 >= 0 && vis[i][j - 1] == false) {
                tmp.push_back(board[i][j - 1]);
                vis[i][j - 1] = true;
                backtrack(board, m, n, word, i, j - 1);
                tmp.pop_back();
                vis[i][j - 1] = false;
            }
            if(j + 1 < n && vis[i][j + 1] == false) {
                tmp.push_back(board[i][j + 1]);
                vis[i][j + 1] = true;
                backtrack(board, m, n, word, i, j + 1);
                tmp.pop_back();
                vis[i][j + 1] = false;
            }

        }

        bool exist(vector<vector<char>>& board, string word) {
            tmp.clear();
            res = false;
            int m = board.size();
            int n = board[0].size();

            for(int i = 0; i < m; i++) { // 从每一个字母作为开头进行回溯
                for(int j = 0; j < n; j++) {
                    if(res) {
                        return res; // 减少循环的次数
                    }
                    tmp.clear();
                    memset(vis, 0, sizeof(vis));
                    vis[i][j] = true;
                    tmp.push_back(board[i][j]);
                    backtrack(board, m, n, word, i, j);
                }
            }
            
            return res;
        }
    };

int main() {
    
    return 0;
}