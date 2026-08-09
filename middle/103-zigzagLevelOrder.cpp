#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
// 4-15
// 0ms 主要是用两个队列分别记录每层的遍历节点，按照奇偶顺序判断是否需要翻转每层的结果

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
    vector<int> tmp;
    vector<int> s;
    public:
        void my_order(TreeNode* root) {
            queue<TreeNode*> q1;
            queue<TreeNode*> q2;

            if(root != nullptr) {
                q1.push(root);
            } else {
                return;
            }

            while(!q1.empty() || !q2.empty()) {
                tmp.clear();
                while(!q1.empty()) {
                    TreeNode* p = q1.front();
                    tmp.push_back(p->val);
                    s.push_back(p->val);
                    q1.pop();
                    
                    if(p->left != nullptr) {
                        q2.push(p->left);
                    }
                    if(p->right != nullptr) {
                        q2.push(p->right);
                    }
                }
                if(!tmp.empty()) {
                    res.push_back(tmp);
                }
                tmp.clear();

                while(!q2.empty()) {
                    TreeNode* p = q2.front();
                    tmp.push_back(p->val);
                    s.push_back(p->val);
                    q2.pop();
                    
                    if(p->left != nullptr) {
                        q1.push(p->left);
                    }
                    if(p->right != nullptr) {
                        q1.push(p->right);
                    }
                }
                if(!tmp.empty()) {
                    reverse(tmp.begin(), tmp.end());
                    res.push_back(tmp);
                }
                
            }
        }

        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            my_order(root);
            return res;
        }
    };

int main() {
    

    return 0;
}
