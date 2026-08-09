/**
 * 2025-3-24
 * 1-：迭代法前序遍历
 */ // 

#include<iostream>
#include<vector>
#include<stack>
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
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> st;
            if(root == nullptr) {
                return res;
            }

            TreeNode* p = root;
            st.push(p);
            while(!st.empty()) {
                p = st.top();
                res.push_back(p->val); // root->val
                st.pop();
                //
                if(p->right != nullptr) st.push(p->right);
                if(p->left != nullptr) st.push(p->left);
            }

            return res;
        }
    };

int main() {

    return 0;
}