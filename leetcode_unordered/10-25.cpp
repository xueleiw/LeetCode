#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, n, a, b, c;
    cin >> T;
    while(T > 0) {
        T--;
        cin >> n;
        vector<int> num(3);
        int x;
        for(int i = 0; i < n; i++) {
            cin >> x;
            num[x]++;
        }
        cin >> a >> b >> c;
        // cout << num[0] << ' ' << num[1] << ' ' << num[2] << endl;
        int res = 0;
        if(c >= num[1]) {
            res += num[1];
            c -= num[1];
        } else {
            res += c;
            c = 0;
        }
        // cout << res << ' ' << c << endl;

        b += c;
        if(b >= num[0]) {
            res += num[0];
        } else {
            res += b;
        }
        cout << res << endl;
    }


    return 0;
}
// 64 位输出请用 printf("%lld")