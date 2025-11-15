//DIAMOND PROBLEM ---M.Imp
#include <iostream>
using namespace std;
int main() {
    int i,j;
    int n = 4;

    for ( i = 1; i <= n; i++) //outer loop : number of rows
    {
        //spaces
        for (j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        //stars
        for (j = 1; j <= 2*i-1; j++)//important
        {
            cout<<"*";
        }
        cout<<endl;
    }//upper triangle ends here

    //Lower Triangle begins: reverse row logic
    for ( i = 4; i >= 1; i--)
    {
        //spaces
        for ( j = 1; j <= n-i ; j++)
        {
            cout<<" ";
        }
         //stars
        for ( j = 1; j <= 2*i-1 ; j++)
        {
            cout<<"*";
        }
        cout<<endl; 
    }//Lower triangle ends here
        
    return 0;
}