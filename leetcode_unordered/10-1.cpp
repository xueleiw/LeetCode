#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     vector<int> res;

//     void backtrace(TreeNode* root) {
//         if(root == nullptr) return;
//         backtrace(root->left);
//         res.push_back(root->val);
//         backtrace(root->right);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         backtrace(root);
//         return res;
//     }
// };


// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == nullptr) return 0;
//         int l = maxDepth(root->left);
//         int r = maxDepth(root->right);
//         return max(l, r) + 1;
//     }
// };


// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(root == nullptr) return nullptr;
//         TreeNode* l = root->left;
//         TreeNode* r = root->right;
//         root->right = l;
//         root->left = r;
//         invertTree(l);
//         invertTree(r);
//         return root;
//     }
// };

// class Solution {
// public:
//     vector<pair<int,int>> res;

//     void back(TreeNode* t, int d) {
//         if(t == nullptr) return;
//         back(t->left, 0);
//         res.push_back(pair<int, int>(t->val, d));
//         back(t->right, 1);
//         return;
//     }
//     bool isSymmetric(TreeNode* root) {
//         back(root, 0);
//         for(int i = 0; i < res.size() / 2; i++) {
//             if(res[i].first != res[res.size() - 1 - i].first || res[i].second == res[res.size() - 1 - i].second) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };  


// class Solution {
// public:
//     int res;

//     int back(TreeNode* t) {
//         if(t == nullptr) return 0;
//         int l = back(t->left);
//         int r = back(t->right);
//         res = max(res, max(l-1, r-1) + 1);
//         return max(l, r) + 1;
//     }

//     int diameterOfBinaryTree(TreeNode* root) {
//         back(root);
//         return res;
//     }   
// };


class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if(root == nullptr) return res;

        q.push(pair<TreeNode*, int>(root, 1));
        int depth = 1;
        while(!q.empty()) {
            pair<TreeNode*, int> x = q.front();
            q.pop();
            if(depth != x.second) {
                res.push_back(tmp);
                tmp.clear();
                depth++;
            }
            tmp.push_back(x.first->val);
            if(x.first->left != nullptr) {
                q.push(pair<TreeNode*, int>(x.first->left, x.second + 1));
            } 
            if(x.first->right != nullptr) {
                q.push(pair<TreeNode*, int>(x.first->right, x.second + 1));
            }
        }
        res.push_back(tmp);

        return res;
    }
};