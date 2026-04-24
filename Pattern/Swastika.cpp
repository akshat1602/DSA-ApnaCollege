#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 11;

    //Upper Half -> Horizontally
    for(int i = 1; i<=n/2+1; i++){
        for(int j = 1; j<=n; j++){
            if(j == 1 || i == n/2+1 || j == n/2+1){
                cout<<"*";
            }
            else if(i == 1 && j > n/2+1) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }

    //Lower Half -> Horizontally
    for(int i = n/2+2; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(j == n/2+1 ||  j == n){
                cout<<"*";
            }
            else if(i == n && j < n/2+1) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}