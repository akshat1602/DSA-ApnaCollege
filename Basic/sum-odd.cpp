#include <iostream>
#include <string>
using namespace std;
int main()
{
int n,i=1,sum=0;
cout<<"enter a number "<<endl;
cin>>n;

while(i<=n)
{
    if(i%2!=0)
    {
        sum+=i;
    }
    i++;
}
cout<<"sum : "<<sum<<endl;
return 0;
}