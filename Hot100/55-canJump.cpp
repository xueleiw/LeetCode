// 4-7
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;


// 693ms 就是判断区间能否覆盖到最后一个点
// class Solution {
//     public:
//         bool canJump(vector<int>& nums) {
//             int n = nums.size();
//             int vis[n + 1];
//             memset(vis, 0, sizeof(vis));
//             vis[0] = 1;

//             for(int i = 0; i < nums.size() - 1; i++) {
//                 if(vis[i]) {
//                     // cout << i << " i ";
//                     for(int j = i; (j < nums.size() && j <= i + nums[i]); j++) {
//                         // cout << 'j' << j << endl;
//                         vis[j] = 1;
//                     }
//                 } else {
//                     break;
//                 }
//             }

//             if(vis[n - 1]) return true;
//             return false;
//         }
//     };


// 0ms 对上面代码的优化，减少了赋值的过程
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int cover = 0;
            if(nums.size() == 1) return true;

            for(int i = 0; i <= cover; i++) {
                cover = max(cover, i + nums[i]);
                if(cover >= nums.size() - 1) return true;
            }

            return false;
        }
    };