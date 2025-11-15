//HOLLOW RECTANGLE
#include <iostream>
using namespace std;
int main() {
    int i,j;
    int n=4;

    for ( i = 1; i <= n; i++)
    {
        cout<<"*";//1st 

        for ( j = 1; j <=n-1 ; j++) //for hollow or star 
        {
            if(i==1 || i==n){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        
        cout<<"*";//last
        cout<<endl;
    }    
    return 0;
}