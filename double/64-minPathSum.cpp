/**
 * 2025-3-17
 * 1-：dp[i][j]代表到达[i][j]的最小和，然后反推dp[i][j]是如何得到的，确定初始化条件，确定循环方向即可；是62题的翻版
 */ 

#include<iostream>
#include<vector>
using namespace std;


/*===============1-: 0ms=====================*/
class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            for(int i = 1; i < m; i++) {
                grid[i][0] += grid[i - 1][0];
            }
            for(int i = 1; i < n; i++) {
                grid[0][i] += grid[0][i - 1];
            }

            for(int i = 1; i < m; i++) {
                for(int j = 1; j < n; j++) {
                    grid[i][j] = min(grid[i - 1][j] + grid[i][j], grid[i][j - 1] + grid[i][j]);
                }
            }

            return grid[m - 1][n - 1];
        }
    };

int main() {

    return 0;
}