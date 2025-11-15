//Overrinding mein inheriatnce hoti.

#include <iostream>
using namespace std;

class Parent{
    public:
    void show(){
        cout<<"Parent...\n";
    }
};

class Child : public Parent{
    public:
    void show(){
        cout<<"Child...\n";
    }
};

int main() {
    Child c1;
    c1.show(); //run time pr decide hoga to run child's show func.
    
    return 0;
}