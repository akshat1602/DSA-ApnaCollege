#include <iostream>
using namespace std;

// Binary search in a single row (row index = r)
bool binarySearchInRow(int mat[][4], int r, int m, int key, int &found_col){
    int st = 0, end = m - 1;
    while (st <= end){
        int mid = st + (end - st) / 2;
        if (mat[r][mid] == key){
            found_col = mid;
            return true;
        } else if (mat[r][mid] < key){
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

// Row-wise binary search: run binary search on each row (O(n log m))
bool rowWiseBinarySearch(int mat[][4], int n, int m, int key){
    for (int r = 0; r < n; ++r){
        int c;
        if (binarySearchInRow(mat, r, m, key, c)){
            cout << "Found key " << key << " at (" << r << "," << c << ") using row-wise binary search\n";
            return true;
        }
    }
    cout << "Key " << key << " not found using row-wise binary search\n";
    return false;
}

// Binary search in a single column (col index = c)
bool binarySearchInCol(int mat[][4], int c, int n, int key, int &found_row){
    int st = 0, end = n - 1;
    while (st <= end){
        int mid = st + (end - st) / 2;
        if (mat[mid][c] == key){
            found_row = mid;
            return true;
        } else if (mat[mid][c] < key){
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

// Column-wise binary search: run binary search on each column (O(m log n))
bool colWiseBinarySearch(int mat[][4], int n, int m, int key){
    for (int c = 0; c < m; ++c){
        int r;
        if (binarySearchInCol(mat, c, n, key, r)){
            cout << "Found key " << key << " at (" << r << "," << c << ") using column-wise binary search\n";
            return true;
        }
    }
    cout << "Key " << key << " not found using column-wise binary search\n";
    return false;
}

int main(){
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    int key;
    cout << "enter the key : " << endl;
    cin >> key;

    // Demonstrate both approaches
    rowWiseBinarySearch(mat, 4, 4, key);
    colWiseBinarySearch(mat, 4, 4, key);

    return 0;
}

// Revision notes - binary-search row-wise and column-wise
// - Problem setup: matrix rows and columns are sorted (non-decreasing).
// - Two simple binary-search approaches implemented here:
//   1) Row-wise: binary-search each row independently -> O(n * log m)
//   2) Column-wise: binary-search each column independently -> O(m * log n)
// - Use-cases: row-wise is good when rows are long and fewer rows; column-wise when columns are long.

// - Correctness: Each row (or column) is individually sorted so binary search on that row (or column)
//   is valid and returns whether key exists in that row/column.
// - Return/Output: functions print the first found position and return true; they stop early on first match.

// - Edge cases & notes:
//   * If matrix dimensions differ from 4, adjust function signatures or use templates/vectors.
//   * When key is present multiple times, these functions report the first row/column in which
//     the binary search found it (not necessarily the top-leftmost occurrence).
//   * For best asymptotic runtime when both n and m are large, prefer Staircase search (O(n+m)).

// - Staircase search summary (recommended): start at top-right (r=0,c=m-1) and move left/down:
//     if mat[r][c] == key -> found
//     else if mat[r][c] > key -> c--
//     else r++
//   This uses O(1) space and O(n+m) time and is optimal for this problem.

// - Testing tips:
//   * Test keys at corners, middle, and non-existing values (e.g., 10, 50, 29, 100).
//   * Compare outputs of row-wise and column-wise to ensure consistency.

// - Implementation notes:
//   * We used fixed-size 4 columns (int mat[][4]) to keep the signature simple for this exercise.
//   * To generalize, switch to vector<vector<int>> and adapt binary search accordingly.