#include <iostream>
#include <vector>
using namespace std;

void merge(int ans[], int st, int end, int mid);

void mergeSort(int ans[], int st, int end){
    if(st >= end) return;

    int mid = st + (end - st) / 2;
    mergeSort(ans, st, mid); // left part
    mergeSort(ans, mid + 1, end); // right part

    merge(ans, st, end, mid); // conquer
}

void merge(int ans[], int st, int end, int mid){
    vector<int> copy;
    int i = st, j = mid + 1; // iterators to store in copy vector

    // merge the two halves into copy
    while (i <= mid && j <= end) {
        if (ans[i] <= ans[j]) {
            copy.push_back(ans[i]);
            ++i;
        } else {
            copy.push_back(ans[j]);
            ++j;
        }
    }

    while (i <= mid) {
        copy.push_back(ans[i]);
        ++i;
    }
    while (j <= end) {
        copy.push_back(ans[j]);
        ++j;
    }

    for (int idx = st, x = 0; idx <= end; ++idx, ++x) {
        ans[idx] = copy[x];
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int ans[] = {6, 3, 7, 5, 2, 4};
    int n = sizeof(ans) / sizeof(int);

    mergeSort(ans, 0, n - 1);
    printArray(ans, n);
    return 0;
}