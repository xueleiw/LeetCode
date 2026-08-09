#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 设置随机数种子
    // srand(time(NULL));
    srand(time(NULL));

    // 生成 5 个随机数
    for (int i = 0; i < 5; i++) {
        int random_num = rand();
        printf("Random number %d: %d\n", i + 1, random_num);
    }

    return 0;
}

