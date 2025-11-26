#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printSubsets(string str, string subset){
    int n = str.size();
    if(n == 0){
        cout<<subset<<"\n";
        return;
    }

    char ch = str[0];

    //Yes case
    printSubsets(str.substr(1, n-1), subset+ch);

    //No case
    printSubsets(str.substr(1, n-1), subset);
}

int main() {
    string str = "abc";
    string subset = "";

    printSubsets(str, subset);
    return 0;
}

/*
Revision Notes - Backtracking/subsets.cpp

- What this program does:
    Prints all subsets (subsequences) of the input string `str` using a
    simple recursive include/exclude approach. The recursion works on the
    first character: include it in the current `subset` or exclude it.

- Common reasons you might see no output (and how to check):
    1) Program not being run: Make sure you compile and run the binary produced
         by your build command. Example (PowerShell):
             g++ "Backtracking/subsets.cpp" -o "Backtracking/subsets.exe"; "Backtracking/subsets.exe"

    2) `str` is empty: The base case prints `subset` only when `str.size() == 0`.
         If the initial `str` is empty, the program will print a single empty line.

    3) Output buffered/not visible: The program prints with `\n` and returns.
         If your runner captures output, check the terminal panel (integrated terminal)
         or run the exe directly to see the output.

- Notes about correctness and complexity:
    - The recursion correctly uses `str.substr(1, n-1)` to drop the first char.
    - Time complexity is O(2^n) and it prints 2^n lines (including the empty subset).

- How to test quickly:
    - Compile and run locally as shown above. Expected output for `"abc"` (order
        may vary depending on recursion order):
            abc
            ab
            ac
            a
            bc
            b
            c
            (empty line)

- If you want a different order (e.g., lexicographic), collect results in a
    vector, sort them, then print.

If you'd like, I can:
 - Change printing order, filter out the empty subset, or store results in a
     vector for sorting/returning instead of direct printing.
 - Add sample unit tests or small harness to run multiple inputs.
*/