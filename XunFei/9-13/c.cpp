#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1e7;
static int spf[MAXA + 1]; // smallest prime factor

// 预处理 SPF
void sieve() {
    for (int i = 2; i <= MAXA; i++) {
        if (!spf[i]) {
            spf[i] = i;
            if ((long long)i * i <= MAXA) {
                for (long long j = (long long)i * i; j <= MAXA; j += i) {
                    if (!spf[j]) spf[j] = i;
                }
            }
        }
    }
}

// 计算重量
int weight(int x) {
    int res = 1;
    while (x > 1) {
        int p = spf[x];
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        res = max(res, cnt);
    }
    return res;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    sieve();

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> w(n + 1);
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            w[i] = weight(a);
        }

        vector<long long> s(n + 1, 0);
        for (int i = 1; i <= n; i++) s[i] = s[i-1] + w[i];

        long long ans = 0;
        deque<int> dq;
        dq.push_back(0);
        for (int r = 1; r <= n; r++) {
            while (!dq.empty() && dq.front() < r - k) dq.pop_front();
            ans = max(ans, s[r] - s[dq.front()]);
            while (!dq.empty() && s[dq.back()] >= s[r]) dq.pop_back();
            dq.push_back(r);
        }
        cout << "sss" << endl;
        cout << ans << "\n";
    }
    return 0;
}
