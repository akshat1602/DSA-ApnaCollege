//VERY IMPORTANT

#include <iostream>
#include <climits>
using namespace std;

int trap(int *heights, int size){
    int leftMax[20000], rightMax[20000];//size according to constraint
    leftMax[0] = heights[0];  
    rightMax[size - 1] = heights[size-1];
    
    //filling of aux. arrays.
    for (int i = 1; i < size; i++)//left se chalega
    {
        leftMax[i] = max(leftMax[i-1], heights[i]);
    }

    for (int i = size-2; i >= 0; i--)//right se chalega
    {
        rightMax[i] = max(rightMax[i+1], heights[i]);
    }
    
    //Finding Water trapped.
    int waterTrapped = 0;
    for (int i = 0; i < size; i++)
    {
        int currWater = min(leftMax[i], rightMax[i]) - heights[i];

        if(currWater > 0){ //to avoid unnecessary addition steps.
            waterTrapped+=currWater;
        }
    }
    return waterTrapped;
}

int main() {
    int heights[] = {4,2,0,6,3,2,5};
    int size = sizeof(heights)/sizeof(int);

    cout<<"Water Trapped = "<<trap(heights, size)<<endl;
    return 0;
}

/*
Revision notes - Trapping Rain Water

- Problem: Given an array `heights[]`, compute how much water is trapped after raining.

- Current implementation (in this file):
    * Builds two auxiliary arrays:
        - leftMax[i] = maximum height to the LEFT of index i (uses heights[i-1] when filling)
        - rightMax[i] = maximum height to the RIGHT of index i (uses heights[i+1] when filling)
    * Water at i = max(0, min(leftMax[i], rightMax[i]) - heights[i]). Sum over i.

- Complexity:
    * Time: O(n) — three linear passes (fill leftMax, fill rightMax, compute water)
    * Space: O(n) — two auxiliary arrays (leftMax, rightMax). Current code uses fixed-size arrays of 20000.

- Two-pointer alternative (O(1) extra space):
    * Use L=0, R=n-1, leftMax=0, rightMax=0
    * While L <= R:
            - if heights[L] <= heights[R]:
                    if heights[L] >= leftMax -> leftMax = heights[L]
                    else water += leftMax - heights[L]
                    L++
            - else:
                    if heights[R] >= rightMax -> rightMax = heights[R]
                    else water += rightMax - heights[R]
                    R--

- Common pitfalls / gotchas:
    * Off-by-one when filling left/right max arrays — ensure you use heights[i-1] and heights[i+1] correctly, and initialize the edges.
    * Negative currWater should be treated as 0 (this code checks currWater > 0 before adding).
    * Fixed-size auxiliary arrays may overflow for large inputs; prefer std::vector sized to `size`.
    * Be careful with integer overflow if heights or n are huge; consider 64-bit sums if needed.

**********Dry run (step-by-step) for the sample input in the code**********

heights = [4, 2, 0, 6, 3, 2, 5], size = 7

Compute leftMax (max to the left of i):
leftMax[0] = heights[0] = 4
leftMax[1] = max(leftMax[0], heights[0]) = max(4,4) = 4
leftMax[2] = max(leftMax[1], heights[1]) = max(4,2) = 4
leftMax[3] = max(leftMax[2], heights[2]) = max(4,0) = 4
leftMax[4] = max(leftMax[3], heights[3]) = max(4,6) = 6
leftMax[5] = max(leftMax[4], heights[4]) = max(6,3) = 6
leftMax[6] = max(leftMax[5], heights[5]) = max(6,2) = 6
So leftMax = [4, 4, 4, 4, 6, 6, 6]

Compute rightMax (max to the right of i):
rightMax[6] = heights[6] = 5
rightMax[5] = max(rightMax[6], heights[6]) = max(5,5) = 5
rightMax[4] = max(rightMax[5], heights[5]) = max(5,2) = 5
rightMax[3] = max(rightMax[4], heights[4]) = max(5,3) = 5
rightMax[2] = max(rightMax[3], heights[3]) = max(5,6) = 6
rightMax[1] = max(rightMax[2], heights[2]) = max(6,0) = 6
rightMax[0] = max(rightMax[1], heights[1]) = max(6,2) = 6
So rightMax = [6, 6, 6, 5, 5, 5, 5]

Compute trapped water per index:
For each i: currWater = min(leftMax[i], rightMax[i]) - heights[i]
i = 0: min(4,6) - 4 = 0 → add 0
i = 1: min(4,6) - 2 = 2 → add 2
i = 2: min(4,6) - 0 = 4 → add 4
i = 3: min(4,5) - 6 = -2 → treated as 0, add 0
i = 4: min(6,5) - 3 = 2 → add 2
i = 5: min(6,5) - 2 = 3 → add 3
i = 6: min(6,5) - 5 = 0 → add 0
Total water trapped = 0 + 2 + 4 + 0 + 2 + 3 + 0 = 11

---------------------------------------------------------------------------------------
Checks and quick tests

Edge arrays of length < 3 always trap 0 water.
Test monotonic arrays (strictly increasing or decreasing) → expected 0.
Test known examples and compare with two-pointer implementation to validate.

*/