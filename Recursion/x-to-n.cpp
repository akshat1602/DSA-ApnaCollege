#include <iostream>
#include <vector>
using namespace std;

int pow(int x, int n){

    if(n == 0){ //any number to power 0 is 1.
        return 1;
    }
    
    int halfPow = pow(x,n/2); 
    int halfPowSquare = halfPow * halfPow;
    
    if(n%2 != 0){
        //odd
        return x * halfPowSquare; 
    }
    return halfPowSquare;
}

int main() {
    int x, n;
    cout<<"Enter the base and power : "<<endl;
    cin>>x>>n;
    cout<<"Answer : "<<pow(x,n)<<endl;
    
    return 0;
}