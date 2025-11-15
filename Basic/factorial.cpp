#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i, fac = 1,n;
    cout<<"enter the number "<<endl;
    cin>>n;
    for (i = 1; i <= n; i++)
    {
        fac*=i;
    }
    cout<<"factorial : "<<fac<<endl;

    return 0;
}