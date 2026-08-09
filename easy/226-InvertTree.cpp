/**
 * 2024-12-30
 * 1-: 从上至下递归的将每个节点的左右子节点进行交换，直到所有的节点被遍历交换一次
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
    void invert(TreeNode* root) {
        if(root == nullptr){
            // 空节点（外部节点）不能翻转
        } else {
            swap(root->left, root->right); //
            invert(root->left);
            invert(root->right);
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        invert(root);
    }
};

int main() {


    return 0;
}