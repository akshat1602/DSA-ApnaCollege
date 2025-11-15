#include <iostream>
using namespace std;

// Transpose using C-style arrays without vectors.
// We represent 2D arrays in row-major order as a contiguous 1D array
// and index using: element at (i,j) is data[i*m + j] where m = number of columns.

// Compute transpose of an n x m matrix `mat` and store the result in `trans` (size m x n).
// Parameters:
//  - mat: pointer to first element of input matrix (row-major flattened), length = n*m
//  - n: number of rows in input
//  - m: number of columns in input
//  - trans: pointer to first element of output matrix (must have space for m*n elements)

void transpose(const int *mat, int n, int m, int *trans){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            // place mat[i][j] at trans[j][i]
            trans[j * n + i] = mat[i * m + j];
        }
    }
}

// Print a matrix stored as flattened row-major array with r rows and c columns
void printMatrix(const int *mat, int r, int c){
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cout << mat[i * c + j] << " ";
        }
        cout << '\n';
    }
}

// In-place transpose for square matrices (n x n). Swaps element (i,j) with (j,i).
// Only valid when the matrix is square.
void transposeInPlace(int *mat, int n){
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){

            int idx1 = i * n + j;
            int idx2 = j * n + i;
           
            int tmp = mat[idx1];
            mat[idx1] = mat[idx2];
            mat[idx2] = tmp;
        }
    }
}

int main(){
    // Example: 2 x 3 matrix
    int n = 2, m = 3;
    int mat[] = {
        1, 4, 9,
        18, 4, 3
    }; // row-major: row0: 1 4 9  ; row1: 18 4 3

    cout << "Original (" << n << " x " << m << ") matrix:\n";
    printMatrix(mat, n, m);

    int trans[3 * 2]; // m x n output (here 3x2)
    transpose(mat, n, m, trans);

    cout << "\nTransposed (" << m << " x " << n << ") matrix:\n";
    printMatrix(trans, m, n);

    // Example in-place transpose (square matrix)
    cout << "\nIn-place transpose example (3x3):\n";
    int sq = 3;
    int sqMat[] = {1,2,3,4,5,6,7,8,9};
    cout << "Before:\n";
    printMatrix(sqMat, sq, sq);
    transposeInPlace(sqMat, sq);
    cout << "After:\n";
    printMatrix(sqMat, sq, sq);

    return 0;
}

/*
Revision notes - Transpose (C-style arrays)

- Data layout (row-major): store 2D matrix as 1D array. Element at (i,j) is at index: i * numCols + j.
- To access mat[i][j] when using flattened array `A`: use A[i * m + j] where m = number of columns.

- Transpose mapping: element at (i,j) in original (n x m) goes to (j,i) in transposed (m x n).
  Implementation formula (flattened): trans[j * n + i] = mat[i * m + j]. Note the switch of `n` and `m`.

- Memory:
  * Using `transpose` that writes to a separate array requires O(n*m) extra space for output.
  * In-place transpose is only possible for square matrices (n == m). For non-square, you need a new buffer.

- Time complexity: O(n * m) — you must visit every element once.
- Space complexity:
  * Separate output: O(n * m) additional space for `trans`.
  * In-place (square): O(1) extra space (swapping elements).

- Common mistakes:
  * Mixing up m and n when computing indices; double-check which dimension multiplies the row index.
  * Returning pointer/reference to a local array — avoid returning pointers to stack memory.
  * For statically declared 2D arrays, the function signatures must match the compile-time column size.

- Practical tips:
  * If you need a generic function for arbitrary sizes without vectors, use the flattened 1D representation.
  * For large matrices, allocate dynamic memory (new/delete) or use smart pointers; prefer std::vector for safety.
  * Test with square and non-square matrices, and with small sizes (1x1, 1xN, Nx1) to verify edge behavior.

*/
