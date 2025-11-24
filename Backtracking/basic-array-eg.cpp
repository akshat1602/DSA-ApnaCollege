#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void changeArr(int arr[], int n, int idx){
    if(idx == n) {//base case hit : when i = 5.
      printArray(arr, n);
      return; 
    }
    arr[idx] = idx+1;
    changeArr(arr, n, idx+1);
    arr[idx] -= 2; //backtrack
}

int main() {
    int arr[5] = {0};
    int n = 5;

    changeArr(arr, n, 0);
    printArray(arr, n);
    return 0;
}