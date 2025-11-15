#include <iostream>
using namespace std;
int main() {
    int a = 5, b = 9;

    int *ptr1 = &a, *ptr2 = &b;
    ptr2 = ptr1;

    cout<<ptr2<<"\n";
    cout<<ptr1<<"\n";
    cout<<&a<<"\n"; //sb same honge--> ptr2==ptr1==&a
    return 0;
}