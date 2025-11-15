#include <iostream>
#include <string>
using namespace std;

int sumDig(int n)
{
    int sum = 0;
    int dig;
    while(n>0)
    {
        dig=n%10;
        n = n/10;
        sum+=dig;
    }
    return sum;
}

int main()
{
    int num;
    cout<<"enter a number : "<<endl;
    cin>>num;

    cout<<"sum of digits : "<<sumDig(num)<<endl;

return 0;
}