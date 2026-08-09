/** 2024-12-25
 * 1-先排序，确定第一个数之后，其实就是在剩下有序的数组里面求两数之和;求两数之和就需要用到双指针了
 * 2-也是先排序，确定前两个数，用O(n^2), 剩下的一个数用二分查找O(log n)
*/

#include<bits/stdc++.h>
using namespace std;


/*========1-: 63ms============*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < len; i++) {
            //确保不会和上一个数一样，以杜绝重复的3元组
            if(i > 0 && nums[i] == nums[i - 1]) {
                // cout <<nums[i] << nums[i - 1] << "continue" << endl;
                continue;
            }
            //  确定第一个数之后，其实就是在剩下有序的数组里面求两数之和，复杂度是O（n）
            int k = len - 1;
            for(int j = i + 1; j < len; j++) {
                //确保不会和上一个数一样，以杜绝重复的3元组
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                // 排序之后后两个数的和一定要大于等于0才能满足条件，否则不满足
                // while(j < k && (nums[j] + nums[k]) >= 0 - nums[i]) {
                //     if(nums[i] + nums[j] + nums[k] == 0) {
                //         if( k < len - 1 && nums[k] == nums[k + 1] ) {

                //         } else {
                //             //cout << i << j << k << endl;
                //             res.push_back({nums[i], nums[j], nums[k]});
                //         }
                       
                //     }
                //     k--;
                // }

                while(j < k && (nums[j] + nums[k]) > -nums[i]) {
                    k--;
                }
                if(j == k) break;

                if(nums[i] + nums[j] == -nums[k]) {
                    res.push_back({nums[i], nums[j], nums[k]});
                }

            }
        }

        return res;
    }
};

int main() {
    Solution solu;
    vector<int> A = {0, 0, 0, 0};
    //vector<int> A = {0, 0, 0};
    vector<vector<int>> res = solu.threeSum(A);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i][0] << ' ' << res[i][1] << ' ' << res[i][2] << endl;
    }

    return 0;
}

