//Try with vectors again

#include <iostream>
using namespace std;

bool containsDup(int *nums, int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(nums[i]==nums[j]){
                return true;
            }
        }
    }
    return false;
    
}


int main() {
    int nums[] = {1,2,4,5};
    int size = sizeof(nums)/sizeof(int);

    cout<<containsDup(nums, size)<<endl;
    return 0;
}