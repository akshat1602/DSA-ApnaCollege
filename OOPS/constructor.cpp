#include <iostream>
#include <string>
using namespace std;

class Car{
    string name;
    string color;

public:
    Car(){
        cout<<"Constructor without params..\n";
    }

    Car(string name, string color){
        cout<<"Constructor with params..\n";
        this->name = name; //this refers to object
        this->color = color;
    }
    
    void start(){
        cout<<"Car started..\n";
    }

    void stop(){
        cout<<"Car stopped..\n";
    }

    //Getter
    string getName(){
        return name;
    }

};

int main() {
    Car c0; //non-params
    Car c1("Audi", "red");//params
    Car c2("mcLaren", "Blue");

    cout<<"Car Name : "<<c1.getName()<<endl;
    cout<<"Car Name : "<<c2.getName()<<endl;

    return 0;
}