#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 6;

    for(int i = 1; i<=n; i++){
        //Even
        if(i%2==0){
            for(int j = 1; j<=i; j++){
                cout<<"*";
            }
        }
        
        //Odd
        else{
            for(int j = 1; j<=i+1; j++){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}