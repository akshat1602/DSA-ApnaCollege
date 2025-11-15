#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  // For INT_MAX
using namespace std;

// Function to find the minimum difference between maximum and minimum chocolates 
// distributed among m students from packets in vector vec
int findMinDiff(vector<int> vec, int m) {
    int n = vec.size();

    // Step 1: Sort the packets by the number of chocolates
    // This arranges packets so that close values are together, making it easier to pick minimal difference sets
    sort(vec.begin(), vec.end());

    // Initialize minDiff with the largest possible integer value 
    // so any found difference will be smaller initially
    int minDiff = INT_MAX;

    // Step 2: Slide over vec with a window of size m (number of students)
    // and calculate the difference between the max and min in each window
    for (int i = 0; i + m - 1 < n; i++) {

        // The difference is between the last element in the current window 
        // and the first element in the window as array is sorted
        int diff = vec[i + m - 1] - vec[i];

        // Update minDiff if the current window's difference is smaller
        if (diff < minDiff)
            minDiff = diff;
    }

    // Step 3: Return the smallest difference found which guarantees the fairest distribution
    return minDiff;
}

int main() {
    // Example input: chocolates in each packet
    vector<int> vec = {7, 3, 2, 4, 9, 12, 56};
    // Number of students to distribute packets to
    int m = 3;

    cout << findMinDiff(vec, m);

    return 0;
}
