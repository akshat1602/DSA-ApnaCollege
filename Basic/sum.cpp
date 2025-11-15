#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i, n, sum = 0;
    cout << "enter a number" << endl;
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << "sum : " << sum << "\n";
    return 0;
}