// Triangle
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n,num = 1;
    cout << "enter the limit : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++) //pattern no. of row ke equal print karna hai
        {
            cout << num;
        }
        num+=1;
        cout << endl;
    }

    return 0;
}