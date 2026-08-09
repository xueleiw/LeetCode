#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>
using namespace std;
// 5-4

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    

// class Solution {
//     private:
//         vector<vector<int>> res;
//         vector<int> tmp;
        
//     public:
//         void backtrace(vector<int>& nums, int count, int n, vector<bool>& vis) {
//             if(tmp.size() == n) {
//                 res.push_back(tmp);
//                 return;
//             }

//             for(int i = 0; i < n; i++) {
//                 if(!vis[i]) {
//                     tmp.push_back(nums[i]);
//                     vis[i] = true;
//                     backtrace(nums, count + 1, n, vis);
//                     vis[i] = false;
//                     tmp.pop_back();
//                     // backtrace(nums, count, n, vis);  // 这里相当于自己调用自己，会无限递归
//                 }
//             }
//         }

//         vector<vector<int>> permute(vector<int>& nums) {
//             int n = nums.size();
//             vector<bool> vis(n, false);
//             backtrace(nums, 0, n, vis);
//             return res;
//         }
//     };

// 0ms 
// class Solution {
//     private:
//         vector<vector<int>> res;
//         vector<int> tmp;
//     public:
//         void back(vector<int>& nums, int index, int n) {
//             res.push_back(tmp);
//             if(index == n) {
//                 return;
//             }

//             for(int i = index; i < n; i++) {
//                 tmp.push_back(nums[i]);
//                 back(nums, i + 1, n); // 下一个元素
//                 tmp.pop_back();
//             }
//         }

//         vector<vector<int>> subsets(vector<int>& nums) {
//             int n = nums.size();
//             back(nums, 0, n);
//             return res;
//         }
//     };

// 67ms
// class Solution {
//     public:
//         int firstMissingPositive(vector<int>& nums) {
//             unordered_set<int> st(nums.begin(), nums.end());
//             for(int i = 1; i <= INT_MAX; i++) {
//                 if(!st.count(i)) {
//                     return i;
//                 }
//             }

//             return 0;
//         }
//     };
// O(1)的空间复杂度
// class Solution {
//     public:
//         int firstMissingPositive(vector<int>& nums) {
//             int n = nums.size();
//             for(int i = 0; i < n; i++) {
//                 if(nums[i] <= 0) {
//                     nums[i] = n + 1;
//                 }
//             }
//             for(int i = 0; i < n; i++) {
//                 int x = abs(nums[i]);
//                 if(x <= n) {
//                     if(nums[x - 1] > 0) {
//                         nums[x - 1] = -nums[x - 1];
//                     }
//                 }
//             }
//             for(int i = 0; i < n; i++) {
//                 if(nums[i] > 0) {
//                     return i + 1;
//                 }
//             }
//             return n + 1;
//         }
//     };


// class Solution {
// private:
//     vector<int> res;
// public:
//     void inorder(TreeNode* root) {
//         if(root == nullptr) return;
//         if(root->left != nullptr) {
//             inorder(root->left);
//         }
//         res.push_back(root->val);
//         if(root->right != nullptr) {
//             inorder(root->right);
//         }
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         inorder(root);
//         return res;
//     }
// };
// 迭代法
// class Solution {
//     public:
//         vector<int> inorderTraversal(TreeNode* root) {
//             stack<TreeNode*> st;
//             vector<int> res;
//             if(root == nullptr) return res;
//             TreeNode* tmp = root;
//             while(!st.empty() || tmp != nullptr) {

//                 while(tmp!= nullptr) {
//                     st.push(tmp);
//                     tmp = tmp->left;
//                 }
//                 TreeNode* t = st.top();
//                 st.pop();
//                 res.push_back(t->val);
//                 if(t->right != nullptr) {
//                     tmp = t->right;
//                     // st.push(tmp);
//                 } else {
//                     tmp = nullptr;
//                 }
//             }
//             return res;
//         }
//     };


// class Solution {
//     private:
//         int res;
//     public:
//         void back(TreeNode* root, int depth) {
//             if(root == nullptr) {
//                 return;
//             }
//             res = max(res, depth);
//             back(root->left, depth + 1);
//             back(root->right, depth + 1);

//         }
//         int maxDepth(TreeNode* root) {
//             back(root, 1);
//             return res;
//         }
//     };


// class Solution {
//     public:
//         void back(TreeNode* root) {
//             if(root == nullptr) {
//                 return;
//             }
//             swap(root->left, root->right);
//             back(root->left);
//             back(root->right);
//         }
//         TreeNode* invertTree(TreeNode* root) {
//             back(root);
//             return root;
//         }
//     };


// class Solution {
//     private:
//         vector<pair<int, int>> s;
//     public:
//         void back(TreeNode* root, int dir) {
//             if(root == nullptr) {
//                 return;
//             }
            
//             back(root->left, -1);
//             s.push_back(pair<int, int>(root->val, dir));
//             back(root->right, 1);
//         }
//         bool isSymmetric(TreeNode* root) {
//             back(root, 0);
//             int n = s.size();
//             if(n == 1) return true;
//             int i = 0, j = n - 1;
//             while(i < j) {
//                 if(s[i].first != s[j].first) {
//                     return false;
//                 } else {
//                     if(s[i].second == s[j].second) {
//                         return false;
//                     }
//                 }
//                 i++;
//                 j--;
//             }
//             return true;
//         }
//     };


// class Solution {
//     private:
//         int res;
//     public:
//         int back(TreeNode* root) {
//             if(root == nullptr) {
//                 return -1;
//             }

//             int x = back(root->left) + 1;
//             int y = back(root->right) + 1;
//             res = max(res, x + y);

//             return max(x, y);
//         }
//         int diameterOfBinaryTree(TreeNode* root) {
//             back(root);
//             return res;
//         }
//     };


// class Solution {
//     private:
//         vector<vector<int>> res;
        
//     public:
//         void level(TreeNode* root) {
//             if(root == nullptr) return;
//             queue<pair<TreeNode*, int>> q;
//             vector<int> tmp;
//             q.push(pair<TreeNode*, int>(root, 1));
//             int cur_depth = 1;

//             while(!q.empty()) {
//                 pair<TreeNode*, int> t = q.front();
//                 q.pop();
//                 if(t.second == cur_depth) {
//                     tmp.push_back(t.first->val);
//                 } else {
//                     res.push_back(tmp);
//                     tmp.clear();
//                     tmp.push_back(t.first->val);
//                     cur_depth = t.second;
//                 }

//                 if(t.first->left != nullptr) {
//                     q.push(pair<TreeNode*, int>(t.first->left, t.second + 1));
//                 }
//                 if(t.first->right != nullptr) {
//                     q.push(pair<TreeNode*, int>(t.first->right, t.second + 1));
//                 }
//             }
//             res.push_back(tmp);
//         }

//         vector<vector<int>> levelOrder(TreeNode* root) {
//             level(root);
//             return res;    
//         }
//     };

// 5ms 递归 分治
// class Solution {
//     public:
//         TreeNode* back(vector<int>& nums, int l, int r) {
//             if(l > r) return nullptr;
//             // if(l == r)

//             int mid = (l + r) / 2;
//             TreeNode* root = new TreeNode(nums[mid]);
//             root->left = back(nums, l, mid - 1);
//             root->right = back(nums, mid + 1, r);

//             return root;
//         }

//         TreeNode* sortedArrayToBST(vector<int>& nums) {
//             int n = nums.size();
//             if(n == 0) {
//                 return nullptr;
//             }

//             TreeNode* res = back(nums, 0, n - 1);
//             return res;
//         }
//     };


// 3ms
// class Solution {
//     private: 
//         vector<int> res;    
//     public:
//         void back(TreeNode* root) {
//             if(root == nullptr) return;

//             back(root->left);
//             res.push_back(root->val);
//             back(root->right);
//         }
//         bool isValidBST(TreeNode* root) {
//             back(root);
//             for(int i = 0; i < res.size() - 1; i++) {
//                 if(res[i] >= res[i + 1]) {
//                     return false;
//                 }
//             }
//             return true;
//         }
//     };



// class Solution {
//     private:
//         vector<int> s;
//     public:
//         void back(TreeNode* root) {
//             if(root == nullptr) {
//                 return;
//             }
//             back(root->left);
//             s.push_back(root->val);
//             back(root->right);
//         }
//         int kthSmallest(TreeNode* root, int k) {
//             back(root);
//             return s[k - 1];
//         }
//     };


// class Solution {
//     private: 
//         vector<int> res;
//     public:
//         void level(TreeNode* root) {
//             if(root == nullptr) {
//                 return;
//             }
//             queue<pair<TreeNode*, int>> q;
//             q.push(pair<TreeNode*, int>(root, 1));
//             int cur_depth = 1;
//             vector<int> tmp;
            
//             while(!q.empty()) {
//                 pair<TreeNode*, int> t = q.front();
//                 q.pop();
//                 if(t.second == cur_depth) {
//                     tmp.push_back(t.first->val);
//                 } else {
//                     res.push_back(tmp[tmp.size() - 1]);
//                     tmp.clear();
//                     tmp.push_back(t.first->val);
//                     cur_depth = t.second;
//                 }
//                 if(t.first->left != nullptr) {
//                     q.push(pair<TreeNode*, int>(t.first->left, cur_depth + 1));
//                 }
//                 if(t.first->right != nullptr) {
//                     q.push(pair<TreeNode*, int>(t.first->right, cur_depth + 1));
//                 }

//             }
//             res.push_back(tmp[tmp.size() - 1]);
//         }

//         vector<int> rightSideView(TreeNode* root) {
//             level(root);
//             return res;
//         }
//     };


// 递归 原地算法
// class Solution {
//     public:
//         TreeNode* back(TreeNode* root) {
//             if(root == nullptr) {
//                 return nullptr;
//             }

//             TreeNode* l = root->left;
//             TreeNode* r = root->right;
//             root->left = nullptr;
//             if(l == nullptr) {
//                 root->right = back(r);
//             } else {
//                 root->right = back(l);
//                 TreeNode* p = l;
//                 while(p->right != nullptr) {
//                     p = p->right;
//                 }
//                 p->right = back(r);
//             }

//             return root;
//         }
//         void flatten(TreeNode* root) {
//             back(root);
//         }
//     };


// class Solution {
//     private:
//         int res;
//     public:
//         void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
//             if(i < 0 || i >= m || j < 0 || j >= n) {
//                 return;
//             }
//             if(grid[i][j] != '1') return;
//             grid[i][j] = '0';
//             dfs(grid, i - 1, j, m, n);
//             dfs(grid, i + 1, j, m, n);
//             dfs(grid, i, j - 1, m, n);
//             dfs(grid, i, j + 1, m, n);
//             return;
//         }

//         int numIslands(vector<vector<char>>& grid) {
//             int m = grid.size();
//             int n = grid[0].size();
//             for(int i = 0; i < m; i++) {
//                 for(int j = 0; j < n; j++) {
//                     // cout << i << " " << j << endl;
//                     if(grid[i][j] == '1') {
//                         dfs(grid, i, j, m, n);
//                         res++;
//                     }
//                 }
//             }
//             return res;
//         }
//     };


// 值 0 代表空单元格；
// 值 1 代表新鲜橘子；
// 值 2 代表腐烂的橘子。 // 2ms 
// struct node {
//     int x;
//     int y;
//     int depth;
// };
// class Solution {
//     public:
//         int orangesRotting(vector<vector<int>>& grid) {
//             queue<node> q;
//             int m = grid.size();
//             int n =  grid[0].size();
//             int res = 0;
//             vector<vector<bool>> vis(m, vector<bool>(n, false));
//             for(int i = 0; i < m; i++) {
//                 for(int j = 0; j < n; j++) {
//                     if(grid[i][j] == 2) {
//                         q.push(node{i, j, 0});
//                     }
//                 }
//             }

//             // cout << q.size() << endl;
//             while(!q.empty()) {
//                 node t = q.front();
//                 q.pop();
//                 if(vis[t.x][t.y]) continue;

//                 vis[t.x][t.y] = true;
//                 res = max(res, t.depth);
//                 if(t.x - 1 >= 0) {
//                     if(!vis[t.x - 1][t.y] && grid[t.x - 1][t.y] == 1) {
//                         grid[t.x - 1][t.y] = 2;
//                         q.push(node{t.x - 1, t.y, t.depth + 1});
//                     }
//                 }
//                 if(t.x + 1 < m) {
//                     if(!vis[t.x + 1][t.y] && grid[t.x + 1][t.y] == 1) {
//                         grid[t.x + 1][t.y] = 2;
//                         q.push(node{t.x + 1, t.y, t.depth + 1});
//                     }
//                 }
//                 if(t.y - 1 >= 0) {
//                     if(!vis[t.x][t.y - 1] && grid[t.x][t.y - 1] == 1) {
//                         grid[t.x][t.y - 1] = 2;
//                         q.push(node{t.x, t.y - 1, t.depth + 1});
//                     }
//                 }
//                 if(t.y + 1 < n) {
//                     if(!vis[t.x][t.y + 1] && grid[t.x][t.y + 1] == 1) {
//                         grid[t.x][t.y + 1] = 2;
//                         q.push(node{t.x, t.y + 1, t.depth + 1});
//                     }
//                 }

//             }
//             // judge the remain
//             // cout << res << endl;
//             for(int i = 0; i < m; i++) {
//                 for(int j = 0; j < n; j++) {
//                     if(grid[i][j] == 1) {
//                         return -1;
//                     }
//                 }
//             }

//             return res;

//         }
//     };


/**
 * 
 * 2025-5-6
 */

// class Solution {
//     public:
//         bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//             if(numCourses == 1) return true;
//             int n = numCourses;
//             int m = prerequisites.size();
//             // vector<int> fa(numCourses);
//             vector<int> in(numCourses, 0);
//             vector<vector<int>> g(n, vector<int>(n, 0));
//             vector<bool> vis(n, false);

//             for(int i = 0; i < m; i++) {
//                 int x = prerequisites[i][0];
//                 int y = prerequisites[i][1];
//                 g[y][x] = 1;
//                 in[x]++; // 入度++
//             }

//             queue<int> q;
//             for(int i = 0; i < n; i++) {
//                 if(in[i] == 0) {
//                     q.push(i);
//                 }
//             }
            
//             while(!q.empty()) {
//                 int x = q.front();
//                 q.pop();
//                 vis[x] = true;
//                 for(int i = 0; i < n; i++) {
//                     if(g[x][i] == 1) {
//                         in[i]--;
//                         if(in[i] == 0 && !vis[i]) {
//                             q.push(i);
//                         }
//                     }

//                 }
//             }

//             for(int i = 0; i < n; i++) {
//                 if(in[i] > 0) {
//                     return false;
//                 }
//             }

//             return true;
//         }
//     };

// preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// 7ms 就是需要记录root在pre序列中的位置，然后分成两部分处理
// class Solution {
//     private:
//         unordered_map<int, int> mp;

//     public:
//         TreeNode* back(vector<int>& pre, vector<int>& in, int l, int r, int rot) {
//             if(l > r) return nullptr;

//             TreeNode* root = new TreeNode(pre[rot]);
//             int index = mp[pre[rot]];
//             int len = index - l;

//             root->left = back(pre, in, l, l + len - 1, rot + 1);
//             root->right = back(pre, in, l + len + 1, r, rot + len + 1);
//             return root;
//         }
//         TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//             for(int i = 0; i < inorder.size(); i++) {
//                 mp[inorder[i]] = i;
//             }
//             TreeNode* res = back(preorder, inorder, 0, inorder.size() - 1, 0);
//             return res;
//         }
//     };

// 19ms 
// class Solution {
//     private:
//         int res;
//     public:
//         void back2(TreeNode* root, int k, long long sum) {
            
//             if(root == nullptr) {
//                 return;
//             }
//             sum += root->val;
//             if(sum == k) res++;

//             back2(root->left, k, sum);
//             back2(root->right, k, sum);
//         }
//         void back1(TreeNode* root, int k) {
//             if(root == nullptr) {
//                 return;
//             }
//             back2(root, k, 0);
//             back1(root->left, k);
//             back1(root->right, k);
//         }
//         int pathSum(TreeNode* root, int targetSum) {
//             back1(root, targetSum);
//             return res;
//         }
//     };


// 26ms 
class Solution {
    private:
        unordered_map<TreeNode*, TreeNode*> mp;
        unordered_map<int ,bool> vis;
    public:
        void order(TreeNode* root, TreeNode* fa) {
            if(root == nullptr) return;
            mp[root] = fa;

            order(root->left, root);
            order(root->right, root);
        }

        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            order(root, nullptr);
            // vis[p->val] = true;
            // vis[q->val] = true;
            TreeNode* tmp = p;
            while(tmp != nullptr) {
                if(!vis.count(tmp->val)) {
                    vis[tmp->val] = true;
                } else {
                    if(vis[tmp->val]) {
                        return tmp;
                    }
                }
                tmp = mp[tmp];
            }

            tmp = q;
            while(tmp != nullptr) {
                if(!vis.count(tmp->val)) {
                    vis[tmp->val] = true;
                } else {
                    if(vis[tmp->val]) {
                        return tmp;
                    }
                }
                tmp = mp[tmp];
            }

            return nullptr;
        }   
    };