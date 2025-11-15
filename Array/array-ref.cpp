#include <iostream>
using namespace std;
int main() {
    int a = 5;
    int *ptr = &a;
    cout<<ptr<<endl; //0x...

    int arr[]= {1,23,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    
    //Accessing indices using pointers
    cout<<*arr<<endl; //arr[0]
    cout<<*(arr+1)<<endl; //arr[1]
    cout<<*(arr+2)<<endl; //arr[2]

    return 0;
}