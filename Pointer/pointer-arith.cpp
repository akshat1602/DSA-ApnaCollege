#include <iostream>
using namespace std;

int main() {
    //int a = 65;
    int a[] = {1,2,5,78,6};
    int *ptr1 = a;
    int *ptr2 = ptr1 + 3; //12 bytes ka difference --> 3 integers can be stored.

    cout<<*ptr2<<endl; //78
    cout<<*ptr1<<endl; //1

    cout<<ptr2-ptr1<<endl; //ans: 3 integers
    return 0;
}
