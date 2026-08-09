/**
 * 2025-1-13
 * 1-：暴力解法  复杂度O(m * n)
 * 2-: 从左下角开始二分查找，小了往上走，大了就往右走，直到超出边界  复杂度O(m + n)
 */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*================1-: 844ms=====================*/
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row = matrix.size();
//         int cloumn = matrix[0].size();

//         for(int i = 0; i < row; i++) {
//             for(int j = 0; j < cloumn; j++) {
//                 if(matrix[i][j] == target) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };

/*================2-: 43ms=====================*/
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row = matrix.size();
//         int cloumn = matrix[0].size();

//         int i = row - 1; 
//         int j = 0;
//         while(i >= 0 && j < cloumn) {
//             if(target == matrix[i][j]) {
//                 return true;
//             } else if(target < matrix[i][j]) { // 小的话往上走
//                 i--;
//             } else if(target > matrix[i][j]) { // 大了就往右走
//                 j++;
//             }
//         }
        

//         return false;
//     }
// };




int main() {

    return 0;
}