#include <iostream>
#include <vector>
using namespace std;

int firstOccu(vector <int> a, int target, int i){
    
    if(a[i] == target) return i;
    if(i == a.size()) return -1;
    
    return firstOccu(a, target, i+1); //recursion
}

int main() {
    vector <int> a = {1,4,5,6,6,7,8,7};
    int target;
    cout<<"Enter the target : "<<endl;
    cin>>target;

    cout<<firstOccu(a, target, 0)<<endl;
    
    return 0;
}