#include <iostream>
#include <deque>
#include <algorithm>  // 需要包含 <algorithm>

int main() {
    std::deque<int> dq = {1, 2, 3, 4, 5};

    // 旋转，使第3个元素（3）成为新的开头
    std::rotate(dq.begin(), dq.begin() + 1, dq.end());
    // std::rotate(dq.rbegin(), dq.rbegin() + 1, dq.rend());

    // 输出旋转后的 deque
    for (int num : dq) {
        std::cout << num << " ";  // 输出：3 4 5 1 2
    }

    return 0;
}


