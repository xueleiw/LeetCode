#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    vector<long long> a;
    cin >> n;
    long long x;
    for(long long i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    long long res  = 0;
    long long count = 0;
    long long index = 0;
    for(long long i = 0; i < n; i++) {
        // for(int j = i + 1; j < n; j++) {
        //     // cout << (a[i] & a[j]) << ' ';
        //     if((a[i] & a[j]) > res) {
        //         res = (a[i] & a[j]);
        //     }
        // }
        long long tmp = 0;
        long long num = a[i];
        while(num > 0) {
            if(num & 1) {
                tmp++;
            }
            num = num >> 1;
        }
        if(tmp > count) {
            count = tmp;
            index = i;
        }
    }

    for(long long i = 0; i < n; i++) {
        if(i != index) {
            res = max(res, (a[i] & a[index]));
        }
    }

    cout << res << endl;

    return 0;
}