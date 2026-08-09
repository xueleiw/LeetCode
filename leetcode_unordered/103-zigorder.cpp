#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
// 4-28

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };


class Solution {
    private:
    vector<vector<int>> res;
    public:
        void zig(TreeNode* root) {
            queue<pair<TreeNode*, int>> q;
            int deepth = 1;
            vector<int> tmp;
            q.push(pair<TreeNode*, int>(root, 1));

            while(!q.empty()) {
                TreeNode* cur = q.front().first;
                int cur_deepth = q.front().second;
                q.pop();
                
                if(cur_deepth == deepth) {
                    tmp.push_back(cur->val);
                } else {
                    if(deepth % 2 == 0) {
                        reverse(tmp.begin(), tmp.end());
                        res.push_back(tmp);
                    } else {
                        res.push_back(tmp);
                    }
                    deepth = cur_deepth;
                    tmp.clear();
                    tmp.push_back(cur->val);
                }

                if(cur->left != nullptr) {
                    q.push(pair<TreeNode*, int>(cur->left, cur_deepth + 1));
                }
                if(cur->right != nullptr) {
                    q.push(pair<TreeNode*, int>(cur->right, cur_deepth + 1));
                }
            }

            if(deepth % 2 == 0) {
                reverse(tmp.begin(), tmp.end());
            }
            res.push_back(tmp);

        }

        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if(root == nullptr) {
                return res;
            }
            zig(root);
            return res;
        }
    };