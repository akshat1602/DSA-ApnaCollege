//No extra space -- 2 Pointer approach
//Primarily for big data structures but you can use multiple variables.
//O(1)--SC, O(n)--TC

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

int main() {
    int a[] = {1, 5, 8, 9, 11};
    int size = sizeof(a) / sizeof(int);
    int st = 0, end = size-1;
    int temp = 0;

    while(st<end){

        //SWAP -- Important
        temp = a[st];
        a[st] = a[end];
        a[end] = temp;

        //swap(a[st], a[end]); -->using this inbuilt function as well.

        st++;
        end--;
    }

    printArray(a, size);
    
    return 0;
}