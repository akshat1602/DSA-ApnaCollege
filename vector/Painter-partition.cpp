#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> a, int n, int m, int maxAllowedTime) //O(n)
{
    int painters = 1, time = 0;

    for (int i = 0; i < n; i++)
    {
        if (time + a[i] <= maxAllowedTime)
        {
            time += a[i];
        }
        else
        {
            painters++;
            time = a[i];
        }
    }
    return painters <= m;
}

int minTimeToPaint(vector<int> &a, int n, int m)  //Olog(sum) *n --> TC
{
    int sum = 0, maxValue = INT32_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        maxValue = max(maxValue, a[i]);
    }

    int st = maxValue, end = sum, ans = -1;

    while (st <= end) //log(sum)
    {
        int mid = st + (end - st) / 2;
        if (isPossible(a, n, m, mid)) // Left
        {
            ans = mid;
            end = mid - 1;
        }
        else // Right
        {
            st = mid + 1;
        }
    }
}

int main()
{
    vector<int> a = {40, 30, 20, 10};
    int n = 4, m = 2;

    cout << minTimeToPaint(a, n, m) << endl;
    return 0;
}