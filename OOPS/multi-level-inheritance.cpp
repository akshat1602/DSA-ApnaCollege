#include <iostream>
#include <string>
using namespace std;

class Animal{
    public:
    void eat(){
        cout<<"Eating..\n";
    }
    void breathe(){
        cout<<"breathing..\n";
    }
};

class Mammal: public Animal{
    public:
    string bloodtype;

    Mammal() { //constructor
        bloodtype = "warm";
    }
};

class Dog: public Mammal{
    public:
    
    void tailWag() {
        cout<<"A dog wags its tail\n"<<endl;
    }
};

int main() {
    Dog d1;

    d1.eat();
    d1.breathe();
    d1.tailWag();

    
    return 0;
}