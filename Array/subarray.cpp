// O(n^3)

#include <iostream>
using namespace std;

void PrintSubArr(int *arr, int size)
{
    for (int start = 0; start < size; start++) // 0 to 4 //n times
    {
        for (int end = start; end < size; end++) //n times
        {
            // cout<<"("<<start<<","<<end<<")"<<" ";
            for (int i = start; i <= end; i++) //n times
            {
                cout << arr[i];
            }
            cout << ",";
        }

        cout << "\n";
    }
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int size = 5;

    PrintSubArr(a, size);

    return 0;
}