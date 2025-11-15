#include <iostream>
#include <string>
using namespace std;

void changex(int x)
{
    x = x * 3;
    cout << "x in function : " << x << endl;
}

int main()
{
    int x = 5;
    changex(x);

    cout << "x in main : " << x << endl;

    return 0;
}