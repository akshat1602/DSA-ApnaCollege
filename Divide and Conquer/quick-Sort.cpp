#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int st, int end){
    int i = st-1;
    int pivot = arr[end];
    
    for (int j = st; j < end ; j++)
    {
        if(arr[j] <= pivot){// for elements smaller than pivot.
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]); //pivot ke liye

    return i;
}

void quickSort(int arr[], int st, int end){
    if(st >= end) return;
    int pivotIdx = partition(arr, st, end); //pivot ka index milega yahan : jo i hai.

    quickSort(arr, st, pivotIdx-1); //for left partition
    quickSort(arr, pivotIdx+1, end); //for right partition
}



int main() {
    int arr[] = {6,3,7,5,2,4};
    int n = sizeof(arr)/sizeof(int);

    quickSort(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}