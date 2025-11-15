#include <iostream>
#include <vector>
using namespace std;

int clearLastIth(int num, int i){
    int bitMask = ~0<<i;
    num = num & bitMask;

    return num;
}

int main() {
    int num, i;
    cout<<"enter the number and its ith position : "<<endl;
    cin>>num>>i;
    
    cout<<clearLastIth(num, i)<<endl;
    
    return 0;
}