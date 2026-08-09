#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    std::vector<std::string> strings;
    std::string str;

    // 方法 1：使用 while(cin >> str) 读取，直到输入结束（Ctrl+D / Ctrl+Z）
    while (std::getline(std::cin, str)) {
        if (str.empty()) break; // 如果输入空行则停止
        std::cout << str << std::endl;
    }

    // 输出所有字符串
    // for (const auto& s : strings) {
    //     std::cout << s << std::endl;
    // }

    return 0;
}