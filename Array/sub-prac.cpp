#include <iostream>
#include <climits>
using namespace std;

void PrintSubArr(int *a, int size){
    int maxSum = INT_MIN;
    int currSum = 0;
    
    for (int i = 0; i < size; i++)
    {
        currSum+=a[i];
        maxSum = max(maxSum, currSum);

        if(currSum<0){
            currSum = 0;
        }
    }
    cout<<"Max Sum = "<<maxSum<<endl;
}
    

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int size = 5;

    PrintSubArr(a, size);

    return 0;
}