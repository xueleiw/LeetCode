#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
// 4-22

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
        vector<int> postorderTraversal(TreeNode* root) {
            if(root == nullptr) return {};
            vector<int> res;
            stack<TreeNode*> st;
            
            st.push(root);
            while(!st.empty()) {
                TreeNode* tmp = st.top();
                res.push_back(tmp->val);
                st.pop();
                if(tmp->left != nullptr) {
                    st.push(tmp->left);
                }
                if(tmp->right != nullptr) {
                    st.push(tmp->right);
                }
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };

