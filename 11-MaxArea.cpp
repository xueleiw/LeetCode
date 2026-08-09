/** 2024-12-25
 * 1-两个指针分别在数组的两端，左右夹击，每次移动高度较小的指针，这样便能保证一定会找到最大的和。-> 双指针
 * 
*/

#include<bits/stdc++.h>
using namespace std;


/*==================1-: 0ms ===========================*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int res = 0;
        //int len = height.size();
        while (i != j) {
            res = max(res, (min(height[i], height[j]) * (j - i)));
            // 每次移动较小的指针
            if(height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }
        
        return res;
    }
};


int main() {


    return 0;
}