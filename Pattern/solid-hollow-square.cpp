#include <iostream>
#include <vector>
using namespace std;

void solidSquare(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void hollowSquare(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(i == 1 || j == 1 || i == n || j == n){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

int main() {
    int n = 4;

    solidSquare(n);
    cout<<endl;
    hollowSquare(n);

    return 0;
}