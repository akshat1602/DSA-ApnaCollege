#include <iostream>
#include <climits>
using namespace std;

void secondLar(int a[], int n){
    int max = INT_MIN;
    int secMax = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if(a[i] > max) max = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i] > secMax && a[i] != max) secMax = a[i];
    }
    cout<<"Second Largest Number : "<<secMax<<endl;
}

int main() {
    int a[] = {1,5,10,36,19};
    int n = sizeof(a)/sizeof(int);

    secondLar(a,n);
    
    return 0;
}