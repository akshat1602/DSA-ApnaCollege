#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &a, int c, int n, int minAllowedDistance)
{

    int cows = 1, lastStallPos = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] - lastStallPos >= minAllowedDistance)
        {
            cows++;
            lastStallPos = a[i];
        }

        if (cows == c)
        {
            return true;
        }
    }
    return false;
}

int minMaxDistance(vector<int> &a, int c, int n)
{
     sort(a.begin(),a.end());

    int st = 1, end = a[n-1] - a[0], ans = 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isPossible(a, c, n, mid))
        {
            ans = mid;
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> a = {1, 2, 8, 4, 9};
    int c = 3, n = 5;

    cout << minMaxDistance(a, c, n) << endl;
    return 0;

    return 0;
}