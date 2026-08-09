/**
 * 2024-12-22
 * 1-:通过两个数组记录行和列需要被置为0的情况,然后根据这两个数组的情况修改原数组
 */
#include<bits/stdc++.h>
using namespace std;

/*=====1-: 0ms==========*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row[200 + 5];
        bool column[200 + 5];
        int m = matrix.size();
        int n = matrix[0].size();
        memset(row, false, sizeof(row));
        memset(column, false, sizeof(column));

        // 获取位置信息
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0) {
                    row[i] = true;
                    column[j] = true;
                }
            }
        }
        // 修改原数组
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                if(row[i] || column[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {

    // int a[200];
    // memset(a, 0, sizeof(a)); // 
    // for(int i = 0; i < 200; i++) {
    //     cout << a[i] << ' ';
    // }

    return 0;
}
