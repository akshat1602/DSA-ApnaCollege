#include <iostream>
using namespace std;

bool isPrime(int n){ //Function to check prime
    if(n==1){
        return false;
    }

    for (int i = 2; i*i <= n; i++)
    {
        if(n%i==0){
            return false;
        }
    }
    return true;
    
}

void allPrimes(int n){ // Function to print all prime in range.
    for (int i = 2; i <= n; i++)
    {
        if(isPrime(i)){
            cout<<i<<" ";
        }
    }
    
}


int main() {
    int n;
    cout<<"Enter the number to check : "<<endl;
    cin>>n;

    allPrimes(n);

    
    return 0;
}