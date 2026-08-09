/**
 * 2025-3-5
 * 1-：首先判断两个节点 p q是否互为父节点包含；然后获得前序序列，从离p q二者最近的数往前逐个判断每个节点是不是他们的父节点即可。
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

/*================1-: 7ms=====================*/
class Solution {
    private:
        bool p_contain_q;
        vector<int> nums;
        TreeNode* res;
    public:
        void contain(TreeNode* p, TreeNode* q) {
            if(p == nullptr) {
                return;
            }
            if(p->val == q->val) {
                p_contain_q = true;
                return;
            }
            contain(p->left, q);
            contain(p->right, q);
        }

        // 获得前序序列
        void backtrace(TreeNode* root) {
            if(root == nullptr) {
                return;
            }
            
            nums.push_back(root->val);
            backtrace(root->left);
            backtrace(root->right);
        }

        void backtrace2(TreeNode* root, int num) {
            if(root == nullptr) {
                return;
            }
            
            if(root->val == num) {
                res = root;
                return;
            }
            backtrace2(root->left, num);
            backtrace2(root->right, num);
        }

        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            p_contain_q = false;
            res = nullptr;
            nums.clear();
            contain(p, q);
            // 如果一个节点为另一个的父节点
            if(p_contain_q) return p;
            contain(q, p);
            if(p_contain_q) return q;

            // 如果不是
            backtrace(root);
            int tmp_num = -1;
            int index = -1;
            for(int i = 0; i < nums.size() - 1; i++) {
                if(nums[i + 1] == p->val || nums[i + 1] == q->val) {
                    tmp_num = nums[i];
                    index = i;
                    break;
                }
            }
            for(int i = index; i >= 0; i--) {
                backtrace2(root, nums[i]);
                p_contain_q = false;
                // bool tmp = false;
                contain(res, p);
                if(p_contain_q) {
                    p_contain_q = false;
                    contain(res, q);
                    if(p_contain_q) {
                        return res;
                    }
                } else {
                    continue;
                } 
            }
            // backtrace2(root, tmp_num);
            // return res;

        }
    };

int main() {

    return 0;
}