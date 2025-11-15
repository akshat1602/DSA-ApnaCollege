#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int a;
    int dig, arm= 0;
    cout<<"enter a 3 digit number: "<<endl;
    cin>>a;
    int b = a;

    while(a>0){
        dig = a%10;
        arm = arm + (dig*dig*dig);
        a/=10; 
    }
    
    if (b==arm)
    {
        cout<<"number is armstrong"<<endl;
    }
    else{
        cout<<"number is not armstrong"<<endl;
    }
    
    return 0;
}