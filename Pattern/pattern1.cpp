// Square Pattern
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i, j;

    for (i = 1; i <= 4; i++) // rows
    {

        for (j = 1; j <= 4+1; j++) // columns --also it represents number of elements in a row.
        {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}