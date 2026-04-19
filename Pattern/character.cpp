#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 5;

    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j++){
            cout<<char('A' + j - 1);
        }
        cout<<endl;
    }
    return 0;
}