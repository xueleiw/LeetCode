#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
#include<queue>
#include<atomic>
#include<condition_variable>
using namespace std;

class Car {
    public:
        virtual void drive() = 0;
        virtual ~Car() {} 
};

class Audi: public Car {
    public:
        void drive() override {
            cout << "audi start" << endl;
        }
};

class Bmw: public Car {
    public:
        void drive() override {
            cout << "bmw start" << endl;
        }
};

// factory
class Factory {
    public:
        virtual Car* create() = 0;
        virtual ~Factory() {
            cout << "222" << endl;
        }
};

class BmwFactory: public Factory {
    public: 
        Car* create() override {
            return new Bmw();
        }
};

class AudiFactory: public Factory {
    public: 
        Car* create() override {
            return new Audi();
        }
        ~AudiFactory() override {
            cout << "111" << endl;
        }
};



int main() {
    Factory* f1 = new BmwFactory();
    Factory* f2 = new AudiFactory();

    Car* c1 = f1->create();
    Car* c2 = f2->create();

    c1->drive();
    c2->drive();

    delete f1;
    delete f2;
    delete c1;
    delete c2;

    // cout << "子类指针" << endl;
    // AudiFactory* f3 = new AudiFactory();
    // delete f3;


    return 0;
}
