#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int arr[7] = {1, 2, 7, 11, 15, 5, 9};
    int n = 7;
    int target = 9;

    unordered_map<int, int> m; //key = arr[i], val = i.

    for (int i = 0; i < n; i++)
    {
        int complement = target - arr[i]; //to find the complement of a number for pair completion
        if(m.count(complement)){
            cout<<"ans = "<<m[complement]<<", "<<i<<endl;
            break;
        }
        m[arr[i]] = i; //adding in map a new element
    }
    
    
    return 0;
}