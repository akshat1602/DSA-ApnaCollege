#include <iostream>
using namespace std;
int main() {
    int a;
    cout<<"enter a number: "<<endl;
    cin>>a;
    
    if(a>0){
        cout<<"number is positive"<<endl;
    }
    else if(a<0){
        cout<<"number is negative"<<endl;
    }
    else{
        cout<<"number is 0"<<endl;
    }
    return 0;
}