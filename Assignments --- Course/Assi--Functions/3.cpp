#include <iostream>
using namespace std;

double calc(double a, double b){
    double val1 = a*a;
    double val2 = b*b;
    double val3 = 2*a*b;
    double formula = val1+val2+val3;

    return formula;
}

int main() {
    int a,b;
    cout<<"enter the value of a & b : "<<endl;
    cin>>a>>b;

    cout<<calc(a,b)<<endl;
    
    return 0;
}