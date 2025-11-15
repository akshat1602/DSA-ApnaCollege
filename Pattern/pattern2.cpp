// Square Pattern
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i, j;

    for (i = 1; i <= 4; i++) // rows
    {

        for (j = 1; j <= 4; j++) // columns
        {
            cout << "&";
        }
        cout << endl;
    }

    return 0;
}