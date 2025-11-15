#include <iostream>
#include <vector>
using namespace std;

class Animal{ //Base Class
    public:
    void eat(){
        cout<<"Eating..\n";
    }
    void breathe(){
        cout<<"breathing..\n";
    }
};

//Multiple Derived classes
class Bird : public Animal{
    public:
    void fly(){
        cout<<"Flying..\n";
    }
};

class Fish : public Animal{
    public:
    void swim(){
        cout<<"Swimming..\n";
    }
};

class Mammal : public Animal{
    public:
    void walk(){
        cout<<"Walking..\n";
    }
};

int main() {
    Bird b1;
    b1.fly();
    b1.eat();
    //same for others as well can be done..
    return 0;
}