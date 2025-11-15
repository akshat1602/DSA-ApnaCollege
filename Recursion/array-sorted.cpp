//IMPORTANT

#include <iostream>
using namespace std;

bool isSorted(int a[], int n, int i){
    if(i == n-1) return true; //ending condition.

    if(a[i] > a[i+1]) return false;

    else{
        return isSorted(a, n, i+1); //recursion
    }
}

int main() {
    int a1[] = {1,2,4,5,6};
    int a2[] = {1,4,2,5,6};
    int n1 = sizeof(a1)/sizeof(int); 
    int n2 = sizeof(a2)/sizeof(int);

    cout<<isSorted(a1, n1, 0)<<endl;
    cout<<isSorted(a2, n2, 0)<<endl;
    
    return 0;
}