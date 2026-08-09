#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 3,9,20,15,7], inorder = [9,3,15,20,7]
// class Solution {
//     unordered_map<int, int> mp;
// public:
//     TreeNode* trace(vector<int>& pre, vector<int>& in, int l, int r, int rot) {
//         if(l > r) return nullptr;
//         if(l == r) {
//             return new TreeNode(in[l]);
//         }

//         int index = mp[pre[rot]];
//         int len = index - l;
//         TreeNode* root = new TreeNode(pre[rot]);
//         root->left = trace(pre, in, l, index - 1, rot + 1);
//         root->right = trace(pre, in, index + 1, r, rot + len + 1);

//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
//         for(int i = 0; i < inorder.size(); i++) {
//             mp[inorder[i]] = i;
//         }

//         TreeNode* res = trace(preorder, inorder, 0, inorder.size() - 1, 0);
//         return res;
//     }
// };

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int i = 0, j = nums.size();
//         int mid = (i + j) / 2;
//         while(i < j) {
//             if(nums[mid] < target) {
//                 i = mid + 1;
//                 mid = (i + j) / 2;
//             } else if(nums[mid] > target) {
//                 j = mid;
//                 mid = (i + j) / 2;
//             } else {
//                 return mid;
//             }
//         }

//         return -1;
//     }
// };