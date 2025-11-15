#include <iostream>
#include <vector>
using namespace std;

void getIthBit(int num, int i){

    int bitMask = 1<<i;

    if(!(num&bitMask)) cout<<"bit is 0"<<endl;
    else cout<<"bit is 1"<<endl;
}

int main() {
    int num, i;
    cout<<"enter the number and its ith position : "<<endl;
    cin>>num>>i;
    
    getIthBit(num, i);

    return 0;
}