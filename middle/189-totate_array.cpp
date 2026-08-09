/** 2024-12-25
 * 1-用空间换时间，新建一个数组存储转换后的数组
 * 2-暴力原地求解，每次只移动1位，移动n次，但是会超时
 * 3-原地算法~利用双指针k个元素为一组，i指针为了保证组内元素都能被访问，循环K次；j指针每次移动k个位置，直到与a指针相与，每次移动与a指针所在元素交换，
 *      这样，b每到达一个位置都能让一个元素放到正确的位置，时间复杂度O(n);如果还剩一个元素说明剩下元素都已移动完毕
 *      移动完成;  此方法更节省内存。空间复杂度O(1)
*/
#include<iostream>
#include<vector>
using namespace std;



/*=======1: 0ms====================*/
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         vector<int> res;
//         res.resize(nums.size());
//         for(int i = 0; i < nums.size(); i++) {
//             res[(i + k) % (nums.size())] = nums[i];
//         }
//         for(int i = 0; i < nums.size(); i++) {
//             nums[i] = res[i];
//         }
//     }
// };

/*================3-:0ms,相较于1更节省内存，原地算法=======================*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 再多次的移动效果不变
        if(k > nums.size()) {
            k %= nums.size();
        }
        if(k == 0) return;

        int sum = nums.size();
        int i = 0, j = 0;
        while (sum > 1) {
            j = (j + k) % nums.size();
            //cout << "i" << i << "j" << j << endl;
            while (i != j && i < k) {
                swap(nums[i], nums[j]);
                //cout << endl;
                sum--; // 当b指针移动的时候就确定了一个数
                j = (j + k) % nums.size();
                // for(int k = 0; k < nums.size(); k++) {
                //     cout << nums[k] << ' ';
                // }
                // cout << i << j <<sum << endl;
            }
            sum--; // 当i==j退出时说明i位置的元素已到正确位置，这里可以sum需要减一
            i++;
            j = i; 
        }
        
    }
};

int main() {
    Solution solu;
    vector<int> x = {-1,-100,3,99};
    solu.rotate(x, 2);
    
    for(int i = 0; i < x.size(); i++) {
        cout << x[i] << ' ';
    }

    return 0;
}