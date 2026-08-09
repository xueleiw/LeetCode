#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 9-11

struct node{
    int x;
    int y;
};


int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> g(m, vector<char>(n, '0'));
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    queue<node> q2;
    int ex, ey, sx, sy;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
            if(g[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if(g[i][j] == 'E') {
                ex = i;
                ey = j;
            }
            if(g[i][j] == '2') {
                q2.push(node{i, j});
            }
            if(g[i][j] == '1') {
                vis[i][j] = true; // wall 
            }
        }
    }

    queue<pair<node, int>> q;
    q.push(pair<node, int>(node{sx, sy},0));
    int res = -1;
    bool flag = false;

    while(!q.empty()) {
        pair<node, int> t = q.front();
        q.pop();
        node tmp = t.first;
        int depth = t.second;
        vis[tmp.x][tmp.y] = true;

        if(tmp.x - 1 >= 0) {
            if(tmp.x - 1 == ex && tmp.y == ey) {
                res = depth + 1;
                break;
            }
            if(g[tmp.x - 1][tmp.y] == '0' && !vis[tmp.x - 1][tmp.y]) {
                q.push(pair<node, int>(node{tmp.x - 1, tmp.y}, depth + 1));
            } else if(g[tmp.x - 1][tmp.y] == '2') {
                flag = true;
                while(!q2.empty()) {
                    node t2 = q2.front();
                    q2.pop();
                    q.push(pair<node, int>(t2, depth + 1));
                }
            }
            // 1 不用管
        }
        if(tmp.x + 1 < m) {
            if(tmp.x + 1 == ex && tmp.y == ey) {
                res = depth + 1;
                break;
            }
            if(g[tmp.x + 1][tmp.y] == '0' && !vis[tmp.x + 1][tmp.y]) {
                q.push(pair<node, int>(node{tmp.x + 1, tmp.y}, depth + 1));
            } else if(g[tmp.x + 1][tmp.y] == '2') {
                flag = true;
                while(!q2.empty()) {
                    node t2 = q2.front();
                    q2.pop();
                    q.push(pair<node, int>(t2, depth + 1));
                }
            }
        }
        if(tmp.y - 1 >= 0) {
            if(tmp.x == ex && tmp.y - 1 == ey) {
                res = depth + 1;
                break;
            }
            if(g[tmp.x][tmp.y - 1] == '0' && !vis[tmp.x][tmp.y - 1]) {
                q.push(pair<node, int>(node{tmp.x, tmp.y - 1}, depth + 1));
            } else if(g[tmp.x][tmp.y - 1] == '2') {
                flag = true;
                while(!q2.empty()) {
                    node t2 = q2.front();
                    q2.pop();
                    q.push(pair<node, int>(t2, depth + 1));
                }
            }
        }
        if(tmp.y + 1 < n) {
            if(tmp.x == ex && tmp.y + 1 == ey) {
                res = depth + 1;
                break;
            }
            if(g[tmp.x][tmp.y + 1] == '0' && !vis[tmp.x][tmp.y + 1]) {
                q.push(pair<node, int>(node{tmp.x, tmp.y + 1}, depth + 1));
            } else if(g[tmp.x][tmp.y + 1] == '2') {
                flag = true;
                while(!q2.empty()) {
                    node t2 = q2.front();
                    q2.pop();
                    q.push(pair<node, int>(t2, depth + 1));
                }
            }
        }
    }

    cout << res << endl;

    
    return 0;
}

