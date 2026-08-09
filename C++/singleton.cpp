#include<iostream>
#include<mutex>
using namespace std;

class single {
    private:
        single() {}
        static single* singleInstance;
        static mutex mt;
        ~single() {
            cout << "byebye instance" << endl;
        }
        
    public:
        
        static single* get_instance() {
            lock_guard<mutex> lock(mt);
            if(singleInstance == nullptr) {
                singleInstance = new single();
            }
            return singleInstance;
        }

        void print() {
            cout << "hello instance" << endl;
        }

        void destroy() {
            delete singleInstance;
        }

};

// 静态成员变量在类外进行初始化
single* single::singleInstance = nullptr;
mutex single::mt;

int main() {
    single* instance = single::get_instance();
    instance->print();
    instance->destroy();
    // delete instance;

    return 0;
}