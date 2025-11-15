//REVERSE PATTERN
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cout << "enter the limit : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}