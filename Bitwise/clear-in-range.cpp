//Imp....

#include <iostream>
#include <vector>
using namespace std;

int clearInRange(int num, int i, int j){
    int leftBitMask = (~0<<(j+1));
    int rightBitMask = ((1<<i)-1);

    int completeMask = leftBitMask|rightBitMask; //to not change bits other than the ones in range.

    return num&completeMask;
}

int main() {
    int num,i,j;
    cout<<"enter the number and range : "<<endl;\
    cin>>num>>i>>j;

    cout<<clearInRange(num,i,j)<<endl;
    
    return 0;
}