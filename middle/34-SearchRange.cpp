/**
 * 2025-1-6
 * 1-: 分类讨论即可 未找到 找到1个 找到多个位置  进行最后处理
 */


#include<iostream>
#include<vector>
using namespace std;


/*=================1-: 0ms=============================*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;  
            
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                res.push_back(i);
            }
        }


        if(res.empty()) { // 遍历未找到
            res.push_back(-1);
            res.push_back(-1);
        } else if (res.size() == 1) {  // 只找到一个
            res.push_back(res[0]);
        } else if (res.size() > 2) {  // 找到很多
            int x = res[0];
            int y = res[res.size() - 1];
            res.clear();
            res.push_back(x);
            res.push_back(y);
        }

        return res;
    }
};

int main() {

    return 0;
}