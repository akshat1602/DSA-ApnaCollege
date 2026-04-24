#include <iostream>
#include <vector>
using namespace std;

void solidRhombus(int n){
    for(int i = 1; i<=n; i++){
        //Left half
        for(int j = 1; j<=n; j++){
            if(j < n-i+1) cout<<" ";
            else{
                cout<<"*";
            }
        }
        //Right half
        for(int j = 1; j<n; j++){
            if(j < n-i+1) cout<<"*";
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void hollowRhombus(int n){
    for(int i = 1; i<=n; i++){
        //Left half
        for(int j = 1; j<=n; j++){
            if(j < n-i+1) cout<<" ";
            else{
                cout<<"*";
            }
        }
        //Right half
        for(int j = 1; j<n; j++){
            if(j < n-i+1) cout<<"*";
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

int main() {
    int n = 4;
    solidRhombus(n);
    cout<<endl;
    return 0;
}