// TC: O(n^2)

#include <iostream>
using namespace std;

void SubArraySum(int *a, int size)
{
    int maxSum = INT32_MIN; // -infinity almost, predefined macro.

    // For every possible start index `st`, compute sums of subarrays that start at `st`.
    for (int st = 0; st < size; st++)
    {
        // currSum will hold the running sum of a[st..end].
        // Reset it when we move to a new start index `st`.
        int currSum = 0;
        for (int end = st; end < size; end++)
        {
            // Extend the current subarray [st..end-1] by including a[end].
            currSum += a[end]; // Add element at 'end' to the running sum.
            // Now currSum == sum of a[st..end]; update the maximum if needed.
            maxSum = max(maxSum, currSum);
        }
        // finished all subarrays that start at 'st'
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

/*DRY RUN
a = {1, -5, -6, 7, 8}

st = 0:
currSum set to 0 before inner loop.
end = 0:
currSum += a[0] -> currSum = 0 + 1 = 1
maxSum = max(-inf, 1) = 1
end = 1:
currSum += a[1] -> currSum = 1 + (-5) = -4
maxSum = max(1, -4) = 1
end = 2:
currSum += a[2] -> currSum = -4 + (-6) = -10
maxSum = 1
end = 3:
currSum += a[3] -> currSum = -10 + 7 = -3
maxSum = 1
end = 4:
currSum += a[4] -> currSum = -3 + 8 = 5
maxSum = max(1, 5) = 5
(Leave inner loop; move to next st.)

st = 1:
currSum reset to 0.
end = 1:
currSum += a[1] -> currSum = 0 + (-5) = -5
maxSum = max(5, -5) = 5
end = 2:
currSum += a[2] -> currSum = -5 + (-6) = -11
maxSum = 5
end = 3:
currSum += a[3] -> currSum = -11 + 7 = -4
maxSum = 5
end = 4:
currSum += a[4] -> currSum = -4 + 8 = 4
maxSum = 5

st = 2:
currSum reset to 0.
end = 2:
currSum += a[2] -> currSum = -6
maxSum = 5
end = 3:
currSum += a[3] -> currSum = -6 + 7 = 1
maxSum = 5
end = 4:
currSum += a[4] -> currSum = 1 + 8 = 9
maxSum = max(5, 9) = 9

st = 3:
currSum reset to 0.
end = 3:
currSum += a[3] -> currSum = 7
maxSum = max(9,7) = 9
end = 4:
currSum += a[4] -> currSum = 7 + 8 = 15
maxSum = max(9,15) = 15

st = 4:
currSum reset to 0.
end = 4:
currSum += a[4] -> currSum = 8
maxSum = max(15,8) = 15
Final output printed by the program:
Maximum subarray sum = 15

------------------------------------------------------------

Notes comparing to the brute-force:

The brute-force recomputed currSum by looping from i = st to end every time. Here we reuse the previously computed currSum for the same st and add the newly exposed element a[end], which is why the inner-most per-element loop disappears and complexity drops from O(n^3) to O(n^2).
The result (15) is the same as the brute-force for this array; the subarray achieving it is [7,8] (a[3..4]).
*/