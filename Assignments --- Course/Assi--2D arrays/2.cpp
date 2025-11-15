#include <iostream>
using namespace std;

int row2sum(int (*mat)[3], int n, int m)
{
    int rowsum = 0;

    for (int i = 1; i < 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            rowsum += mat[i][j];
        }
    }
    return rowsum;
}

int main()
{
    int mat[3][3] = {
        {1, 4, 9},
        {18, 4, 3},
        {2, 2, 3}};

    cout << "Sum of 2nd row : " << row2sum(mat, 3, 3) << endl;

    return 0;
}