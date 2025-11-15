#include <iostream>
using namespace std;
int main() {
    int n;
    int odd_dig_sum = 0, dig;
    cout<<"enter the number: "<<endl;
    cin>>n;

    while(n>0){
        dig=n%10;
        if(dig%2!=0){
            odd_dig_sum+=dig;
        }
        n/=10;
    }

    cout<<"sum of odd digits: "<<odd_dig_sum<<endl;


    return 0;
}