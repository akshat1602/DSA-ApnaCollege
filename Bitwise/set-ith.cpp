#include <iostream>
#include <vector>
using namespace std;

int setIthBit(int num, int i){
    
    int bitMask = 1<<i;
    return (num|bitMask);
}

int main() {
    int num, i;
    cout<<"enter the number and its ith position : "<<endl;
    cin>>num>>i;
    
    cout<<setIthBit(num, i)<<endl;
    return 0;
}