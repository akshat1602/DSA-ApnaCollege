#include<iostream>
using namespace std;

int main() {
    int r = 3, c = 2;
    int a[3][2] = { {1, 2}, 
                    {3, 4}, 
                    {5, 6} };
    int transpose[2][3];

    // Print the original matrix
    cout << "The Original matrix is:" << endl;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }

    // Transpose calculation
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            transpose[j][i] = a[i][j];

    // Print the transposed matrix
    cout << "The transpose of the matrix is:" << endl;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j)
            cout << transpose[i][j] << " ";
        cout << endl;
    }
    return 0;
}
