//SUM AND FACTORIAL
#include <iostream>
#include <string>
using namespace std;

int sum(int n)
{
    int sumN = 0;
    for (int i = 1; i <= n; i++)
    {
        sumN += i;
    }
    return sumN;
}

    int fact(int n)
    {
        int fac = 1;
        for (int i = 1; i <= n ; i++)
        {
            fac*=i;
        }
        return fac;
    }

int main()
{
    int n;
    cout << "enter the limit : " << endl;
    cin >> n;

    cout <<"sum : "<< sum(n) << endl;
    cout<<"factorial : "<<fact(n)<<endl;
    return 0;
}