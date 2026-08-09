#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
// 4-15 


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 思想：层序遍历的过程中，如果遇到了空节点那么他后面就不该再出现非空节点
 class Solution {
    private:
        bool flag;
    public:

        bool isCompleteTree(TreeNode* root) {
            flag = false;
            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()) {
                TreeNode *tmp = q.front();
                q.pop();

                if(tmp == nullptr) {
                    flag = true; // 已经遍历到一个空节点了
                } else {
                    // cout << tmp->val << endl;
                    if(flag) {
                        // cout << "sss" << endl;
                        return false;
                    }
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
            }

            return true;
        }
    };