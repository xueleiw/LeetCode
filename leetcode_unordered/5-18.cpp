#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// 5-18
// 先转置然后中心对称翻转
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j <= i; j++) {
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < n / 2; j++) {
//                 swap(matrix[i][j], matrix[i][n - j - 1]);
//             }
//         }
//     }
// };


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
class Solution {
private:
    unordered_map<int, int> mp;
public:
    TreeNode* back(vector<int>& pre, vector<int>& in, int l, int r, int rot) {
        if(l > r) return nullptr;
        if(l == r) {
            return new TreeNode(in[l]);
        }
        TreeNode* root = new TreeNode(pre[rot]);

        int index = mp[pre[rot]];
        int len = index - l;

        root->left = back(pre, in, l, index - 1, rot + 1);
        root->right = back(pre, in, index + 1, r, rot + len + 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* res = back(preorder, inorder, 0, inorder.size() - 1, 0);
        return res;
    }
};