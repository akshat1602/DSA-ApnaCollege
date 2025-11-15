#include <iostream>
using namespace std;

int main(){
    char symbol;
    int a,b;
    cout<<"enter the symbol to perform calculation : "<<endl;
    cin>>symbol;

    cout<<"enter the numbers : "<<endl;
    cin>>a>>b;

    switch (symbol)
    {
    case '+':
        cout<<"addition : "<<(a+b)<<endl;
        break;
    case '-':
        cout<<"subtraction : "<<(a-b)<<endl;
        break;
    case '*':
        cout<<"multiplication : "<<(a*b)<<endl;
        break;
    case '/':
        cout<<"divison : "<<(a/b)<<endl;
        break;
    
    default:
        cout<<"Invalid value: "<<endl;
        break;
    }
}