#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// 4-18
// 记录每个节点父节点，遍历第一个p的父节点路径，记录节点是否被访问，再遍历q的父节点路径，如果遇到了已经访问过的点那么这个点就是公共父节点

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        // TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };
    

class Solution {
    public:
        unordered_map<TreeNode*, TreeNode*> fa;
        unordered_map<TreeNode*, bool> vis;

        void record(TreeNode* root) {
            if(root == nullptr) return;

            if(root->left != nullptr) {
                fa[root->left] = root;
                record(root->left);
            }
            if(root->right != nullptr) {
                fa[root->right] = root;
                record(root->right);
            }


        }

        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            record(root);
            fa[root] = nullptr;
            // 记录每个节点的父亲
            TreeNode* res = nullptr;
            TreeNode* tmp = p;
            while(tmp != nullptr) {
                // cout << tmp->val << ' ';
                vis[tmp] = true;
                tmp = fa[tmp];
            }
            vis[tmp] = true;
            //
            tmp = q;
            while(tmp != nullptr) {
                if(vis[tmp]) {
                    res = tmp;
                    break;
                } else {
                    tmp = fa[tmp];
                    cout << tmp->val << ' ';
                }
            }

            return res;
        }
    };