#include <iostream>
#include <vector>
using namespace std;

int updateBit(int num, int i, int val){
    int bitMask = ~(1<<i); //clear bit
    
    num = num&bitMask;

    return num|(val<<i);

}

int main() {
    int num, i,val;
    cout<<"enter the number and its ith position and value to be changed into : "<<endl;
    cin>>num>>i>>val;
    
    cout<<updateBit(num, i, val)<<endl;
    return 0;
}