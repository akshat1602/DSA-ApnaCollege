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
};

int main() {
    Car c1("alto", "blue");
    
    Car c2(c1);
    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
    cout<<*c2.mileage<<endl; //deference
    
    *c2.mileage = 10; //shallow copy --> reference same
    
    cout<<*c1.mileage<<endl; //c1 ki bhi value changed matlb both c1 and c2 points to same memory location in heap.
    //ab deep copy ke karan c1 mein no change toh 12 hi aaega

    return 0;
}