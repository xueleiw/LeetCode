#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// 5-10


class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        // 把四个方向的面积求和然后相加
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            return 0;
        }
        if(grid[i][j] == 0) return 0;
        // cout << i << " " << j << endl;

        int res = 1;
        grid[i][j] = 0;
        res += dfs(grid, i + 1, j, n, m);
        res += dfs(grid, i - 1, j, n, m);
        res += dfs(grid, i, j + 1, n, m);
        res += dfs(grid, i, j - 1, n, m);
        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    // cout << i << " s " << j << endl;
                    res = max(res, dfs(grid, i, j, n, m));
                }
            }
        }

        return res;
    }
};