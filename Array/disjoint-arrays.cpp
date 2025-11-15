#include <iostream>
using namespace std;

bool isDisjoint(int a[], int b[], int n, int m){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(a[i] == b[j]){
                return false;
                break;
            }
            else{
                continue;
            }
        }
        
    }
    return true;
    
}

int main() {
    int a[] = {1,2,4};
    int b[] = {4,5,6};
    int n = sizeof(a)/sizeof(int);
    int m = sizeof(b)/sizeof(int);

    cout<<isDisjoint(a,b,n,m)<<endl;
    
    return 0;
}