#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// 4-28
// 99ms  使用哈希表去重，O(n)的时间内就可以找到长度
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> st;
            int res = 0;
            for(int i = 0; i < nums.size(); i++) {
                st.insert(nums[i]);
            }

            for(auto &num: st) {
                if(!st.count(num - 1)) { // 它就是起点
                    int cur_num = num;
                    int k = 1;
                    while(st.count(cur_num + 1)) {
                        cur_num++;
                        k++;
                    }
                    res = max(res, k);
                }
            }

            return res;
        }
    };


