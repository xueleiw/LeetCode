#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){

    int n;
    if(!(cin >> n)) return 0;
    vector<int64> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int64> b(n+1);
    for(int i=1;i<=n;i++) cin >> b[i];

    // 建成年序列 p：按 b 升序排列编号
    vector<int> ids(n);
    for(int i=0;i<n;i++) ids[i] = i+1;
    sort(ids.begin(), ids.end(), [&](int x, int y){
        if(b[x] != b[y]) return b[x] < b[y];
        return x < y;
    });
    vector<int> p(n+1); // 1-based positions -> id
    vector<int> pos(n+1); // id -> position
    for(int i=1;i<=n;i++){
        p[i] = ids[i-1];
        pos[p[i]] = i;
    }

    // 前缀和 of id_by_pos
    vector<int64> pref(n+1, 0);
    for(int i=1;i<=n;i++) pref[i] = pref[i-1] + p[i];

    // 差分用于统计每个位置被“全额贡献”多少次
    vector<int64> diff(n+3, 0);
    vector<int64> extra(n+2, 0); // 部分贡献累积
    vector<int64> total_given(n+1, 0);

    for(int id = 1; id <= n; id++){
        int posi = pos[id];
        int64 total_suf = pref[n] - pref[posi];
        int64 given = min(a[id], total_suf);
        total_given[id] = given;
        if(given == 0) continue;
        if(given == total_suf){
            // full to posi+1 .. n
            if(posi+1 <= n){
                diff[posi+1] += 1;
                diff[n+1] -= 1;
            }
        } else {
            // 找最小 t > posi, s.t. pref[t] - pref[posi] > given
            int L = posi+1, R = n, t = n+1;
            while(L <= R){
                int mid = (L+R)/2;
                if(pref[mid] - pref[posi] > given){
                    t = mid;
                    R = mid-1;
                } else L = mid+1;
            }
            // full to posi+1 .. t-1
            if(posi+1 <= t-1){
                diff[posi+1] += 1;
                diff[t] -= 1;
            }
            // partial to t
            int64 full_before = pref[t-1] - pref[posi]; // sum given to posi+1..t-1
            int64 rem = given - full_before; // 0 < rem < p[t]
            if(rem > 0) extra[t] += rem;
        }
    }

    // 扫描得到 times[pos]
    vector<int64> times(n+1, 0);
    int64 cur = 0;
    for(int i=1;i<=n;i++){
        cur += diff[i];
        times[i] = cur;
    }

    // recv at position
    vector<int64> recv_at_pos(n+1, 0);
    for(int i=1;i<=n;i++){
        recv_at_pos[i] = times[i] * (int64)p[i] + extra[i];
    }

    // 输出 final per id in id order 1..n
    vector<int64> ans(n+1,0);
    for(int id=1;id<=n;id++){
        int posi = pos[id];
        ans[id] = a[id] - total_given[id] + recv_at_pos[posi];
    }

    for(int id=1; id<=n; id++){
        if(id>1) cout << ' ';
        cout << ans[id];
    }
    cout << '\n';
    return 0;
}
