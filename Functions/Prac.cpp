#include <iostream>
using namespace std;

bool OddEven(int n){ //odd or even 
    if(n%2==0){
        return true; 
    }
    else{
        return false;
    }
}

int fact(int n){ //factorial
    int facto = 1;
    for (int i = 1; i <= n ; i++)
    {
        facto=facto*i;
    }

    return facto;
}

bool isPrime(int n){
    if(n==1){
        return false;
    }
    
    for (int i = 2; i <= n-1; i++)
    {
        if(n%i==0){
            return false;
        }
    }
     return true;
}

bool isPrime2(int n){
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



int main() {
    cout<<OddEven(5)<<endl;
    cout<<"Factorial is : "<<fact(4)<<endl;
    cout<<isPrime(5)<<endl;
    cout<<isPrime2(5)<<endl;
    return 0;
}