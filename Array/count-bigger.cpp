#include <iostream>
using namespace std;

void countBigger(int a[], int n, int target){
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if(a[i] > target){
            cnt++;
        }
    }

    cout<<"Count of larger elements than target : "<<cnt<<endl;
    
}

int main() {
    int a[] = {1,4,6,2,55,3,7};
    int n = sizeof(a)/sizeof(int);
    int target;
    cout<<"Enter the Target : \n";
    cin>>target;
    countBigger(a,n,target);

    return 0;
}