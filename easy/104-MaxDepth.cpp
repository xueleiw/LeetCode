/**
 * 2024-12-30
 * 1-: 递归遍历比较左右子树深度的最大值然后返回上一层，最终得到最大深度
 */
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*===============1-: 0ms=====================*/
class Solution {
public:
    int depth(TreeNode* root, int deep) {
        if(root == nullptr) return deep;// 如果当前节点是空，返回传进来的深度
        return max(depth(root->left, deep + 1), depth(root->right, deep + 1)); // 如果当前节点不是空，返回左右子树最大深度
    }

    int maxDepth(TreeNode* root) {
        return depth(root, 0);
    }
};



int main() {



    return 0;
}