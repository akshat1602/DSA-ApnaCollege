// 2022. Convert 1D Array Into 2D Array
// Given a 1D array `original` and two integers `m` and `n`, create a 2D array with
// `m` rows and `n` columns filled row-wise from `original`. If it is impossible
// because m * n != original.size(), return an empty 2D array.

#include <iostream>
using namespace std;

// C-style solution: convert a 1D array into a dynamically allocated 2D array (int**)
// Returns nullptr if impossible (original length != m * n). Caller must free the memory.
int** construct2DArrayC(const int* original, int len, int m, int n){
	if (len != m * n) return nullptr;
	// allocate array of row pointers
	int** mat = new int*[m];
	for (int i = 0; i < m; ++i) mat[i] = new int[n];

	int idx = 0;
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			mat[i][j] = original[idx++];
		}
	}
	return mat;
}

// print a dynamically allocated 2D array (int**)
void printMatrixC(int** mat, int m, int n){
	if (!mat){
		cout << "[]\n";
		return;
	}
	for (int i = 0; i < m; ++i){
		cout << "[ ";
		for (int j = 0; j < n; ++j) cout << mat[i][j] << ' ';
		cout << "]\n";
	}
}

// free memory allocated by construct2DArrayC
void freeMatrixC(int** mat, int m){
	if (!mat) return;
	for (int i = 0; i < m; ++i) delete[] mat[i];
	delete[] mat;
}

int main(){
	// Example 1: 2x2
	int original1[] = {1,2,3,4};
	int len1 = sizeof(original1)/sizeof(int);
	int m1 = 2, n1 = 2;
	int** mat1 = construct2DArrayC(original1, len1, m1, n1);
	cout << "Example 1 (2x2):\n";
	printMatrixC(mat1, m1, n1);
	freeMatrixC(mat1, m1);

	// Example 2: impossible (1x5)
	int original2[] = {1,2,3};
	int len2 = sizeof(original2)/sizeof(int);
	int m2 = 1, n2 = 5;
	int** mat2 = construct2DArrayC(original2, len2, m2, n2);
	cout << "Example 2 (1x5, impossible):\n";
	printMatrixC(mat2, m2, n2);
	freeMatrixC(mat2, m2); // safe even if mat2==nullptr

	return 0;
}

/*
Revision notes - Convert 1D to 2D using C-style arrays

- Problem: create an m x n 2D array from a 1D array filled row-wise.
- Quick check: length must equal m * n; otherwise return nullptr / empty.

- C-style approach used here:
  * Allocate `int** mat = new int*[m]` and for each row `mat[i] = new int[n]`.
  * Fill row-major: mat[i][j] = original[idx++].
  * Remember to free memory with delete[] for each row and delete[] mat.

- Time complexity: O(m * n) — all elements are visited once.
- Space complexity: O(m * n) for the resulting matrix (heap-allocated).

- Important memory notes:
  * Always free with the same allocation pattern (delete[] mat[i]; then delete[] mat).
  * If using exceptions, prefer RAII wrappers or std::vector to avoid leaks.

- Edge cases & testing:
  * original empty and m*n == 0 -> treat as valid empty matrix (returns an allocated 0-sized structure or nullptr based on design).
  * Non-matching sizes -> function returns nullptr.
  * Test with small sizes (1x1, 1xN, Nx1) and larger matrices.

*/