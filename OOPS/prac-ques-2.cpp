#include <iostream>
using namespace std;

class Base{
    public:
    virtual void show(){ //virtual function
        cout << "Base" << endl;
    }
};

class Derived : public Base{
    public:
    void show() override{ //Function Overriding
        cout << "Derived" << endl;
    }
};

int main() {
    //object derived ka hai toh function bhi uss hi class ka run karega, does'nt depend upon pointer.
    Base *b = new Derived(); //Run time poly : run time binding
    b->show();
    delete b; //deleting the allocated memory by b

    return 0;
}