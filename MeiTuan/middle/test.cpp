#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<cmath>
using namespace std;


void fun(string tmp) {
    int n = tmp.length();
    int sum = 0;
    int po = 0; // 幂次
    for(int i = n - 1; i > -1; i--) {
        if(isdigit(tmp[i])) {
            sum += (tmp[i] - '0') * pow(10, po);
            po++;
        } else if(tmp[i] == '.') {
            
            cout << "sum is " << sum << endl;
            if(sum > 255) return;
            if(tmp[i + 1] == '0' && po >= 2) return;
            po = 0;
            sum = 0;
        }
    }

    
    cout << "sum is " << sum << endl;
    if(sum > 255) return;
    if(tmp[0] == '0' && po >= 2) return;
    cout << tmp;
}

int main() {
    fun("1.01.02.3");
    // fun("22.5521.11.135");
    return 0;
}