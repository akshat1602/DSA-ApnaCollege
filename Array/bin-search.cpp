#include <iostream>
using namespace std;

int binSearch(int *arr, int size, int key)
{
    int st = 0, end = size-1;

    while(st<=end){
        int mid = st+(end-st)/2;
        if(arr[mid] == key){
            return mid; //key found
        }
        else if(arr[mid] < key){
            st = mid+1; //2nd half mein key present
        }
        else if(arr[mid] > key){
            end = mid-1; //1st half mein key present
        }
    }

    return -1;
}

int main() {
    int a[] = {2,4,6,7,9,11,56,87,96};
    int size = sizeof(a)/sizeof(int);
    int key;
    cout<<"Enter the element to be searched : "<<endl;
    cin>>key;

    cout<<"At index : "<<binSearch(a, size, key)<<endl;

    return 0;
}