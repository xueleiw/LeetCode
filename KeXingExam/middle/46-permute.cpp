#include <iostream>
#include <vector>
using namespace std;

// 0908
// class Solution {
//     private:
//         vector<vector<int>> res;
//         vector<int> tmp;
//         vector<bool> vis;

//     public:
//         void backTrace(vector<int>& nums, const int n) {
//             if (tmp.size() == n) {
//                 res.push_back(tmp);
//                 return;
//             }

//             for (int i = 0; i < n; i++) {
//                 if (!vis[i]) {
//                     vis[i] = true;
//                     tmp.push_back(nums[i]);
//                     backTrace(nums, n);
//                     vis[i] = false;
//                     tmp.pop_back();
//                     // backTrace(nums, n);   多了这次就不对了
//                 }
//             }

//             return;
//         }

//         vector<vector<int>> permute(vector<int>& nums) {
//             int n = nums.size();
//             vis.resize(n, false);

//             backTrace(nums, n);

//             return res;
//         }
// };

// 0916
class Solution {
    private:
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> vis;
    public:
        void backtrace(vector<int>& nums, const int n) {
            // 回溯终止条件
            if (tmp.size() == n) {
                res.push_back(tmp);
                return;
            }

            for(int i = 0; i < n; i++) {
                if (!vis[i]) {
                    vis[i] = true;
                    tmp.push_back(nums[i]);
                    backtrace(nums, n);
                    vis[i] = false;
                    tmp.pop_back();
                }
            }

            return;
        }
        vector<vector<int>> permute(vector<int>& nums) {
            res.clear();
            tmp.clear();
            int n = nums.size();
            vis.resize(n, false);

            backtrace(nums, n);

            return res;
        }
};

int main() {
    return 0;
}