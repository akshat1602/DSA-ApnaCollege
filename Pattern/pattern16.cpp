#include <iostream>
using namespace std;
int main() {
    int i,j;
    int n;
    cout<<"enter the linit : ";
    cin>>n;
    char ch = 'A';
    
    for ( i = 1; i <= n ; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout<<ch;
            ch+=1;
        }
        cout<<endl;
    }
    
    return 0;
}