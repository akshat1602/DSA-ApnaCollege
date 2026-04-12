#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int LIS(vector <int> arr) { //O(n^2)
    unordered_set <int> s(arr.begin(), arr.end()); //Unique elements storage

    vector <int> arr2(s.begin(), s.end());
    sort(arr2.begin(), arr2.end()); //ascending sorted order

    //LCS = LIS
    int n = arr.size();
    int m = arr2.size();
    
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<m+1; j++){
            if(arr[i-1] == arr2[j-1]){
                //when characters match
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                //when characters don't match
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m]; //final ans
}

int main() {
    vector<int> arr = {50, 3, 10, 7, 40, 80};

    cout<<"LIS length is : "<<LIS(arr)<<endl;
    
    return 0;
}