#include <iostream>
#include <thread>
#include <chrono>

void childProcess() {
    std::cout << "子线程开始 (线程ID: " << std::this_thread::get_id() << ")\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "子线程结束\n";
}

int main() {
    std::cout << "主线程开始 (线程ID: " << std::this_thread::get_id() << ")\n";

    // 创建并启动子线程
    std::thread t(childProcess);

    // 主线程继续执行其他工作
    std::cout << "主线程正在做其他工作...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 等待子线程结束
    t.join();
    std::cout << "主线程结束\n";

    return 0;
}