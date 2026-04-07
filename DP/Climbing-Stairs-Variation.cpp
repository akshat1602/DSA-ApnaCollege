#include <iostream>
#include <vector>
using namespace std;

//TABULATION
int countWaysTabulationDP(int n){ //O(n)
    //1,2 and 3 jumps now
    vector <int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int main() {
    int n = 4;
    vector <int> dp(n+1, -1);

    cout<<"Ways to reach destination by Tabulation : "<<countWaysTabulationDP(n)<<endl;
    return 0;
}