//FLOYD'S TRIANGLE
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int num = 1;
    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<num<<" ";
            num+=1; //main logic
        }
        cout<<endl;  
    }
return 0;
}