//TC : O(n^3)

#include <iostream>
using namespace std;

void SubArraySum(int *a, int size){
    int maxSum = INT32_MIN; // -infinity almost, predefined macro.

    for (int st = 0; st<size; st++)
    {
        for (int end = st; end < size; end++)
        {
            int currSum = 0;
            for (int i = st; i <= end; i++)
            {
                currSum+=a[i];
            }
            cout<<currSum<<',';
            maxSum = max(maxSum, currSum);
        }
        cout<<endl;
    }
    cout<<"Maximum subarray sum = "<<maxSum<<endl;
}

int main() {
    int a[5]= {1,-5,-6,7,8};
    int size = 5;

    SubArraySum(a, size);
    
    return 0;
}


/* DRY RUN
a = {1, -5, -6, 7, 8}
st = 0:

end = 0: subarray [a0] = [1] -> currSum = 1 -> maxSum = max(-inf, 1) = 1
end = 1: subarray [a0..a1] = [1, -5] -> currSum = -4 -> maxSum = 1
end = 2: subarray [a0..a2] = [1, -5, -6] -> currSum = -10 -> maxSum = 1
end = 3: subarray [a0..a3] = [1, -5, -6, 7] -> currSum = -3 -> maxSum = 1
end = 4: subarray [a0..a4] = [1, -5, -6, 7, 8] -> currSum = 5 -> maxSum = max(1,5) = 5
(After finishing all ends for st=0 the program prints the five currSums separated by commas and a newline.)
st = 1:

end = 1: [-5] -> currSum = -5 -> maxSum = 5
end = 2: [-5,-6] -> currSum = -11 -> maxSum = 5
end = 3: [-5,-6,7] -> currSum = -4 -> maxSum = 5
end = 4: [-5,-6,7,8] -> currSum = 4 -> maxSum = 5
st = 2:

end = 2: [-6] -> currSum = -6 -> maxSum = 5
end = 3: [-6,7] -> currSum = 1 -> maxSum = 5
end = 4: [-6,7,8] -> currSum = 9 -> maxSum = max(5,9) = 9
st = 3:

end = 3: [7] -> currSum = 7 -> maxSum = 9
end = 4: [7,8] -> currSum = 15 -> maxSum = max(9,15) = 15
st = 4:

end = 4: [8] -> currSum = 8 -> maxSum = 15
Final printed maximum: Maximum subarray sum = 15

-----------------------------------------------------------------------------

HOW THE INDICES MOVE(single example walk-through)
Take the iteration st=2, end=4:

Outer loop set st = 2.
Middle loop sets end = 4 (it will iterate end=2,3,4).
Inner loop runs: i = 2 -> add a[2] (-6); i = 3 -> add a[3] (7); i = 4 -> add a[4] (8).
currSum computed as (-6 + 7 + 8) = 9.
Print 9, update maxSum if needed.
So i always runs from the current st to the current end inclusive.
*/