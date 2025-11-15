#include <iostream>
using namespace std;
int main()
{
    int arr[3][4];
    int n = 3, m = 4;

    cout << "Enter elements of array :" << endl;
    for (int i = 0; i < n; i++) // Input loop
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) // Output loop
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}