#include <iostream>
#include <vector>
using namespace std;

class Parent {
    public:
    Parent(){
        cout<<"Parent Constructor called...."<<endl;
    }
    ~Parent(){
        cout<<"Parent Destructor called...."<<endl;
    }

};

class Child : public Parent {
    public:
    Child(){
        cout<<"Child Constructor called...."<<endl;
    }
    ~Child(){
        cout<<"Child Destructor called...."<<endl;
    }

};

int main() {
    cout<<"Order Of printing :\n";
    Child c1;
    return 0;
}

/*---------Imp Points---------
Order of printing for constructor:
1. Parent ka
2. Child ka

Order of printing for destructor:
1. Child ka
2. Parent ka
*/