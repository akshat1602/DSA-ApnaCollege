#include <iostream>
#include <vector>
using namespace std;

int search(int arr[], int st, int end, int tar){
    if(st > end) return -1; //BASE CASE

    int mid = st + (end - st)/2;

    if(arr[mid] == tar){
        return mid;
    }

    if(arr[st] <= arr[mid]){ //L1(Left side sorted matlb)
       if(arr[st] <= tar && tar <= arr[mid]){ //left side
        return search(arr, st, mid-1, tar);
       } 
       else{ //right side
        return search(arr, mid+1, end, tar);
       }
    }

    else{ //L2(right side sorted matlb)
        if(arr[mid] <= tar && tar <= arr[end]){//right side
            return search(arr, mid+1, end, tar);
        }
        else{//left side
            return search(arr, st, mid-1, tar);
        }
    }
}

int main() {
    int arr[] = {4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(int);
    int tar;
    cout<<"Enter the target : "<<endl;
    cin>>tar;

    cout<<"index : "<<search(arr, 0, n-1, tar)<<endl;
    return 0;
}