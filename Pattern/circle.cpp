#include <iostream>
using namespace std;

int main() {
    int n = 6;

    // Top row fill with star 
    for(int i = 0; i < n; i++) cout << "*";
    cout << endl;

    // Upper half imp
    for(int i = n/2; i >= 1; i--) {
        // left stars
        for(int j = 0; j < i; j++) cout << "*";

        // spaces 
        for(int j = 0; j < 2*(n/2 - i) + 1; j++) cout << " ";

        // right stars
        for(int j = 0; j < i; j++) cout << "*";

        cout << endl;
    }

    // Lower half....
    for(int i = 1; i <= n/2; i++) {
        // left stars
        for(int j = 0; j < i; j++) cout << "*";

        // spaces
        for(int j = 0; j < 2*(n/2 - i) + 1; j++) cout << " ";

        // right stars ...
        for(int j = 0; j < i; j++) cout << "*";

        cout << endl;
    }

    // Bottom row
    for(int i = 0; i < n; i++) cout << "*";

    return 0;
}