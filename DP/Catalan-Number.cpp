#include <iostream>
#include <vector>
using namespace std;

//RECURSION
int catalanRec(int n){ //O(2^n)
    if(n == 0 || n == 1){ //BC
        return 1;
    }

    int ans = 0;

    for(int i = 0; i<n; i++){
        ans += catalanRec(i) * catalanRec(n-i-1);
    }
    return ans;
}

//MEMOIZATION
int catalanMem(int n, vector<int> &dp){ //O(n^2)
    if(n == 0 || n == 1){ //BC
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ans = 0;

    for(int i = 0; i<n; i++){
        ans += catalanMem(i, dp) * catalanMem(n-i-1, dp);
    }
    return dp[n] = ans;
}

//TABULATION
int catalanTab(int n){
    vector <int> dp(n+1, 0);
    dp[0] = dp[1] = 1;//initialization

    for(int i = 2; i<=n; i++){ //ith catalan
        for(int j = 0; j<i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n]; //ans
}

int main() {
    int n = 6;
    vector <int> dp(n+1, -1);

    //First n catalan numbers
    cout<<"By recursion : ";
    for(int i = 0; i<=6; i++){
        cout<<catalanRec(i)<<" ";
    }
    cout<<endl;

    cout<<"By Memoization : ";
    for(int i = 0; i<=6; i++){
        cout<<catalanMem(i, dp)<<" ";
    }
    cout<<endl;

    cout<<"By Tabulation : ";
    for(int i = 0; i<=6; i++){
        cout<<catalanTab(i)<<" ";
    }
    cout<<endl;

    return 0;
}