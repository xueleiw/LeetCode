---
name: leetcode-error-summary
description: Systematically review and summarize LeetCode problems to identify bugs, logic errors, edge cases, and performance issues.
---

# LeetCode 错题总结

当遇到LeetCode代码有问题时，使用这个skill来系统性地审查和总结关键问题点。

## 何时使用

- 代码编译/运行出错
- 某些测试用例失败
- 算法逻辑不完整
- 需要优化性能（时间/空间复杂度）
- 找到了bug并想记录下来

## 检查清单

### 1. 运行时错误
- [ ] 空指针访问（NULL pointer dereference）？
  - 函数可能返回 NULL，但调用方没有检查
- [ ] 数组越界（out of bounds）？
  - 循环条件是否正确？
  - 边界索引是否考虑周全？
- [ ] 内存泄漏（memory leak）？
  - malloc 的内存是否都被 free？
  - 提前返回时有无遗漏？

### 2. 逻辑错误
- [ ] 初始化错误？
  - 变量/数组初值是否正确？
- [ ] 循环条件错误？
  - i < numsSize 还是 i <= numsSize？
  - 起点、终点、步长都对吗？
- [ ] 边界情况处理？
  - 空数组、单元素、特殊值（0, 负数）
  - 无解的情况如何处理？

### 3. 时间复杂度
- [ ] 是否达到预期的时间复杂度？
  - 题目要求是什么？通常 O(n)、O(nlogn) 等
  - 当前是否为 O(n²) 或更差？
  - 有无更优解法（如哈希表替代嵌套循环）？

### 4. 返回值/输出
- [ ] 返回类型是否正确？
- [ ] 返回值的格式是否符合要求？
- [ ] 返回NULL/0时调用方能否安全处理？

## 总结模板

```
## 问题
[简述遇到的问题：编译错误/运行时崩溃/错误答案]

## 根本原因
[分析问题的根源]

## 错误示例
[贴出有问题的代码片段]

## 修复方式
[说明如何修复]

## 正确示例
[贴出修复后的代码片段]

## 要点
[总结这个错题教会了什么]

## 时间/空间复杂度
- 时间: O(?)
- 空间: O(?)
```

## 常见问题示例

### 示例1：空指针未检查
**问题**: 函数返回NULL时，调用方直接访问导致崩溃

**错误**:
```c
int *arr = twoSum(nums, size, target, &returnSize);
printf("[%d, %d]", arr[0], arr[1]);  // arr 可能是 NULL!
free(arr);
```

**正确**:
```c
int *arr = twoSum(nums, size, target, &returnSize);
if (arr == NULL) {
    printf("No solution\n");
    return 1;
}
printf("[%d, %d]\n", arr[0], arr[1]);
free(arr);
```

### 示例2：循环条件错误
**错误**: `for(int i = 0; i <= numsSize; i++)` — 会越界
**正确**: `for(int i = 0; i < numsSize; i++)`

### 示例3：性能不达标
**错误**: 两层嵌套循环 O(n²) 在大数据上TLE
**优化**: 用哈希表记录已见的数字，变成 O(n)

## Learnings

- 总是处理函数可能返回的NULL/0/空值
- 仔细检查循环边界条件（`<` 还是 `<=`）
- malloc的内存必须对应free，包括早期返回的路径
- 先确保逻辑正确，再优化性能；从O(n²)优化到O(n)通常需要数据结构支持（哈希表、栈等）
