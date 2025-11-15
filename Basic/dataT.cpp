#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float PI = 3.14159265359;
    cout << setprecision(6) << "Value of PI: " << PI << endl;
    double PI2 = 3.14159265359;
    cout << setprecision(8) << "Value of PI2: " << PI2 << endl;
    return 0;
}
