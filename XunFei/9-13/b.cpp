#include<iostream>
#include<vector>
using namespace std;
// 9-18 找出小于n的所有质数，然后从大到小依次加一遍判断是否和等于n

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);

    // a[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] == 1) continue;
        for(int j = i; j * i <= n; j++) {
            a[i * j] = 1;
        }
    }

    int sum = 0;
    int res = 0;
    for(int i = n; i >= 1; i--) {
        if(a[i] == 0) {
            sum += i;
            if(sum < n) {
                res++;
            } else if(sum > n) {
                sum -= i;
            } else {
                // ==
                res++;
                break;
            }
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << a[i] << ' ';
    // }
    cout << res << endl;
    return 0;
}

