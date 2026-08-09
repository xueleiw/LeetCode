/**
 * 2025-2-25
 * 1-：根左右-前序遍历：注意遍历的时候只添加根元素; 前序遍历的结果是一个递增序列
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


/*================1-: 23ms=====================*/
class Solution {
    private:
        vector<int> tmp;
    public:
        void backtrack(TreeNode* root) {
            if(root->left != nullptr) {
                // tmp.push_back(root->left->val);
                backtrack(root->left);
            }
            tmp.push_back(root->val);
            if(root->right != nullptr) {
                // tmp.push_back(root->right->val);
                backtrack(root->right);
            }
            // 如果是叶子节点则直接返回
            return ;
        }
        bool isValidBST(TreeNode* root) {
            tmp.clear();

            backtrack(root);
            for(int i = 0; i < tmp.size(); i++) {
                cout << tmp[i] << ' ';
            }
            cout << endl;
            for(int i = 0; i < tmp.size() - 1; i++) {
                // cout << tmp[i] << ' ' << endl;
                if(tmp[i] >= tmp[i + 1]) {
                    return false;
                }
            }
            return true;
            
        }
};

int main() {
    TreeNode* x = new TreeNode(1);
    Solution solu;
    TreeNode root = TreeNode(2);
    TreeNode root1 = TreeNode(1);
    TreeNode root2 = TreeNode(3);
    root.left = &root1;
    root.right = &root2;
    cout << "solu is " << solu.isValidBST(&root);

    return 0;
}