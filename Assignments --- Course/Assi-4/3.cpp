#include <iostream>
using namespace std;
int main() {
    int n;
    int dig ,copy, arm_sum=0;
    cout<<"enter a number : "<<endl;
    cin>>n;
    copy = n;

    while(n>0){
        dig = n%10;
        arm_sum+=(dig*dig*dig);
        n/=10;
    }

    if(arm_sum==copy){
        cout<<"number is armstrong"<<endl;
    }
    else{
        cout<<"number is not armstrong"<<endl;
    }

    return 0;
}