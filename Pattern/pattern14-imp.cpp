// Pyramid
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n = 4;
    for (int i = 0; i < n; i++)
    {//combination of spaces and numbers
        for (int j = 0; j < n - i - 1; j++)//space loop
        {
            cout << " ";
        }
        for (int k = 1; k <= i + 1; k++)
        {
            cout << k;
        }
        for (int j = i; j > 0; j--)
        {
            cout<<j;
        }
        
        cout << endl;
    }

    return 0;
}