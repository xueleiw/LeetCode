#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// 5-1
// 二叉树的深度搜索，一遍即可，过程中记录最大长度  27ms
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    
class Solution {
    private:
        unordered_map<TreeNode*, int> vis;
        int res = 1;
    public:
        void backtrace(TreeNode* root, int count) {
            res = max(res, count);
            if(root == nullptr) {
                return;
            }
    
            // vis[root] = 1; // 
            if(root->left != nullptr) {
                if(root->left->val == root->val + 1) {
                    backtrace(root->left, count + 1);
                } else {
                    backtrace(root->left, 1);
                }
            }
            if(root->right != nullptr) {
                if(root->right->val == root->val + 1) {
                    backtrace(root->right, count + 1);
                } else {
                    backtrace(root->right, 1);
                }
            }
            
            return;
        }
        int longestConsecutive(TreeNode* root) {
            backtrace(root, 1);
            return res;
        }
    };