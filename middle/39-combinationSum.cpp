/**
 * 2025-2-22
 * 1-：回溯-刚开始需要排序，保证从小到大求和；无需index + 1；从i开始传参表示当前位置的元素可以重复选取。
 */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*================1-: 0ms=====================*/
class Solution {
    vector<vector<int>> result;
    vector<int> tmp;
    bool vis[31];
    public:
        void backtrack(vector<int>& candidates, int index, int target, int sum) {
            // int sum = 0;
            // for(int i = 0; i < tmp.size(); i++) {
            //     sum += tmp[i];
            // }
            if(sum >= target) {
                if(sum == target) {
                    result.push_back(tmp);
                }
                return;
            }

            for(int i = index; i < candidates.size(); i++) {
                sum += candidates[i];
                tmp.push_back(candidates[i]);
                backtrack(candidates, i, target, sum); // 这里不用index + 1；表示当前位置的元素可以重复选择
                tmp.pop_back();
                sum -= candidates[i];
            }
        }

        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            if(candidates.empty()) return result;

            sort(candidates.begin(), candidates.end());
            backtrack(candidates, 0, target, 0);

            return result;
        }
    };


int main() {

    return 0;
}