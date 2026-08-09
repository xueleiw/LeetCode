/**
 * 2025-1-1
 * 1-: 本题的思路是有序数组的中间数作为BST（平衡二叉搜索树）的根节点，然后递归；
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*===============1-: 3ms=====================*/
class Solution {
public:
    TreeNode* middle(vector<int>& nums, int start, int end) {
        if(start > end) {
            return nullptr; // 证明到了叶子节点，该返回空了
        }
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]); // !!! 注意： 这里使用new申请堆内存，才能显示释放保证一直有效，
                                                  //     否则函数退出之后当前节点就被销毁了。

        root->left = middle(nums, start, mid - 1);
        root->right = middle(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        if(nums.empty()) return root;

        root = middle(nums, 0, nums.size() - 1);
        return root;
    }
};

int main() {

    return 0;
}