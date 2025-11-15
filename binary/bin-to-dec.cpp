#include <iostream>
#include <string>
using namespace std;
int binDec(int n)
{
    int ans = 0;
    int pow = 1;
    int rem;

    while (n > 0)
    {
        rem = n % 10;
        ans += (rem * pow);
        n /= 10;
        pow *= 2; // 2 ki powers badhengi
    }
    return ans;
}
int main()
{
    int n;
    cout << "enter a number : " << endl;
    cin >> n;

    cout << "decimal to binary : " << binDec(n) << endl;

    return 0;
}