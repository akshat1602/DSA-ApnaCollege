#include <iostream>
#include <vector>
using namespace std;

class Animal{
    public:
    string color;

    void eat(){
        cout<<"Eating..\n";
    }
    void breathe(){
        cout<<"breathing..\n";
    }

};

class Fish : public Animal{ //inheritance --> always write with access modifiers.
    public:
    int fins;

    void swim(){
        cout<<"Swimming..\n";
    }
};


int main() {
    Fish f1;
    f1.fins = 4;
    cout<<f1.fins<<endl;
    f1.swim();

    f1.eat(); //inherited
    f1.breathe();//inherited 

    return 0;
}