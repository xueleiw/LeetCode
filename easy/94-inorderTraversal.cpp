/**
 * 2024-12-28
 * 2024-3-24
 * 1-: 根序遍历，使用递归还是比较简单的。 // 左-根-右
 */

#include<iostream>
#include<string.h>
#include<stack>
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

/*=========1-: 0ms=============*/
// class Solution {
// public:
//     void inorder(TreeNode* node, vector<int>& res) {
//         if(node == nullptr) return;
//         // 左-根-右
//         inorder(node->left, res);
//         res.push_back(node->val);
//         inorder(node->right, res);
//     }

//     vector<int> inorderTraversal(TreeNode* root) {
//         static vector<int> res;
//         inorder(root, res);
//         return res;  
//     }
// };

/*===============1-:0ms=====================*/
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            if(root == nullptr) return res;
            stack<TreeNode*> st;

            TreeNode* p = root;
            st.push(p);
            while(!st.empty()) {
                if(p->left != nullptr) {
                    st.push(p);
                    p = p->left;
                } else {
                    p = st.top();
                    st.pop();
                    res.push_back(p->val);
                    p = p->right;
                    if(p != nullptr) st.push(p);
                }
            }
            return res;
        }
    };

int main() {



    return 0;
}