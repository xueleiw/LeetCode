/**
 * 2025-1-9
 * 1-：排序之后使用双指针进行判断，需要特别注意多个数字一样的情况。
 */

#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;


/*================1-: 17ms=====================*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 1) {
            return 1;
        }
        if(nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int p = 0, q = 1;
        int res = 1;
        // for(int i = 0; i < nums.size(); i++) {

        // }
        int tmp = 1;
        while(p != nums.size() && q != nums.size()) {
            
            if(nums[q] == nums[p] + 1) {
                tmp++;
            } else {
                if(nums[q] == nums[p]) { // 排除多个一样的数字情况

                } else {
                    tmp = 1;
                }
            }
            res = max(tmp, res);
            p++;
            q++;
        }

        return res;
    }
};

int main() {
    Solution solu;
    vector<int> x = {0, 2, 1, 1};
    cout << solu.longestConsecutive(x);
    return 0;
}