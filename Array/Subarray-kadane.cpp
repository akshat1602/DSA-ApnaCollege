// TC : O(n)
#include <iostream>
using namespace std;

void SubArraySum(int *a, int size)
{
    int maxSum = INT32_MIN;
    int currSum = 0; // keeps a track of current window

    for (int i = 0; i < size; i++)
    {
        currSum += a[i];
        maxSum = max(currSum, maxSum);

        if (currSum < 0)
        { // For -ve values
            currSum = 0;
        }
    }
    cout << "Maximum subarray sum = " << maxSum << endl;
}

int main()
{
    int a[5] = {1, -5, -6, 7, 8};
    int size = 5;

    SubArraySum(a, size);

    return 0;
}

/*
DRY RUN

a = {1, -5, -6, 7, 8}
Initial state:

maxSum = INT32_MIN
currSum = 0
We'll iterate i from 0..4 and show the actions.

i = 0 (a[0] = 1)
currSum += 1 -> currSum = 0 + 1 = 1
maxSum = max(INT32_MIN, 1) = 1
currSum < 0? No (1 >= 0), so no reset.
State after i=0: currSum = 1, maxSum = 1

i = 1 (a[1] = -5)
currSum += -5 -> currSum = 1 + (-5) = -4
maxSum = max(1, -4) = 1
currSum < 0? Yes (-4 < 0) -> reset currSum = 0
State after i=1: currSum = 0, maxSum = 1

i = 2 (a[2] = -6)
currSum += -6 -> currSum = 0 + (-6) = -6
maxSum = max(1, -6) = 1
currSum < 0? Yes -> reset currSum = 0
State after i=2: currSum = 0, maxSum = 1

i = 3 (a[3] = 7)
currSum += 7 -> currSum = 0 + 7 = 7
maxSum = max(1, 7) = 7
currSum < 0? No
State after i=3: currSum = 7, maxSum = 7.

i = 4 (a[4] = 8)
currSum += 8 -> currSum = 7 + 8 = 15
maxSum = max(7, 15) = 15
currSum < 0? No
State after i=4: currSum = 15, maxSum = 15
Loop ends. 

Final printed output:
Maximum subarray sum = 15
*/