//TC : O(n).
//Imp Ques.
#include <climits>
#include <iostream>
using namespace std;

void maxProfit(int *prices, int size){
    int bestBuy[100000]; //constraint ka max size on leet
    bestBuy[0] = INT_MAX;

    for (int i = 1; i < size; i++) // loop for finding best buying prices of each day
    {
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
    }

    int maxProfit = 0;
    for (int i = 0; i < size; i++) //loop for finding profit
    {
        int currProfit = prices[i] - bestBuy[i]; //(profit = selling price - buying price)
        maxProfit = max(maxProfit, currProfit);
    }
    cout<<"max profit = "<<maxProfit<<endl;
}

int main() {
    int prices[] = {7,1,5,3,6,4};
    int size = sizeof(prices)/sizeof(int);
 
    maxProfit(prices, size);
    return 0;
}


/*
DRY RUN

Initial:

bestBuy[0] = INT_MAX (a large positive sentinel)
maxProfit = 0
First loop: compute bestBuy[i] = min(bestBuy[i-1], prices[i-1])

i = 1:
bestBuy[1] = min(bestBuy[0], prices[0]) = min(INT_MAX, 7) = 7

i = 2:
bestBuy[2] = min(bestBuy[1], prices[1]) = min(7, 1) = 1

i = 3:
bestBuy[3] = min(bestBuy[2], prices[2]) = min(1, 5) = 1

i = 4:
bestBuy[4] = min(bestBuy[3], prices[3]) = min(1, 3) = 1

i = 5:
bestBuy[5] = min(bestBuy[4], prices[4]) = min(1, 6) = 1
After first loop, bestBuy array (indices 0..5):

bestBuy[0] = INT_MAX
bestBuy[1] = 7
bestBuy[2] = 1
bestBuy[3] = 1
bestBuy[4] = 1
bestBuy[5] = 1


Second loop: compute profits and track maxProfit

i = 0:
currProfit = prices[0] - bestBuy[0] = 7 - INT_MAX -> a negative large value (but maxProfit = max(0, large negative) => remains 0)
Note: This iteration uses bestBuy[0] = INT_MAX, so it yields a nonsense negative profit; the code still works because maxProfit starts at 0 and remains non-negative. Still, it's unnecessary to compute profit at i=0 — can start loop at i=1 in practice.
maxProfit stays 0

i = 1:
currProfit = prices[1] - bestBuy[1] = 1 - 7 = -6
maxProfit = max(0, -6) = 0

i = 2:
currProfit = prices[2] - bestBuy[2] = 5 - 1 = 4
maxProfit = max(0, 4) = 4

i = 3:
currProfit = prices[3] - bestBuy[3] = 3 - 1 = 2
maxProfit = max(4, 2) = 4

i = 4:
currProfit = prices[4] - bestBuy[4] = 6 - 1 = 5
maxProfit = max(4, 5) = 5

i = 5:
currProfit = prices[5] - bestBuy[5] = 4 - 1 = 3
maxProfit = max(5, 3) = 5
Final printed output:
max profit = 5

-------------------------------------------------------
File summary (what the code does)

Function maxProfit(int *prices, int size) computes the maximum profit achievable by buying once and selling once.
Approach: for every day i, it precomputes bestBuy[i] = minimum price seen before day i (i.e., best buy price available up to i-1). Then it computes profit = prices[i] - bestBuy[i] and tracks the maximum.
Complexity: O(n) time, O(n) extra space (the bestBuy array). Note: bestBuy is sized for up to 100000 — this uses fixed large array memory; a single-pass variable reduces space to O(1).

-------------------------------------------------------
Notes on the code lines to watch

bestBuy[0] = INT_MAX — ensures first min check uses prices[0] as candidate when computing bestBuy[1] = min(INT_MAX, prices[0]) => prices[0]
The first for-loop fills bestBuy for indices 1..size-1; bestBuy[i] holds the minimal price among prices[0..i-1].
Second loop computes currProfit = prices[i] - bestBuy[i] (selling at day i, buying at best previous day).
maxProfit initialized to 0 — assumes no transaction yields non-negative profit; if all declines, profit remains 0 (which matches the typical "best single transaction" LeetCode problem semantics).
*/