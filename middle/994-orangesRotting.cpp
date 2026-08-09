/**
 * 2025-2-12
 * 1-：BFS-从值为2的地方开始bfs逐层遍历（如果有多个2则同时放入队列视为一层即可）；每遍历一层时间+1，最后返回层数最大的遍历情况
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*================1-: 0ms=====================*/
/**
 * 注意数组的判空、bfs之后仍然存在值为1的情况，说明应该直接返回-1，所有的1并不能都变成2
 * */
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        queue<pair<pair<int, int>, int>> queue;
        int res = 0;
        int row = grid.size();
        int column = grid[0].size();

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(grid[i][j] == 2) {
                    // pair<pair<int, int>, int> x = make_pair(make_pair(i, j), 0);
                    queue.push(make_pair(make_pair(i, j), 0)); //第0层
                }
            }
        }
        // 进行BFS遍历
        // if(queue.empty()) return -1; // 没有腐烂的水果，直接返回-1  ***这里不能直接返回，如果既没有腐烂也没有正常的水果，全是空位那么时间是0
        while(!queue.empty()) {
            pair<pair<int, int>, int> point = queue.front();
            queue.pop();
            int x = point.first.first;
            int y = point.first.second;
            int deepth = point.second;
            res = max(deepth, res);

            if(x - 1 >= 0) {
                if(grid[x - 1][y] == 1){
                    grid[x - 1][y] = 2; // 将下一层数据修改，水果腐烂了
                    queue.push(make_pair(make_pair(x - 1, y), deepth + 1));
                }
            }

            if(x + 1 < row) {
                if(grid[x + 1][y] == 1){
                    grid[x + 1][y] = 2; // 将下一层数据修改，水果腐烂了
                    queue.push(make_pair(make_pair(x + 1, y), deepth + 1));
                }
            }

            if(y - 1 >= 0) {
                if(grid[x][y - 1] == 1){
                    grid[x][y - 1] = 2; // 将下一层数据修改，水果腐烂了
                    queue.push(make_pair(make_pair(x, y - 1), deepth + 1));
                }
            }

            if(y + 1 < column) {
                if(grid[x][y + 1] == 1){
                    grid[x][y + 1] = 2; // 将下一层数据修改，水果腐烂了
                    queue.push(make_pair(make_pair(x, y + 1), deepth + 1));
                }
            }
        }
        // 最后检查一下是否有遗漏的情况导致该位置被孤立，始终无法变为2
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(grid[i][j] == 1) { // 如果还有新鲜的那么就输出-1
                    return -1;
                }
            }
        }

        return res;

    }
};

int main() {

    return 0;
}