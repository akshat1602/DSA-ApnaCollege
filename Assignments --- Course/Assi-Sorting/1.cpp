#include <iostream>
using namespace std;

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " , ";
    }
    cout << endl;
}

void bubbleSort(int *arr, int size){
    bool isSwap = false;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1 ; j++)
        {
            if(arr[j] < arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            break;
        }
    }
     printArray(arr, size);
}

void selectionSort(int *arr, int size){
    for (int i = 0; i < size - 1; i++)
    {
        int minIdx = i;
        for (int j = i+1; j < size; j++)
        {
            if(arr[j] > arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[minIdx] , arr[i]);
    }
   printArray(arr, size);    
}

int main() {
    int arr[] = {3,6,2,1,8,7,4,5,3,1};
    int size = sizeof(arr)/sizeof(int);

    selectionSort(arr, size);


    return 0;
}