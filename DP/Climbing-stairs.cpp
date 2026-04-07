#include <iostream>
#include <vector>
using namespace std;

//RECURSION
int countWaysRec(int n){ //O(2^n).
    if(n == 0 || n == 1){
        return 1;
    }
    return countWaysRec(n-1) + countWaysRec(n-2);
}

//MEMOIZATION
int countWaysMemDP(int n, vector <int> &dp){ //O(n).
    if(n == 0 || n == 1){
        return 1;
    }
    
    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = countWaysMemDP(n-1, dp) + countWaysMemDP(n-2, dp);
    return dp[n];
}

//TABULATION
int countWaysTabulationDP(int n){ //O(n)
    vector <int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n = 6;
    vector <int> dp(n+1, -1);

    cout<<"Ways to reach destination by Recursion : "<<countWaysRec(n)<<endl;
    cout<<"Ways to reach destination by Memoization : "<<countWaysMemDP(n, dp)<<endl;
    cout<<"Ways to reach destination by Tabulation : "<<countWaysTabulationDP(n)<<endl;
    return 0;
}