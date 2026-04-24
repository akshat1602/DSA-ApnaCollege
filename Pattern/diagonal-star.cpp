#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 11;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(i == 1 || j == 1 || i == n || j == n || i == j || j == n-i+1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}