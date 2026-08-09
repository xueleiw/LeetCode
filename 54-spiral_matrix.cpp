/**
 * 2024-12-23
 * 1-按照4个边界进行判定，以右-下-左-上的顺序进行循环遍历即可
 * 
 */ //: $$
#include<bits/stdc++.h>
using namespace std;

/*=====1: 0ms=========*/ 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // int sum = m * n; // 元素总数
        int x1 = 0, x2 = n, y1 = 0, y2 = m; // 4个边界
        // cout << x1 << '-' << x2 << '-' << y1 << '-' << y2  << endl;
        vector<int> result;
        while(x1 != x2 && y1 != y2) {
            // 按照
            for(int i = x1; i < x2; i++) {
                result.push_back(matrix[y1][i]);
                // cout << matrix[y1][i] << 'a';
            }
            y1++;// 上边界+1
            if(x1 == x2 || y1 == y2)break;
            for(int i = y1; i < y2; i++) {
                result.push_back(matrix[i][x2 - 1]);
                // cout << matrix[i][x2 - 1] << 'b';
            }
            x2--;// 右边界
            if(x1 == x2 || y1 == y2)break;
            for(int i = x2 - 1; i >= x1; i--) {
                result.push_back(matrix[y2 - 1][i]);
                // cout << matrix[y2 - 1][i] << 'c';
            }
            y2--;
            if(x1 == x2 || y1 == y2)break;
            for(int i = y2 - 1; i >= y1; i--) {
                result.push_back(matrix[i][x1]);
                // cout << matrix[i][x1] << 'd';
            }
            x1++;
            // cout << endl;
            // cout << x1 << '-' << x2 << '-' << y1 << '-' << y2  << endl;
        }
        
        return result;
    }
};


int main() {
    Solution solu;
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res = solu.spiralOrder(A);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}