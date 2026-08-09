/**
 * 2025-2-21
 * 1-：回溯-子集问题无需从头遍历，而且递归时需要从当前位置接着往后遍历
 */


#include<iostream>
#include<vector>
using namespace std;


/*================1-: 0ms=====================*/
class Solution {
    public:
        vector<vector<int>> result;
        vector<int> tmp;
        
        void backtrack(vector<int>& nums, int index) {
            result.push_back(tmp); // 刚开始的空集也算子集的一部分; 因为是收集非叶子结点，所以要在这里

            if(index >= nums.size()) return; // 如果下一个要访问的元素超出了数组边界直接返回，
            // 子集无序所以不需要从头开始遍历，从当前位置开始即可  其实这里也可以不需要判断溢出，因为下面的for循环不会执行，不产生死循环。

            for(int i = index; i < nums.size(); i++) {
                tmp.push_back(nums[i]);
                backtrack(nums, i + 1);
                tmp.pop_back(); // 回溯
            }
        }

        vector<vector<int>> subsets(vector<int>& nums) {
            result.clear();
            tmp.clear();

            backtrack(nums, 0);
            return result;
        }
    };

int main() {

    return 0;
}