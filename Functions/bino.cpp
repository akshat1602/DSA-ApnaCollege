#include <iostream>
#include <string>
using namespace std;

int fact(int n)
{
    int fac = 1;

    for (int i = 1; i <= n; i++)
    {
        fac*=i;
    }
    return fac;
}

int main()
{
    int n,r;
    cout<<"enter n and r : "<<endl;
    cin>>n>>r;

    int fact_n = fact(n);
    int fact_r = fact(r);
    int fact_nr = fact(n-r);

    int bino = fact_n/(fact_r*fact_nr);
    cout<<"Binomial nCr : "<<bino<<endl;

return 0;
}