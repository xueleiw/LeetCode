#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    vector<int> a;
    a.reserve(N);
    int x;
    while ((int)a.size() < N && (cin >> x)) a.push_back(x);
    N = (int)a.size();

    deque<int> minq, maxq; // 存下标，minq 单调递增（值），maxq 单调递减（值）
    int l = 0;
    int bestLen = 0;
    vector<pair<int,int>> ans;

    for (int r = 0; r < N; ++r) {
        int v = a[r];
        // 若不在 [18,24]，窗口重置
        if (v < 18 || v > 24) {
            minq.clear();
            maxq.clear();
            l = r + 1;
            continue;
        }
        // 维护单调队列（插入 r）
        while (!minq.empty() && a[minq.back()] >= v) minq.pop_back();
        minq.push_back(r);
        while (!maxq.empty() && a[maxq.back()] <= v) maxq.pop_back();
        maxq.push_back(r);

        // 收缩直到满足 max - min <= 4
        while (!minq.empty() && !maxq.empty() && a[maxq.front()] - a[minq.front()] > 4) {
            if (minq.front() == l) minq.pop_front();
            if (maxq.front() == l) maxq.pop_front();
            ++l;
        }

        // 记录答案
        int len = r - l + 1;
        if (len > 0) {
            if (len > bestLen) {
                bestLen = len;
                ans.clear();
                ans.emplace_back(l, r);
            } else if (len == bestLen) {
                ans.emplace_back(l, r);
            }
        }
    }

    for (auto &p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}
