/**
 * 2024-12-30
 * 1-: 遍历每个节点，获取每个节点左右子树的深度并相加得到当前节点直径，取所有节点直径的最大值便可得到整个二叉树的直径
 */

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*==============1-: 159ms==========================*/
class Solution {
public:
    int depth(TreeNode* root, int deep) {
        if(root == nullptr) return deep; //返回当前深度
        return max(depth(root->left, deep + 1), depth(root->right, deep + 1));
    }

    void inorder(TreeNode* root, int& res) {
        if(root == nullptr) return;
        //根-左-右的顺序
        res = max(res, depth(root->left, 0) + depth(root->right, 0)); // 取每个节点的直径最大值
        inorder(root->left, res);
        inorder(root->right, res);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        inorder(root, res);
    }
};

int main() {

    return 0;
}
