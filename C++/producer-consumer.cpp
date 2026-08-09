#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
#include<queue>
#include<atomic>
#include<condition_variable>
using namespace std;

mutex mt;
int data;
queue<int> share;
condition_variable cv;
// atomic_bool stop{false};
bool stop = false;
const unsigned int BUFFER_SIZE = 10;

void producer(int id) {
    while(!stop) {
        this_thread::sleep_for(chrono::milliseconds(300)); // 模拟生产数据的时间

        unique_lock<mutex> lock(mt); // 
        cv.wait(lock, [](){return share.size() < BUFFER_SIZE || stop;});
        if(stop) {
            break;
        }
        share.push(data);
        cout << id << " produce " << data << endl;
        data++;
        // cv.notify_one();
        cv.notify_all();
        if(data >= 10) {
            // break;
            stop = true;
            break;
        }
    }
}

void consumer(int id) {
    while(!stop) {
        unique_lock<mutex> lock(mt); // 
        cv.wait(lock, [](){return share.size() > 0 || stop;});
        if(stop) {
            cout << id << " -> stop " << endl;
            break;
        }
        int x = share.front();
        share.pop();
        cout << id << " consume " << x << endl;

        // cv.notify_one();
        cv.notify_all();

        lock.unlock();// 解锁以允许生产者继续生产
        
        this_thread::sleep_for(chrono::milliseconds(150)); // 模拟消费过程


    }
}


int main() {
    thread p(producer, 1);
    thread p2(producer, 0);
    thread c(consumer, 2);
    thread c2(consumer, 3);
    c.join();
    c2.join();
    p.join();
    p2.join();

    return 0;
}