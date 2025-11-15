#include <iostream>
using namespace std;

void searchSortedMatrix(int a[][4], int n, int m){
    int key;
    cout<<"enter the number to be searched : "<<"\n";
    cin>>key;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(key == a[i][j]){
                cout<<"Index of key is : "<<"("<<i<<","<<j<<")"<<endl;
                found = true;
            }
        } 
    }
    if(!found)
     cout << "Element not found in the matrix" << endl;
}

int main() {
    int a[4][4] = {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };

    searchSortedMatrix(a, 4, 4);
    return 0;
}

// Revision notes - quick points to revisit for exam/recap:

// - Matrix property: each row is sorted left->right and each column is sorted top->bottom.
// - Current implementation: brute-force nested loops that check every element.
//   * Time complexity: O(n * m) where n = rows, m = cols.
//   * Space complexity: O(1) (only local vars and a boolean flag).
 
// - Behavior: prints the indices of all occurrences of the key (0-based indices).
//   * If you only want the first occurrence, break/return after the first match to avoid duplicates.
// - Minor inefficiency: function reads `key` from stdin. For testing, pass `key` as a parameter instead.

// - Edge cases to remember:
//   * Empty matrix or invalid dimensions -> handle before searching.
//   * All elements smaller/larger than key -> not found; `found` remains false.
// - Indexing note: code prints 0-based indices; for user-facing output you may prefer 1-based.
// - Testing tip: try keys at corners and middle (e.g., 10, 50, 29 in the sample) to verify paths.
// - API suggestion: return a pair<int,int> for a single found position or vector<pair<int,int>> for all positions
//   instead of printing directly — this makes unit testing easier.
// Example (sample matrix): searching 29 -> found at (2,1) using 0-based indexing.