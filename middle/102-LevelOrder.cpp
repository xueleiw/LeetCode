/**
 * 2025-1-1
 * 1-: 每次将当前节点的左右子树放入队列，然后将当前节点存入结果数组；但是结果按层分开，所以需要将入队的节点增加一个深度depth参数以区分不同层。
 * 
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

/*===============1-: 0ms=====================*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> node_queue;
        
        int tmp_depth = 1;
        vector<int> tmp_res;

        if(root == nullptr) return res;
        node_queue.push(pair<TreeNode*, int>(root, 1));
        while(!node_queue.empty()) {
            pair<TreeNode*, int> p = node_queue.front();
            if(p.second == tmp_depth) { // 如果节点的深度等于目前正在记录的深度，那么说明它们属于同一层
                tmp_res.push_back(p.first->val);
            } else {
                tmp_depth = p.second; // 修改正在记录的深度，说明到下一层了，把上一层存起来
                res.push_back(tmp_res);
                tmp_res.clear();
                tmp_res.push_back(p.first->val);
            }

            
            if(p.first->left != nullptr) {
                node_queue.push(pair<TreeNode*, int>(p.first->left, p.second + 1));
            }
            if(p.first->right != nullptr) {
                node_queue.push(pair<TreeNode*, int>(p.first->right, p.second + 1));
            }

            node_queue.pop(); // 弹出队首元素

        }

        res.push_back(tmp_res); // 把最后一层存起来
        
        return res;

    }
};

int main() {


    return 0;
}