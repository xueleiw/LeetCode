#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// 9-20

int main() {
    int n, m, op, x, y;
    cin >> n >> m;
    unordered_map<int, int> mp;
    vector<int> a(n + 1);
    vector<int> w(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        w[a[i]] = 0;// 
        mp[a[i]]++;
    }

    for(int i = 0; i < m; i++) {
        cin >> op;
        switch (op) {
            case 1: 
                cin >> x >> y;
                w[a[x]] += y;

                break;
            case 2:
                cin >> x >> y;
                w[a[x]] -= y;
                break;
            case 3:
                cin >> x;
                // cout << w[a[x]] << ' ' << mp[a[x]] << endl;
                float ans = (float)w[a[x]] / mp[a[x]];
                // cout << ans << endl;
                printf("%.5f\n", ans);

                break;
        }
    }

    return 0;
}
