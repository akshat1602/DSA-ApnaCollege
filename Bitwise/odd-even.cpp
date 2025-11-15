#include <iostream>
#include <vector>
using namespace std;

void oddEven(int num){
    if(!(num & 1)) cout<<"Even number"<<endl; //true(1) aaya toh false(0) kardega meaning even
    else cout<<"Odd number"<<endl;
}

int main() {
    int num;
    cout<<"enter the number : "<<endl;
    cin>>num;

    oddEven(num);
    
    return 0;
}