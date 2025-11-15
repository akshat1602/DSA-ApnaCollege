//Important Points--->1. Array name can be converted to pointer.
//2. Array is passed by reference.
//3. both the syntaxes down for func are same.

#include <iostream>
using namespace std;

void func(int a[])
{ // array is passed by reference
    a[0] = 1020;
}

void func2(int *ptr)
{ // same o/p as above func., as a pointer.
    ptr[0] = 1020;
}

int main()
{
    int a = 5;
    int *ptr = &a;
    cout << ptr << endl; // 0x...

    int arr[] = {1, 23, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    func2(arr); //Passing array name is equivalent to passing pointer.
    cout<<arr[0]<<endl;

    return 0;
}