#include <iostream>
#include <vector>
using namespace std;
// 0907

class Solution {
    private:
        vector<string> res;
        vector<vector<bool>> vis;

        // 前缀树结构体
        struct TreeNode {
            TreeNode* child[26];
            string result;

            TreeNode() {
                result = "";
                for(int i = 0; i < 26; i++) {
                    child[i] = nullptr;
                }
            }
        };

        TreeNode* root;

        void insert(string& s, TreeNode* node) {
            // TreeNode* node = root; // 插入的时候根节点是不能动的
            int len = s.length();
            for(int i = 0; i < len; i++) {
                char c = s[i];
                int index = c - 'a';
                if(node->child[index] == nullptr) {
                    node->child[index] = new TreeNode();
                }
                node = node->child[index];
            }
            node->result = s;
        }


    public:
        void findSearch(vector<vector<char>>& board, const int m, const int n, int i, int j, TreeNode* node) {

            if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j] == true) {
                return;
            }

            char c = board[i][j];
            int index = c - 'a';
            if(node->child[index] == nullptr) {
                return; // 加上当前字符，如果不满足前缀直接返回
            }
            // 这里向下一层之后才能判断是不是完整单词
            node = node->child[index];
            vis[i][j] = true;

            if(node->result != "") {
                res.push_back(node->result);
                node->result = ""; // 这里置空是为了只找一次，减少更多次的查找
            }



            findSearch(board, m, n, i + 1, j, node);
            findSearch(board, m, n, i - 1, j, node);
            findSearch(board, m, n, i, j + 1, node);
            findSearch(board, m, n, i, j - 1, node);

            vis[i][j] = false;
            return;
        }

        bool exist(vector<vector<char>>& board, string word) {

            int m = board.size(); // row
            int n = board[0].size(); // column
            vis.resize(m, vector<bool>(n, false));
            root = new TreeNode();

            insert(word, root);

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    TreeNode* node = root;
                    findSearch(board, m, n, i, j, node);
                }
            }

            return (res.size() != 0);
        }
};