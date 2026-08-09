#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// 9-4
int main() {
    int n, m;
    cin >> n;

    int val;
    string name, res_node;
    vector<string> node;
    int sum = 0;
    vector<vector<int>> g(n, vector<int>(n, -1));
    unordered_map<string, int> mp;
    unordered_map<int, string> mp3;
    unordered_map<string, int> mp2;
    for(int i = 0; i < n; i++) {
        cin >> name >> val;
        // if(val > sum){
        //     sum = val;
        //     res_node = name;
        // }
        mp[name] = i;
        mp2[name] = val;
        mp3[i] = name;
        node.push_back(name);
    }

    cin >> m;
    string x, y;
    int a, b;
    vector<bool> vis(n, false);
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        a = mp[x];
        b = mp[y];
        g[a][b] = 1;
        g[b][a] = 1;
    }

    for(int i = 0; i < n; i++) {
        // cout << i << endl;
        if(!vis[i]) {
            int tmp_sum = 0;
            int tmp_val = 0;
            string tmp_node;
            // vis[i] = true;
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int x = q.front();
                // cout << x << endl;
                q.pop();
                vis[x] = true;
                tmp_sum += mp2[mp3[x]];
                if(mp2[mp3[x]] > tmp_val) {
                    tmp_node = mp3[x];
                }

                for(int j = 0; j < n; j++) {
                    if(g[x][j] == 1 && !vis[j]) {
                        q.push(j);
                    }
                }
            }
            // 找出当前连通子图中的最大值节点和连通子图的和
            if(tmp_sum > sum) {
                sum = tmp_sum;
                res_node = tmp_node;
            }
            
        } else {
            continue;
        }
    }
    
    cout << res_node << ' ' << sum;
    return 0;
}
// 64 位输出请用 printf("%lld")
