#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// 5-11

// 7ms
class Solution {
public:
    int dis[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    for(int k = 0; k < 4; k++) {
                        int x = i + dis[k][0];
                        int y = j + dis[k][1];
                        if(x >= 0 && y >= 0 && x < n && y < m) {
                            if(grid[x][y] == 0) {
                                res++;
                            }
                        } else {
                            res++;
                        }
                    }
                }
            }
        }

        return res;
    }
};

