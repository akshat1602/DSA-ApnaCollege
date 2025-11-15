#include <iostream>
#include <vector>
using namespace std;

class Car{
public:
    string name;
    string color;

    Car(string name, string color){
        this->name = name;
        this->color = color;
    }

    Car(Car &original){ //Custom Copy constructor.
        cout<<"copying original to new..."<<endl;
        name = original.name;
        color = original.color;
    }
};

int main() {
    Car c1("alto", "blue");

    Car c2(c1); //automatically a new copy constructor is created by compiler/or when custom is made then that is called.
    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
    return 0;
}