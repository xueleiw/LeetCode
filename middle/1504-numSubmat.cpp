#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
// 4-15 dp 
// 思路就是计算 i j 位置左上角所有矩阵的个数，类似于矩阵前缀和
// 15ms 
class Solution {
    public:
        int numSubmat(vector<vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();
            vector<vector<int>> num(m, vector<int>(n, 0));

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(mat[i][j] == 0) {
                        num[i][j] = 0;
                    } else {
                        if(j != 0) {
                            // cout << i << ' ' << j << ' ' << num[i][j - 1] << endl;
                            num[i][j] = num[i][j - 1] + 1;
                        } else {
                            num[i][j] = 1;
                        }
                        
                    }
                }
            }

            // for(int i = 0; i < m; i++) {
            //     for(int j = 0; j < n; j++) {
            //         cout << num[i][j] << ' ';
            //     }cout << endl;
            // }

            int res = 0;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(num[i][j] == 0) continue;
                    int col = num[i][j];
                    for(int k = i; k >= 0; k--) {
                        col = min(col, num[k][j]); // 把每列的数收集起来
                        res += col;
                    }
                    
                }
            }

            return res;

        }
    };
