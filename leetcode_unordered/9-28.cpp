#include <iostream>
#include <vector>
#include <stdlib.h>
#include <array>
#include <queue>
#include <deque>
using namespace std;

void PrintV(int &t) { cout << "lvalue" << endl; } 
void PrintV(int &&t) { cout << "rvalue" << endl; } 
template<typename T> 
void Test(T &&t) 
{ PrintV(t); PrintV(std::forward<T>(t)); PrintV(std::move(t)); }


int main() {

    // const char *str3 = "-123456"; // 前面有空格，后面有字母
    // string str3 = "123";
    // int num3 = atoi(str3.c_str());
    // cout << str3 << endl;
    // printf("%s\n", str3.c_str());
    // printf("str3 = %s, atoi(str3) = %d\n", str3, num3);

    array<int, 5> a = {0,0,0,0,1};
    vector<int> v;
    v.resize(10);
    cout << v.size() << endl;

    deque<int> q;
    q.push_back(1);
    cout << q[0] << endl;
    queue<int> q1;
    q1.push(1);
    // cout << q1[0] << endl;    --- 不能按索引访问

    int b[5] = {1, 2, 3, 4, 5};
    cout << sizeof(b) / sizeof(b[0]) << endl;

    int x = 4;
    int& y = x;
    cout << y << endl;
    

    int z = 1; Test(z); // lvalue lvalue rvalue 
    Test(forward<int>(z)); // lvalue rvalue rvalue

    return 0;
}