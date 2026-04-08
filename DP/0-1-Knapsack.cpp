#include <iostream>
#include <vector>
using namespace std;

//RECURSION
int knapsackRec(vector <int> val, vector<int> wt, int W, int n){ //TC : O(2^n)
    //BC
    if(n==0 || W==0){
        return 0;
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= W){ //valid wt
        //include
        int ans1 = knapsackRec(val, wt, W-itemWt, n-1) + itemVal;

        //exclude
        int ans2 = knapsackRec(val, wt, W, n-1);

        return max(ans1, ans2);
    }
    else{
        //exclude
        return knapsackRec(val, wt, W, n-1);
    }
}

//MEMOIZATION
int knapsackMem(vector <int> val, vector<int> wt, int W, int n, vector<vector<int>> &dp){ //TC : O(n*W)
    //BC
    if(n==0 || W==0){
        return 0;
    }

    if(dp[n][W] != -1){ //means already value calculated and stored
        return dp[n][W];
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= W){ //valid wt
        //include
        int ans1 = knapsackMem(val, wt, W-itemWt, n-1, dp) + itemVal;

        //exclude
        int ans2 = knapsackMem(val, wt, W, n-1, dp);

        dp[n][W] =  max(ans1, ans2);
    }
    else{
        //exclude
        dp[n][W] = knapsackMem(val, wt, W, n-1, dp);
    }

    return dp[n][W];
}

//TABULATION
int knapsackTab(vector <int> val, vector<int> wt, int W, int n){//TC : O(n*W)
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<W+1; j++){
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j){
                //in between inclusion and exclusion
                dp[i][j] = max(itemVal + dp[i-1][j-itemWt], dp[i-1][j]);
            }
            else{
                //exclude
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    //Print tabulation matrix
    cout<<endl;
    cout<<"Tab Matrix\n";
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<W+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return dp[n][W]; //as ans is always at last cell.
}


int main() {
    vector <int> val = {15, 14, 10, 45, 30};
    vector <int> wt = {2, 5, 1, 3, 4};
    int W = 7;
    int n = 5;
    vector<vector<int>> dp(n+1, vector<int>(W+1, -1)); //2D matrix

    cout<<"Max Profit by Recursion : "<<knapsackRec(val, wt, W, n)<<endl;
    cout<<"Max Profit by Memoization : "<<knapsackMem(val, wt, W, n, dp)<<endl;
    cout<<"Max Profit by Tabulation : "<<knapsackTab(val, wt, W, n)<<endl;

    cout<<endl;

    //Print memoization matrix
    cout<<"Mem Matrix\n";
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<W+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}