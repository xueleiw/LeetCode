/**
 * 2025-3-29
 * 1-: 暴力求解
 * 2-: 单调栈求解右边第一个大元素或者不存在，但是需要注意的是循环数组问题，长度需要访问到 (2 * n) - 1
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*===============1-: 271ms=====================*/
// class Solution {
//     public:
//         vector<int> nextGreaterElements(vector<int>& nums) {
//             vector<int> res;
//             int max_num = INT_MIN;
//             for(auto &x: nums) {
//                 max_num = max(max_num, x);
//             }

//             for(int i = 0; i < nums.size(); i++) {
//                 if(nums[i] == max_num) {
//                     res.push_back(-1);
//                     continue;
//                 }
//                 int j = (i + 1) % nums.size();
//                 while(i != j) {
//                     if(nums[j] > nums[i]) {
//                         res.push_back(nums[j]);
//                         break;
//                     }
//                     j = (j + 1) % nums.size();
//                 }
//             }

//             return res;
//         }
//     };

/*===============1-: 3ms=====================*/
class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            vector<int> res(nums.size(), -1);
            stack<int> _stack;

            for(int i = 0; i < 2 * nums.size() - 1; i++) {
                int j = i % nums.size();
                // cout << i << endl;
                if(_stack.empty()) {
                    _stack.push(j);
                } else {
                    while(!_stack.empty()) {
                        // cout << 'y' << endl;
                        int index = _stack.top();
                        if(nums[j] > nums[index]) {
                            _stack.pop();
                            res[index] = nums[j];
                        } else {
                            break;
                        }
                    }
                    _stack.push(j);
                }
            }

            return res;
        }
    };

int main() {

    Solution solu;
    vector<int> x = {1,2,1};
    vector<int> res = solu.nextGreaterElements(x);
    for(int i = 0; i < x.size(); i++) {
        cout << res[i] << ' ';
    }

    return 0;
}