//REFERENCE VARIABLES EG.--> They should always be initialized.
#include <iostream>
using namespace std;

//Same memory location but alternate name(alias).
void changeB(int &param){ //Pass by reference using ref variable.
    param = 20;
    cout<<param<<"\n";
}

int main() {
    int a = 10;
    changeB(a);
    cout<<a<<"\n";

    int &b = a; //Both pointing to same location
    b = 50;
    cout<<b<<"\n";
    cout<<a<<"\n";
    return 0;
}