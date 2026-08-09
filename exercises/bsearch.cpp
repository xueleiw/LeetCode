#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// 4-19


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            if(root == nullptr) return {};
            vector<int> res;
            stack<TreeNode*> st;
            st.push(root);
            TreeNode* tmp = nullptr;

            while(!st.empty()) {
                tmp = st.top();
                // TreeNode* p = tmp;
                res.push_back(tmp->val);
                st.pop();
                if(tmp->right != nullptr) st.push(tmp->right);
                if(tmp->left != nullptr) st.push(tmp->left);

            }

            return res;
        }
    };

// 
int main() {
    // Solution solu;
    // TreeNode* p3 = new TreeNode(3);
    // TreeNode* p2 = new TreeNode(2, p3, nullptr);
    // TreeNode* p1 = new TreeNode(1, nullptr, p2);
    // vector<int> res = solu.inorderTraversal(p1);


    return 0;
}
