#include <iostream>
using namespace std;
int main() {
    int x, *ptr;
    x = 7;
    ptr = &x;
    cout<<*ptr; //value stored at x will be printed.
    return 0;
}