#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cout << "enter a number" << endl;
    cin >> n;

    bool isPrime = true;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0) // here i is the factor of the given number
        {
            isPrime = false;
            break;
        }
    }

    if (isPrime == true)
        cout << "prime number" << endl; // endl is slower
    else
        cout << "not prime \n"; //\n is faster in execution

    return 0;
}