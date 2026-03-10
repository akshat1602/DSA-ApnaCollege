#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int largest0Sum(vector <int> nums){
    unordered_map <int, int> m; //<sum, idx>

    int currSum = 0;
    int ans = 0;

    for(int j = 0; j<nums.size(); j++){
        currSum += nums[j];

        if(m.count(currSum)){ //if exists
            int currLen = j - m[currSum]; //j-idx
            ans = max(ans, currLen); //to get max length
        }
        else{
            m[currSum] = j;
        }
    }

     return ans;
}

int main() {
    vector <int> nums = {15, -2, 2, -8, 1, 7, 10};

    cout<<"Max Subarray with sum 0 : "<<largest0Sum(nums)<<endl;
    
    return 0;
}