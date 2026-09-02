#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 0903

// class Solution {
//     private:
//         unordered_map<string, bool> mp; // 记录所有的单词是否出现
//         vector<vector<bool>> vis;
//         vector<string> res;

//     public:
//         void findSearch(vector<vector<char>>& board, string& const int m, const int n, int i, int j, const int node) {
//             if(mp.count(tmp)) {  // 如果当前的字符串在单词表中出现过就删除，这里也能减少一些hash比较
//                 res.push_back(tmp);
//                 mp.erase(tmp);
//             }
//             if(tmp.length() > node) {
//                 return;
//             }

//             if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j] == true) {
//                 return;
//             }

//             vis[i][j] = true;
//             tmp += board[i][j];
//             findSearch(board, m, n, i + 1, j, node);
//             findSearch(board, m, n, i - 1, j, node);
//             findSearch(board, m, n, i, j + 1, node);
//             findSearch(board, m, n, i, j - 1, node);

//             vis[i][j] = false;
//             tmp.pop_back(); // 删除最后一个元素
//             return;
//         }

//         vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//             mp.clear();
//             string tmp = "";
//             int wordsLen = words.size();
//             int m = board.size(); // row
//             int n = m == 0 ? 0 : board[0].size(); // column
//             int node = 0;
//             vis.assign(m, vector<bool>(n, false));

//             for(int i = 0; i < wordsLen; i++) {
//                 mp[words[i]] = false;
//                 node = max(node, (int)words[i].length());
//             }

//             for(int i = 0; i < m; i++) {
//                 for(int j = 0; j < n; j++) {
//                     findSearch(board, m, n, i, j, node);
//                 }
//             }

//             // vector<string> res;
//             // for(int i = 0; i < wordsLen; i++) {
//             //     if(mp[words[i]]) {
//             //         res.push_back(words[i]);
//             //     }
//             // }

//             return res;
//         }
// };


// 就算用set构建所有前缀节点，大量的哈希操作还是很耗时
// class Solution {
//     private:
//         unordered_map<string, bool> mp; // 记录所有的单词是否出现
//         unordered_set<string> st;
//         vector<vector<bool>> vis;

//     public:
//         void findSearch(vector<vector<char>>& board, string& const int m, const int n, int i, int j, const int node) {
//             if(tmp.length() > node || ((tmp.length() >= 1) && !st.count(tmp))) {
//                 return;
//             }

//             if(mp.count(tmp)) {
//                 mp[tmp] = true;
//             }


//             if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j] == true) {
//                 return;
//             }

//             vis[i][j] = true;
//             tmp += board[i][j];
//             findSearch(board, m, n, i + 1, j, node);
//             findSearch(board, m, n, i - 1, j, node);
//             findSearch(board, m, n, i, j + 1, node);
//             findSearch(board, m, n, i, j - 1, node);

//             vis[i][j] = false;
//             tmp.pop_back(); // 删除最后一个元素
//             return;
//         }

//         vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//             mp.clear();
//             st.clear();
//             string tmp = "";
//             int wordsLen = words.size();
//             int m = board.size(); // row
//             int n = m == 0 ? 0 : board[0].size(); // column
//             int node = 0;
//             vis.assign(m, vector<bool>(n, false));

//             for(int i = 0; i < wordsLen; i++) {
//                 mp[words[i]] = false;
//                 node = max(node, (int)words[i].length());
//                 for(int j = 0; j < words[i].length(); j++) {
//                     st.insert(words[i].substr(0, j + 1));
//                 }
//             }

//             // for(auto& word: st) {
//             //     cout << word << " ";
//             // }

//             for(int i = 0; i < m; i++) {
//                 for(int j = 0; j < n; j++) {
//                     findSearch(board, m, n, i, j, node);
//                 }
//             }

//             vector<string> res;
//             for(int i = 0; i < wordsLen; i++) {
//                 if(mp[words[i]]) {
//                     res.push_back(words[i]);
//                 }
//             }

//             return res;
//         }
// };

// 终极解决方案：前缀树
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

        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

            int wordsLen = words.size();
            int m = board.size(); // row
            int n = board[0].size(); // column
            vis.resize(m, vector<bool>(n, false));
            root = new TreeNode();

            for(int i = 0; i < wordsLen; i++) {
                insert(words[i], root);
            }

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    TreeNode* node = root;
                    findSearch(board, m, n, i, j, node);
                }
            }

            return res;
        }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                  {'e', 't', 'a', 'e'},
                                  {'i', 'h', 'k', 'r'},
                                  {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> result = solution.findWords(board, words);
    for (const string& word : result) {
        cout << word << " ";
    }

    return 0;
}