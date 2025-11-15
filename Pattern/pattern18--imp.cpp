#include <iostream>
using namespace std;
int main() {
    int i,j;
    int n = 4;

    for ( i = 1; i <= n; i++)
    {
        for(j=1;j<=n-i;j++){//1st give space:so pehle space wala loop
            cout<<" ";
        }
        for(int k=1; k<=i; k++){//2nd give stars: toh baad mein stars wala loop
            cout<<"*";
        }
        cout<<endl;
    }
    
    return 0;
}