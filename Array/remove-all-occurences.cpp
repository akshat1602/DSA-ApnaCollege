#include <iostream>
using namespace std;

void removeOcc(int a[], int n, int target){
    // compact non-target elements to a new array `result` using a write index.
    int result[n];
    int write = 0; // next position to write a non-target element

    for (int i = 0; i < n; ++i) {
        if (a[i] != target) {
            result[write++] = a[i];
        }
    }

    // print only the compacted elements (no zeros for removed elements)
    cout << "Result (elements != " << target << "):\n";
    for (int i = 0; i < write; ++i) {
        cout << result[i] << " "<<endl;
    }
    // If you want to see the full array size with removed slots, you can print the rest as blanks
    // or leave them uninitialised. Prefer returning `write` as the new length in real code.
    
    
}

int main() {
    int a[] = {1,2,2,2,55,3,7};
    int n = sizeof(a)/sizeof(int);
    int target;
    cout<<"Enter the Target : \n";
    cin>>target;
    removeOcc(a,n,target);

    return 0;
}

/*
Revision notes - removing all occurrences (compact approach)

- Problem: remove all occurrences of `target` from an array and produce an array (or length)
    that contains only the non-target elements (no placeholder zeros).

- Compact / two-pointer approach (O(n) time, O(n) extra space or O(1) in-place):
    * Use a write index `w = 0`.
    * Iterate i from 0..n-1. If a[i] != target, write a[w++] = a[i].
    * After the loop, the first `w` elements are the kept elements; the remaining slots
        can be ignored or overwritten.

- In-place variant (no extra array):
    * Use same write index and write back into `a` itself: a[w++] = a[i];
    * After loop, `w` is the new length. Optionally set remaining entries to 0 or leave as-is.

- Common mistakes:
    * Writing to result at the same index `i` (result[i] = ...) leaves gaps when removals occur.
    * Using += on uninitialised entries (result[i] += a[i]) produces wrong values.

- Return value design:
    * Prefer to return the new length `w` so the caller knows how many valid elements exist.
    * Alternatively, return a vector<int> of kept elements for convenience.

- Example:
    a = [1,2,2,2,55,3,7], target = 2 -> result (compacted) = [1,55,3,7], new length = 4

*/