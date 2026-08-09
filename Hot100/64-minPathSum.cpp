// 4-8
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;


// 0ms 判断路径和的取值 grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            // 初始化首行首列
            for(int i = 1; i < m; i++) {
                grid[i][0] += grid[i - 1][0];
            }
            for(int i = 1; i < n; i++) {
                grid[0][i] += grid[0][i - 1];
            }

            for(int i = 1; i < m; i++) {
                for(int j = 1; j < n; j++) {
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                }
            }

            return grid[m - 1][n - 1];
        }
    };