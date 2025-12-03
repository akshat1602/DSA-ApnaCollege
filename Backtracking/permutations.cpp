#include <iostream>
#include <vector>
using namespace std;

void permutations(string str, string ans){
    int n = str.size();
    if(n == 0){
        cout<<ans<<"\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        string nextLvl = str.substr(0,i) + str.substr(i+1, n-i-1); //to delete ith element.
        permutations(nextLvl, ans + ch); //ith element choice to add in permutation.
    }
}

int main() {
        string str = "abc";
        string ans = "";

        permutations(str, ans);
        return 0;
}

/*
Revision Notes (with dry-run) - Backtracking/permutations.cpp

Summary
- Generates all permutations of `str` by choosing each character in turn,
    recursing on the remaining characters, then returning to try the next choice.

Dry-run: initial call `permutations("abc", "")`

Root call: permutations("abc", "")
Loop i=0..2

i=0:
    ch = 'a'
    nextLvl = "bc"
    call permutations("bc", "a")
        i=0:
            ch='b', nextLvl="c"
            call permutations("c","ab")
                i=0:
                    ch='c', nextLvl=""
                    call permutations("","abc") -> base case prints: abc
                return to permutations("c","ab") -> loop ends -> return
        return to permutations("bc","a")
        i=1:
            ch='c', nextLvl="b"
            call permutations("b","ac")
                call permutations("","acb") -> prints: acb
            return
        end -> return to root

i=1:
    ch='b', nextLvl="ac"
    call permutations("ac","b")
        i=0 -> prints: bac
        i=1 -> prints: bca

i=2:
    ch='c', nextLvl="ab"
    call permutations("ab","c")
        i=0 -> prints: cab
        i=1 -> prints: cba

Final printed sequence (this implementation):
    abc
    acb
    bac
    bca
    cab
    cba

Call-stack snapshot (just before printing "acb")
- permutations("abc","") [root]
    - permutations("bc","a")
        - permutations("b","ac")
            - permutations("","acb")  <-- now prints "acb"

How backtracking manifests here
- Choose: pick `ch = str[i]` and add to `ans` (passed as `ans + ch`).
- Recurse: call `permutations(nextLvl, ans + ch)` to build remaining positions.
- Unchoose: explicit undo isn't needed because `str` and `ans` are passed by
    value (copies). When recursion returns the caller's `str`/`ans` are unchanged,
    so the function naturally proceeds to the next `i` (the logical unchoose).

Notes & optimizations
- This implementation is simple and easy to understand, but it allocates
    new strings at every call (`substr` and `ans + ch`). For large inputs this
    increases time and memory overhead.
- In-place swap-based approach (explicit choose/recurse/unchoose) reduces
    allocations: swap characters in `str`, recurse with index+1, then swap back.

Quick test
- Compile and run (PowerShell):
        g++ "Backtracking/permutations.cpp" -o "Backtracking/permutations.exe"; "Backtracking/permutations.exe"

If you'd like, I can replace this with an in-place swap version and add
instrumentation to show the call stack for each printed permutation.
*/