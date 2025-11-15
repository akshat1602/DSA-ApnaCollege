//With Extra Space -- Not Optimized

#include <iostream>
using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {1, 5, 8, 9, 11};
    int size = sizeof(a) / sizeof(int);

    int copyArr[size]; // Copy array to store elements in reverse

    for (int i = 0; i < size; i++)
    {
        int j = size - i - 1; // important step for reverse loop
        copyArr[i] = a[j];    // copy array mein start se fill honge and ori. array se shuru se utha kar laenge elements.
    }

    for (int i = 0; i < size; i++)
    {
        a[i] = copyArr[i];
    }

    printArray(a, size);

    return 0;
}