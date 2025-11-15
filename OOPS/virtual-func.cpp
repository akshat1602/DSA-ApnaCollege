#include <iostream>
#include <vector>
using namespace std;

class Parent{
    public:
    void show(){
        cout<<"parent class show..\n";
    }
    
    virtual void hello(){
        cout<<"Parent hello\n";
    }
};

class Child: public Parent{
    public:
    void hello(){ //redefined here.
        cout<<"Child hello\n";
    }
};

int main() {
    Child c1;
    Parent *ptr; //it will point to objects of parent class.
    
    ptr = &c1; //Run Time Binding : Due to inheritance.
    ptr -> hello();
    return 0;
}