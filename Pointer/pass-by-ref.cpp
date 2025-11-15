#include <iostream>
using namespace std;

void changeA(int a){ //Pass by value
    a = 20;
    cout<<a<<"\n";
}

void changeB(int *ptr){ //By pointer defrencing --- pass by reference
    *ptr = 20;
    cout<<*ptr<<"\n";
}

int main() {

    int a = 10;
    cout<<a<<"\n";
    changeA(a);
    changeB(&a);
    cout<<a<<"\n";
    
    return 0;
}