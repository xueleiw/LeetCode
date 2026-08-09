#include<iostream>
using namespace std;


int main() {
    int a[5] = {1, 2, 3, 4, 5};
    
    int *p = a;
    // printf("%d %d \n", p[6], a[6]);
    cout << p[6] << ' ' << a[6] << endl;
    int b[5] = {1, 2, 3, 4, 5};
    cout << &b[6] << endl;
    
    
    return 0;
}