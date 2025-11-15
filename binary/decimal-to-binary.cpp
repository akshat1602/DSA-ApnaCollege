#include <iostream>
#include <string>
using namespace std;

int decBin(int n)
{
    int ans = 0;
    int pow = 1; // as 10 to power 0 is 1.(imp)
    int rem;

    while (n > 0)
    {
        rem = n % 2;
        n /= 2;

        ans = ans + (rem * pow); // decimal se binary jo bnega woh hai yeh
        pow *= 10;               // 10 ki powers badhengi
    }
    return ans;
}
int main()
{
    int n;
    cout << "enter a number : " << endl;
    cin >> n;

    cout << "binary of number : " << decBin(n) << endl;

    return 0;
}