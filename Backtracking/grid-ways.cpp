#include <iostream>
#include <vector>
#include <string>
using namespace std;

int gridWays(int rows, int cols, int n, int m, string ans){
    if(rows == n-1 && cols == m-1) {//BC : only 1 possible way.
        cout<<ans<<"\n";
        return 1;
    } 

    if(rows >= n || cols >= m) return 0; //To avoid infinite iterations.

    //right
   int v1 = gridWays(rows, cols+1, n, m, ans+"R");

    //down
   int v2 =  gridWays(rows+1, cols, n, m, ans+"D");

   return v1 + v2;
}

int main() {
    int n = 3, m =3;
    string ans =""; //to show all moves
    cout<<gridWays(0, 0, n, m, ans)<<endl;
    return 0;
}