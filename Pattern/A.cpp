#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 10;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n/2+1; j++){
            //Main logic
            if(i == 1 || j == 1 || i == n/2+1 || j == n/2+1){ //1st and last check on rows and cols
                if(i == 1 && (j == 1 || j == n/2+1)) cout<<" "; //only for 1st row check
                else cout<<"*";
            }

            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}