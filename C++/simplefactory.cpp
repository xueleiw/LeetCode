#include<iostream>
#include<mutex>
using namespace std;

class sender {
    public:
        virtual ~sender() {} // 析构必须是虚函数
        virtual void send() = 0; // 抽象类
};

class message1: public sender {
    public:
        // ~message1() {
        //     
        // }
        void send() override {
            cout << "m1" << endl;
        }
};

class message2: public sender {
    public: 
        void send() override {
            cout << "m2" << endl;
        }
};

// // 简单工厂模式
// class factory {
//     public:
//         static sender* producer(const string& s) {
//             if(s == "m1") {
//                 return new message1();
//             } else if(s == "m2") {
//                 return new message2;
//             }
//         }
// };


// 工厂模式--就是有多个工厂生产产品
class factory {
    public:
        static sender* producer1() {
            return new message1();
        }

        static sender* producer2() {
            return new message2();
        }
};


int main() {
    // 简单工厂
    // sender* sd = factory::producer("m1");
    // sd->send();
    // sd = factory::producer("m2");
    // sd->send();

    // 工厂模式
    sender* m1 = factory::producer1();
    m1->send();
    sender* m2 = factory::producer2();
    m2->send();

    return 0;
}
