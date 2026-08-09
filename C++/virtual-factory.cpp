#include<iostream>
using namespace std;

// car
class Car {
    public:
        virtual ~Car() {}
        virtual void drive() = 0;
};

class BmwCar: public Car {
    public:
        void drive() override {
            cout << "bmw driving" << endl;
        }
};

class AudiCar: public Car {
    public:
        void drive() override {
            cout << "audi driving" << endl;
        }
};

// engine
class Engine {
    public:
        virtual ~Engine() {}
        virtual void start() = 0;
};

class BmwEngine: public Engine {
    public:
        void start() override {
            cout << "bmw starting" << endl;
        }
};

class AudiEngine: public Engine {
    public:
        void start() override {
            cout << "audi starting" << endl;
        }
};

// factory
class Factory {
    public:
        virtual ~Factory() {}
        virtual Car* create_car() = 0;
        virtual Engine* create_engine() = 0;
};

class BmwFactory: public Factory {
    public:
        Car* create_car() override {
            return new BmwCar();
        }

        Engine* create_engine() override {
            return new BmwEngine();
        }
};

class AudiFactory: public Factory {
    public:
        Car* create_car() override {
            return new AudiCar();
        }

        Engine* create_engine() override {
            return new AudiEngine();
        }
};


int main() {
    Factory* f1 = new BmwFactory();
    Factory* f2 = new AudiFactory();

    Car* c1 = f1->create_car();
    Engine* e1 = f2->create_engine();

    c1->drive();
    e1->start();

    delete f1;
    delete f2;
    delete c1;
    delete e1;
    

    return 0;
}