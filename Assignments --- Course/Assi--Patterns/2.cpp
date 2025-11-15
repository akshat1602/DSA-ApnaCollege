#include <iostream>
using namespace std;
int main() {
    int i,j;
    int n = 5;
    
    //1st half
    for ( i = 1; i <= n; i++)
    {
        for ( j = 1; j <= (n-i); j++)
        {
            cout<<" ";
        }
        for ( j = 1; j <= i; j++)
        {
            cout<<"*";
        }
        for (int j = n-i; j > 0; j--)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}