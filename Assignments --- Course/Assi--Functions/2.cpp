//SUM OF DIGITS
#include <iostream>
using namespace std;

int dig_sum(int n){
    int dig;
    int sum = 0;

    while(n>0){
        dig = n%10;
        sum+=dig;
        n/=10;
    }
    return sum;
}

int main() {

    int n;
    cout<<"enter the number : "<<endl;
    cin>>n;
    
    cout<<dig_sum(n)<<endl;
    
    return 0;
}