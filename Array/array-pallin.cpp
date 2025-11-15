#include <iostream>
using namespace std;

bool checkPallin(int a[], int n){
    int st = 0, end = n-1; //2 pointer approach.

    while(st<=end){
        if(a[st] != a[end]){
            return false;
            break;
        }
        else{
            st++;
            end--;
        }
    }
    return true;
}

int main() {
    int a[] = {1,2,2,1};
    int n = sizeof(a)/sizeof(int);

    cout<<checkPallin(a,n)<<endl;
    return 0;
}