//PALLINDROME
#include <iostream>
using namespace std;

bool isPallin(int n){
    int rev = n;
    int dig;
    int new_num = 0;

    while(n>0){
        dig = n%10;
        new_num = new_num*10 + dig;
        n/=10;
    }

    if(new_num==rev){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    int n;
    cout<<"Enter the number to check : "<<endl;
    cin>>n;
    cout<<isPallin(n)<<endl;;
    
    return 0;
}