#include <iostream>
using namespace std;
int main() {
    int i,j;
    int n = 5;

    for ( i = 1; i <= n; i++) //outer loop : number of rows
    {
        //spaces
        for (j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        //stars
        for (j = i; j >= 1; j--)//important
        {
            cout<<j;
        }
        
        for ( j = 2; j <= i ; j++) //important**
        {
            cout<<j;
        }
      
        
        cout<<endl;
    }//upper triangle ends here
    return 0;
}