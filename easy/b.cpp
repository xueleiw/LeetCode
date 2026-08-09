#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;


int main() {
    int t, n;
    cin >> t;
    while(t > 0) {
        cin >> n;
        t--;
        int min = INT_MAX;
        int max = INT_MIN;
        int x = 0;
        int y = 0;
        int count = 0;
        int max_length = 0;
        int index = 0;

        vector<int> a(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i == 0) {
                x = a[i];
                count = 1;
                // index = i;
            } else {
                y = a[i];
                if(x == y) {
                    count++;
                    // index = i;
                } else {
                    count = 1;
                    // index = i;
                    x = y;
                    y = -1;
                }
            }

            if(count > max_length) {
                max_length = count;
                index = i;
            }
        }
        int res =( n - 1 - index ) + (index + 1 - max_length); 
        // cout << n << ' ' << index << ' ' << max_length << endl;
        cout << res << endl;
    }
    return 0;
}