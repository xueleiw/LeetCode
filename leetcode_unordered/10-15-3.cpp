#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


int main() {
    long long t, x;
    cin >> t;

    unordered_set<long long> st;
    long long sum = 2;
    for(int i = 3; i <= 100; i++) {
        if(sum > 1e9) {
            cout << i << endl;
            break;
        }
        sum *= i;
        st.insert(sum);
    }

    while(t > 0) {
        t--;
        cin >> x;
        if(st.count(x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }


    return 0;
}