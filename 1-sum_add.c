/**
 * 2024-12-12
 * 暴力求解，函数的最后要返回空
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i = 0; i < numsSize; i++) {
        for(int j = i + 1; j < numsSize; j++ ) {
            if (nums[i] + nums[j] == target) {
                int *arr = (int*)malloc(2 * sizeof(int));
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;
                return arr;
            }
        }
    }
    // 如果不满足返回空
    *returnSize = 0;
    return NULL;
}

int main() {
    int sum[4] = {2, 7 , 11, 15};
    int return_size;
    int *arr = twoSum(sum, 4, 9, &return_size);
    printf("[%d, %d]", arr[0], arr[1]);
    free(arr);

    return 0;
}
 