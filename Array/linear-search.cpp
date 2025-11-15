#include <iostream>
using namespace std;

int main()
{
    int a[7];
    int size = sizeof(a) / sizeof(int);
    int key; // number to be searched.

    cout << "enter elements of array : " << endl;
    for (int i = 0; i < size; i++) // Input loop for array elements
    {
        cin >> a[i];
    }

    cout << "enter the number to be searched : " << endl;
    cin >> key;

    for (int i = 0; i < size; i++) // Comparison loop
    {
        if (a[i] == key)
        {
            cout << "number found at : " << i << endl;
        }
    }

    cout << "Not Found!!" << endl;

    return 0;
}