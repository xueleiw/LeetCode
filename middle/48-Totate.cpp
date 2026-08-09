/**
 * 2025-1-12
 * 1-：很巧妙的数学题，先转置，再按列对称交换即可
 * 2-: 直接按照旋转90度之后的矩阵遍历，将元素先存下来，然后再赋值回原矩阵即可
 * $$
 */

#include<iostream>
#include<vector>
using namespace std;


/*=========1-: 0ms====================*/
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int row = matrix.size();
//         int column = matrix[0].size();
//         // 矩阵转置 -- > 这里注意转置的时候只按上三角交换
//         for(int i = 0; i < row; i++) {
//             for(int j = i; j < column; j++) {
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }
//         // 对称交换
//         for(int i = 0; i < row; i++) {
//             for(int j = 0; j < column / 2; j++) {
//                 swap(matrix[i][j], matrix[i][column - j - 1]);
//             }
//         }
//     }
// };

/*=========2-: 0ms====================*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<int> tmp;

        for(int j = 0; j < column; j++) {
            for(int i = row - 1; i >= 0; i--) {
                tmp.push_back(matrix[i][j]);
            }
        }

        int index = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                matrix[i][j] = tmp[index];
                index++;
            }
        }
    }
};


int main() {
    return 0;
}