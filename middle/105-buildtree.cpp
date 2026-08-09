#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// 4-24

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
        unordered_map<int, int> mp;
    public:
        // root是前序序列的索引  left right 是当前的区间
        TreeNode* cur(vector<int>& pre, int root, int left, int right) {
            if(left > right) {
                return nullptr;
            }
            if(left == right) {
                return new TreeNode(pre[root]);
            }
            TreeNode* res = new TreeNode(pre[root]);
            int d = mp[pre[root]];
            int length = d - left + 1;
            res->left = cur(pre, root + 1, left, d - 1);
            res->right = cur(pre, root + length, d + 1, right);
            return res;
        }
    
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            for(int i = 0; i < inorder.size(); i++) {
                mp[inorder[i]] = i; // 记录位置，方便查找
            }
    
            return cur(preorder, 0, 0, inorder.size() - 1);
        }
    };
