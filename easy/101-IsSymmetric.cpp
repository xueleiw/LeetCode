/*
* 2024-12-30
* 1-: 根据中序遍历的结果存在数组中，判断是否为回文，并且还要judge当前相等数值的一对节点是否属于不同的左右子树，如果是不同的左右子树那么一定是对称
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

/*===============1-: 0ms=====================*/
class Solution {
public:
    void inorder(TreeNode* root, vector<pair<int, string>>& res, string x) {
        if(root == nullptr) return;
        inorder(root->left, res, "left");
        res.push_back(pair<int, string>(root->val, x));
        inorder(root->right, res, "right");
    }

    bool isSymmetric(TreeNode* root) {
        vector<pair<int, string>> res;
        inorder(root, res, "root");
        if(res.size() == 1 || res.empty()) return true;
        int len = res.size();
        for(int i = 0; i < (len / 2); i++) {
            if(res[i].first != res[len - 1 - i].first || (res[i].second == "left" && res[len - 1 - i].second != "right") 
                || (res[i].second == "right" && res[len - 1 - i].second != "left")){
                return false;
            }
            
        }
        
        return true;
    }
};

int main() {

    return 0;
}