#include <iostream>
using namespace std;

void sumEle(int arr[], int n){
    int arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        arrSum+=arr[i];
    }
    cout<<"Sum is : "<<arrSum<<endl;
}
void proEle(int arr[], int n){
    int arrPro = 1; //multiplicative identity
    for (int i = 0; i < n; i++)
    {
        arrPro*=arr[i];
    }
    cout<<"Product is : "<<arrPro<<endl;
}

int main() {
    int a[] = {2,3,4,5,6,8};
    int a1[] = {1,2,3,4};
    int n = sizeof(a)/sizeof(int);
    int m = sizeof(a1)/sizeof(int);

    sumEle(a, n);
    proEle(a, m);
    
    return 0;
}