#include <iostream>
using namespace std;

/* int diagSum(int mat[][3], int n){ //n=m
    int sum = 0;

      for (int i = 0; i < n; i++) //O(n^2)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j){ //Primary diag sum
                sum+=mat[i][j];
            }
            else if(j == n-i-1){ //Secondary diag sum
                sum+=mat[i][j];
            }
        }

    }

    cout<<"Sum is : "<<sum<<"\n";
    return sum;
}
 */

int diagSum(int mat[][3], int n) // O(n) ---Optimized
{                                // n=m
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i]; // i==j --Primary mein
        if (i != n - i - 1)
        { // when i!=j --second mein
            sum += mat[i][n - i - 1];
        }
    }

    cout << "Sum is : " << sum << "\n";
    return sum;
}

int main()
{
    int a[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    int a2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    /* diagSum(a,4); */
    diagSum(a2, 3);

    return 0;
}