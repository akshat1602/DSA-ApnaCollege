#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i = 1, n, sum = 0;
    cout << "enter a number" << endl;
    cin >> n;
    while (i <= n)
    {
        sum += i;
        i++;
    }
    cout << "sum : " << sum << endl;
    return 0;
}