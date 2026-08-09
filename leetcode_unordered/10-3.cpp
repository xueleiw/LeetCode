#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     TreeNode* create(vector<int>& nums, int l, int r) {
//         int mid = (l + r) / 2;
//         if(l > r) return nullptr;
//         if(l == r) {
//             TreeNode* res = new TreeNode(nums[l]);
//             return res;
//         }

//         TreeNode* res = new TreeNode(nums[mid]);
//         res->left = create(nums, l, mid - 1);
//         res->right = create(nums, mid + 1 ,r);
//         return res;
//     }

//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         if(nums.size() == 0) return nullptr;
//         return create(nums, 0, nums.size() - 1);
//     }
// };


// class Solution {
// public:
//     vector<int> res;
//     void backtr(TreeNode* root) {
//         if(root == nullptr) return;
//         backtr(root->left);
//         res.push_back(root->val);
//         backtr(root->right);
//         return;
//     }

//     bool isValidBST(TreeNode* root) {
//         backtr(root);
//         if(res.size() <= 1) return true;
//         for(int i = 0; i < res.size() - 1; i++) {
//             if(res[i] >= res[i + 1]) return false;
//         }

//         return true;
//     }
// };


// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> res;
//         vector<int> tmp;
//         if(root == nullptr) return res;
//         queue<pair<TreeNode*, int>> q;       
//         q.push(pair<TreeNode*, int>(root, 1));
//         // tmp.push_back(root->val);
//         int depth = 1;

//         while(!q.empty()) {
//             auto x = q.front();
//             q.pop();
//             if(x.second != depth) {
//                 res.push_back(tmp[tmp.size() - 1]);
//                 tmp.clear();
//                 depth++;
//             } 

//             tmp.push_back(x.first->val);
//             if(x.first->left != nullptr) {
//                 q.emplace(x.first->left, x.second + 1);
//             }
//             if(x.first->right != nullptr) {
//                 q.emplace(x.first->right, x.second + 1);
//             }
//         }
//         res.push_back(tmp[tmp.size() - 1]);

//         return res;
//     }
// };


// class Solution {
// public:
//     TreeNode* back(TreeNode* root) {
//         if(root == nullptr) return nullptr;
//         if(root->left == nullptr && root->right == nullptr) return root;
        
//         TreeNode* l = root->left;
//         TreeNode* r = root->right;
//         root->left = nullptr;
//         if(l == nullptr) {
//             root->right = back(r);
//         } else {
//             root->right = back(l);
//             TreeNode* p = l;
//             while(p->right != nullptr) {
//                 p = p->right;
//             }
//             p->right = back(r);
//         }

//         return root;
//     }

//     void flatten(TreeNode* root) {
//         back(root);
//     }
// };

