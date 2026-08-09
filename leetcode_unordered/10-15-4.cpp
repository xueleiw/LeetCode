#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
    int n,m,x;
    cin >> n >> m;
    vector<int> a;
    for(int i = 0;  i < n; i++) {
        cin >> x;
        a.push_back(x);
    }

    unordered_map<int, int> mp;
    mp[1] = n;
    for(int j = 2; j <= 5e5; j++) {
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] % j == 0 || j % a[i] == 0) {
                tmp++;
            }
        }
        mp[j] = tmp;
    }

    for(int i = 0; i < m; i++) {
        cin >> x;
        // int res = 0;
        // for(int j = 0; j < n; j++) {
        //     // cout << x << ' ' << a[j] << endl;
        //     if(x > a[j]) {
        //         if((x % a[j]) == 0) res++;
        //     } else {
        //         if((a[j] % x) == 0) res++;
        //     }
        // }
        cout << mp[x] << endl;
    }

    return 0;
}