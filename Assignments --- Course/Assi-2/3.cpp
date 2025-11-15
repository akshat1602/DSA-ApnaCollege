#include <iostream>
using namespace std;

int main() {

    int P,R,T;
    cout<<"Enter Principal Amount: ";
    cin>>P;
    cout<<"Enter Rate of Interest: ";
    cin>>R;
    cout<<"Enter Time (in years): ";
    cin>>T;

    float SI = (P * R * T) / 100;
    cout<<"Simple Interest is: "<<SI;

    return 0;
}