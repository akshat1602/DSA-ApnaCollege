#include <iostream>
#include <vector>
using namespace std;

//Using Memoization : Recursion + storage.
int fibDP(int n, vector <int> &f){ //TC : O(n).
    if(n == 0 || n == 1){
        return n;
    }

    if(f[n] != -1){
        return f[n]; //means already calculated
    }
    
    //storing calculated answers in  DP array : f.
    f[n] = fibDP(n-1, f) + fibDP(n-2, f);
    return f[n];
}


//Using Tabulation
//TC : O(n)
int fibDPTab(int n){
    vector <int> fib(n+1, 0); //fib[i] = ith fib hoga
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i<=n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}

int main() {
    int n = 6;
    vector <int> f(n+1, -1); //n+1 size with initial values as -1.
    cout<<"By Memoization : "<<fibDP(n, f)<<endl;
    cout<<"By Tabulation : "<<fibDPTab(n)<<endl;
    
    return 0;
}