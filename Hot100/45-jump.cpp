// 4-7
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

// 23ms 思路就是不断从前往后遍历，找到到达最后一个位置的最远位置，步数加1，然后更改终点，直到pos == 0，回到出发点
// class Solution {
//     public:
//         int jump(vector<int>& nums) {
//             if(nums.size() == 1) return 0;

//             int pos = nums.size() - 1;
//             int ans = 0;
//             while(pos > 0) {
//                 for(int i = 0; i < nums.size(); i++) {
//                     if(nums[i] + i >= pos) {
//                         ans++;
//                         pos = i;
//                         break;
//                     }
//                 }
//             }

//             return ans;
//         }
//     };


// 0ms 思路就是记录当前一步能走多远和能跳多远，这两个位置很关键；如果到达了能走多远的位置说明步数该加1了；精髓就在于只走到倒数第二个位置，
class Solution {
    public:
        int jump(vector<int>& nums) {
            if(nums.size() == 1) return 0;
            int ans = 0;
            int current_pos = 0; // 当前这步能-走-到的最远位置
            int next_pos = 0; // 当前这步能-跳-到的最远位置

            for(int i = 0; i < nums.size() - 1; i++) { // 精髓就在于只走到倒数第二个位置，如果当前步能走到的最远位置不等于 n-1，
                                                      //  那么说明当前这步已经能到达最后了
                next_pos = max(next_pos, i + nums[i]);
                if(current_pos == i) { // 说明该增加步数了
                    ans++;
                    current_pos = next_pos;
                }
            }

            return ans;
        }
    };