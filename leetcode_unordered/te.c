#include<stdio.h>

int main() {

    // int arr[1][10] = {{1, 2, 3}};  // 1行10列的数组
    // // int (*p)[10] = arr;            // P 指向 arr[0]
    // // printf("%d\n", (*p)[1]);
    // int * p[10];
    // p[0] = arr[0];
    //  printf("%d\n", p[0][1]);

    // int arr[1][10] = {{1, 2, 3}};
    // int *p[10];       // p 是一个包含10个 int* 的数组
    // p[0] = arr[0];    // 让 p[0] 指向 arr[0]

    // printf("%d\n", p[0][1]);  // 输出 arr[0][1]（2）

    int a[5] = {1, 2, 3, 4, 5  };
    int *p = a;
    printf("%d %d \n", p[6], a[6]);
    return 0;
}