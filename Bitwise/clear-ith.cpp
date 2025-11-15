#include <iostream>
#include <vector>
using namespace std;

int clearIthBit(int num, int i){
    int bitMask = ~(1<<i);

    return num&bitMask;
}

int main() {
    int num, i;
    cout<<"enter the number and its ith position : "<<endl;
    cin>>num>>i;
    
    cout<<clearIthBit(num, i)<<endl;
    
    return 0;
}