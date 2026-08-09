#include <iostream>
using namespace std;

int countOnes(int n) {
    int count = 0;
    unsigned int un = n;
    while (un != 0) {
        count += un & 1; // 检查最低位是否为1
        un = un >> 1;     // 右移一位
    }
    return count;
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    cout << "Number of 1's in binary: " << countOnes(n) << endl;
    return 0;
}