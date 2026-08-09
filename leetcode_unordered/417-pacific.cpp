#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// 5-10 
// 2ms m*n
// 如果暴力每个点则会超时，从边界出发，两次dfs，重复访问到的点就是符合要求的点；
class Solution {
public:
    int dis[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<int>>& g, vector<vector<bool>>& vis, int i, int j, int n, int m) {
        // if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j]) {
        //     return;
        // }
        if(vis[i][j]) return;

        vis[i][j] = true;
        for(int k = 0; k < 4; k++) {
            int x = i + dis[k][0];
            int y = j + dis[k][1];
            if(x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && g[i][j] <= g[x][y]) {
                dfs(g, vis, x, y, n, m);
            }
        }
        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;

        vector<vector<bool>> first(n, vector<bool>(m, false));
        vector<vector<bool>> second(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            dfs(heights, first, i, 0, n, m);
            // dfs(heights, second, i, m - 1, n, m);
        }
        for(int i = 0; i < n; i++) {
            // dfs(heights, first, i, 0, n, m);
            dfs(heights, second, i, m - 1, n, m);
        }
        for(int i = 0; i < m; i++) {
            dfs(heights, first, 0, i, n, m);
            // dfs(heights, second, n - 1, i, n, m);
        }
        for(int i = 0; i < m; i++) {
            // dfs(heights, first, 0, i, n, m);
            dfs(heights, second, n - 1, i, n, m);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // cout << first[i][j] << ' ';
                if(first[i][j] == true && second[i][j] == true) {
                    res.push_back({i, j});
                }
            } // cout << endl;
        }

        return res;
    }
};