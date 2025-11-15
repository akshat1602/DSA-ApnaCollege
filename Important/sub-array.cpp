#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a[]={1,2,3,4,5};
    int n = 5;

    for (int start = 0; start < n; start++)
    {
        for ( int end = start; end < n ; end++)
        {
            for (int i = start; i <=end ; i++)
            {
                cout<<a[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
    


return 0;
}