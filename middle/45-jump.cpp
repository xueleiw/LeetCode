/**
 * 2025-3-10
 * 1-：O(n^2),从后往前每次找跨度最大的位置；但是找的时候需要从前往后遍历，这样做的目的是为了保证一定有位置可以到达，
 *     如果一昧的倒推最大步长可能会导致无法回到起点。
 */ // $$

#include<iostream>
#include<vector>
using namespace std;


/*================1-: 31ms=====================*/
class Solution {
    public:
        int jump(vector<int>& nums) {
            int position = nums.size() - 1;
            int res = 0;
            while(position > 0) { // 如果退回到索引0就该终止循环了
                for(int i = 0; i < nums.size(); i++) {
                    if(i + nums[i] >= position) {
                        position = i;
                        res++; // 说明这里跳了一步
                        break;
                    }
                }
            }

            return res;
        }
};


int main() {

    return 0;
}