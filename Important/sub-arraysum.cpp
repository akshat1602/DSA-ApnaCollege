#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a[]={3,-4,5,4,-1,7,-8};
    int n = sizeof(a);
    
    int ms = INT32_MIN; //maxsum
    for (int start = 0; start < n; start++)
    {
        int cs = 0;//current sum
        for ( int end = start; end < n ; end++)
        {
            cs+=a[end];
            ms = max(cs,ms);
        }
    }
    cout<<"max sum : "<<ms<<endl;
    return 0;
}

