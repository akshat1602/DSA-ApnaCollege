#include <iostream>
#include <vector>
using namespace std;

//TABULATION
//here infinite choices of items
int knapsackTab(vector <int> val, vector<int> wt, int W, int n){//TC : O(n*W)
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<W+1; j++){
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j){
                //in between inclusion and exclusion
                dp[i][j] = max(itemVal + dp[i][j-itemWt], dp[i-1][j]); //only inclusion condition mein change
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

    cout<<"Max Profit by Tabulation : "<<knapsackTab(val, wt, W, n)<<endl;

    return 0;
}