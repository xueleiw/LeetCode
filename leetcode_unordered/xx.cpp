#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    double D;
    cin >> D;

    double tmp = D - (int)(D);
    int n = 1;
    int m = (int)D;
    // for(int i = 2; i <= 10000; i++) {
    //     double x = (i * D);
    //     double y = x - (int)x;
    //     if(i == 113 || i == 9937) {
    //         cout << tmp << ' ' << y << endl;
    //     }
    //     if(y < tmp) {
            
    //         tmp = y;
    //         n = i;
    //         m = (int)(x);
    //     }
    // }

    // cout << m << ' ' << n << endl;

    double x = 113 * D;
    double y = 9937 * D;
    // cout << x << ' ' << y;
    printf("%lf  %lf\n", x, y);

    double a = 355.0 / 113;
    double b = 31218.0 / 9937;
    printf("%.16f %.16f", a, b);;
    return 0;
}
// 64 位输出请用 printf("%lld")