#include <iostream>
using namespace std;

int lar(int a, int b, int c){
    if(a>b&a>c){
        return a;
    }
    else if(b>c){
        return b;
    }
    else{
        return c;
    }
}

int main() {
    int a,b,c;
    cout<<"enter the numbers : "<<endl;
    cin>>a>>b>>c;

    cout<<lar(a,b,c)<<" is the largest among the 3."<<endl;
    
    return 0;
}