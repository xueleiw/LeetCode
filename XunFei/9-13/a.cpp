#include<iostream>
#include<vector>
using namespace std;
// 9-18

int main() {
    int n;
    cin >> n;

    long long sum = 1;
    for(int i = 1; i <= n; i++) {
        sum *= i;
    }

    int count = 0;
    while(sum > 0) {
        int x = sum % 10;
        if(x == 0) {
            count++;
        }
        sum /= 10;
    }

    cout << count << endl;
    return 0;
}

