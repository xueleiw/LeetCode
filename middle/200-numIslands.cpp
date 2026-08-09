/**
 * 2025-2-12
 * 1-：dfs-从整个网格开始扫描1的位置进行dfs遍历，每次把dfs遍历到的1置为0，这样，统计dfs的轮数，就是所求结果。
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*================1-: 24ms=====================*/
class Solution {
public:
    void dfs(vector<vector<char>>& g, int i, int j) {
        int row = g.size(); // row
        int column = g[0].size();
        g[i][j] = '0'; // 修改当前点的值,相当于标记访问过了
        // 该点的邻接点只有上下左右四个方向
        if(i - 1 >= 0) {
            if(g[i - 1][j] != '0'){
                dfs(g, i - 1, j);
            }
        }

        if(i + 1 < row) {
            if(g[i + 1][j] != '0'){
                dfs(g, i + 1, j);
            }
        }

        if(j - 1 >= 0) {
            if(g[i][j - 1] != '0'){
                dfs(g, i, j - 1);
            }
        }

        if(j + 1 < column) {
            if(g[i][j + 1] != '0'){
                dfs(g, i, j + 1);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size(); // row
        int column = grid[0].size();
        int res = 0;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(grid[i][j] != '0') {  // 从不是0的位置开始DFS
                    dfs(grid, i, j);
                    res++;
                }
            }
        }

        return res;
    }
};

int main() {

    return 0;
}
