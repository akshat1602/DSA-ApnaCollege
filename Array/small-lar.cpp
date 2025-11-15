#include <iostream>
#include <string>
using namespace std;

int main()
{
int a[5];
int min = INT32_MAX;
int max = INT32_MIN;

cout<<"enter elements of array : "<<endl;

for (int i = 0; i < 5; i++) //inputting elements
{
    cin>>a[i];
}

for (int i = 0; i < 5; i++) //smallest
{
    if(a[i] < min)
    {
        min = a[i];
    }
}
for (int i = 0; i < 5; i++) //largest
{
    if(a[i] > max)
    {
        max = a[i];
    }
}


cout<<"largest element : "<<max<<endl;
cout<<"smallest element :"<<min<<endl;

return 0;
}