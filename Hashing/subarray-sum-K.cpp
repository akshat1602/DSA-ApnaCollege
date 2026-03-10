#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int subarrayCountK(vector <int> nums, int K){ //sum[i,j] = sum[j] - sum[i-1];
    unordered_map <int, int> m; // <sum, count>

    m[0] = 1; // for single element arr : <0, 1>
    int currSum = 0;
    int ans = 0;

    for(int j = 0; j<nums.size(); j++){
        currSum += nums[j];

        if(m.count(currSum - K)){
            ans += m[currSum-K];
        }

        if(m.count(currSum)){ //to increase count
            m[currSum]++;
        }
        else{ //to add the sum with 1 count in map.
            m[currSum] = 1;
        }
    }

    return ans;
}

int main() {
    vector <int> nums = {10, 2, -2, -20, 10};
    int K = -10;

    cout<<"Count of subarrays with sum "<<K<<" : "<<subarrayCountK(nums, K)<<endl;
    
    return 0;
}