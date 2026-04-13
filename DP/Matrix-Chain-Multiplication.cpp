#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//RECURSION
int mcmRec(vector<int> arr, int i, int j){ 
    //Return minCost

    //BC
    if(i == j){ //single matrix
        return 0;
    }

    int ans = INT_MAX;

    for(int k = i; k<j; k++){
        //(i , k)
        int cost1 = mcmRec(arr, i, k);

        //(k+1, j)
        int cost2 = mcmRec(arr, k+1, j);

        //Curr Partition Cost
        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, currCost);
    }

    return ans;
}

//MEMOIZATION
int mcmMem(vector<int> arr, int i, int j, vector<vector<int>> &dp){ 
    //Return minCost

    //BC
    if(i == j){ //single matrix
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = INT_MAX;

    for(int k = i; k<j; k++){
        //(i , k)
        int cost1 = mcmMem(arr, i, k, dp);

        //(k+1, j)
        int cost2 = mcmMem(arr, k+1, j, dp);

        //Curr Partition Cost
        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, currCost);
    }

    return dp[i][j] = ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3}; //n-> n-1 matrices (1 to n-1)
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int> (n, -1));

    cout<<"Min Cost by Recursion : "<<mcmRec(arr, 1, n-1)<<endl;
    cout<<"Min Cost by Memoization : "<<mcmMem(arr, 1, n-1, dp)<<endl;
    return 0;
}