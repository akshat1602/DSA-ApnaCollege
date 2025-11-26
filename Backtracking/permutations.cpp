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
Revision Notes - Backtracking/permutations.cpp

- What this file does:
    Generates all permutations of the input string `str` using a recursive
    algorithm (`permutations`). Results are printed in `main`.

- Common reasons you might see incorrect or no output:
    1) Program not being run: Ensure you compile and run the binary produced
         by your build command. Example (PowerShell):
             g++ "Backtracking/permutations.cpp" -o "Backtracking/permutations.exe"; "Backtracking/permutations.exe"

    2) No output: This happens if `str` is empty or if the `permutations` function
         does not reach the base case. Verify that `str` is initialized correctly.

    3) Output buffered or hidden: The program writes to stdout using `cout`.
         If your runner captures output, check the integrated terminal or run the
         executable directly to see results.

- Expected output for `str = "abc"` (order depends on implementation):
        abc
        acb
        bac
        bca
        cab
        cba

- Testing checklist:
    - Compile and run using the command above.
    - Add a debug print at the start of `main` (e.g., `cout << "Running...\n";`) to
        confirm the program starts.
    - If no output is seen, instrument `permutations` to print when the base case is hit
        to ensure the recursion reaches it.

- Possible improvements I can apply:
    - Add unit tests or a small test harness to run multiple inputs automatically.
    - Add comments in `permutations` showing the base case and recursive steps.
*/