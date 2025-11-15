#include <iostream>
#include <vector>
using namespace std;

class Car{
public:
    string name;
    string color;
    int *mileage;

    Car(string name, string color){
        this->name = name;
        this->color = color;
        mileage = new int; //Dynamic allocation
        *mileage = 12;
    }

    Car(Car &original){ //Custom Copy constructor.
        cout<<"copying original to new..."<<endl;
        name = original.name;
        color = original.color;
        mileage = new int; //new memory for deep copy
        *mileage = *original.mileage;
    }

    ~Car() { //Destructor
        cout<<"deleting object..."<<endl;
        if(mileage != NULL){
            delete mileage; //memory location deleted.
            mileage = NULL; //meaning no valid memory address is stored
        }
    }
};

int main() {
    Car c1("alto", "blue");
    cout<<c1.name<<endl;
    cout<<c1.color<<endl;
    cout<<*c1.mileage<<endl; 
    
    return 0;
}