/**
 * 2025-3-10
 * 1-：关键是看覆盖范围，能否覆盖到最后一个位置
 */ // $

#include<iostream>
#include<vector>
using namespace std;

 /*================1-: 0ms=====================*/
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int len = nums.size();
            bool vis[10005];
            vis[0] = true;
            for(int i = 0; i < nums.size(); i++) {
                // if(nums[i] == 0) continue; // 0步不能覆盖后面任何位置
                int stop = 0;
                if(i + nums[i] + 1 > nums.size()) {
                    stop = nums.size();
                } else {
                    stop = i + nums[i] + 1;
                }
                for(int j = i + 1; j < stop; j++) {
                    vis[j] = true;
                }
            }

            for(int i = 0; i < nums.size(); i++) {
                cout<< vis[i] << ' ';
                if(vis[i] != true) {
                    return false;
                }
            }
            return true;
            // 关键是看覆盖范围，能否覆盖到最后一个位置
        }
    };

int main() {
    Solution solu;
    vector<int> x = {1,0,8,0};
    cout << solu.canJump(x);
    return 0;
}