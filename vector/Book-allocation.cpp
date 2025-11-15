#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &a, int n, int m, int maxAllowedPages) //O(n)
{
    int stu = 1, pages = 0;
    for (int i = 0; i <= n; i++)
    {
        if (a[i] > maxAllowedPages)
        {
            return -1;
        }
        if (pages + a[i] <= maxAllowedPages)
        {
            pages += a[i];
        }
        else
        {
            stu++;        // New Student
            pages = a[i]; // No of pages for new student
        }
    }
    return stu > m? false : true;
}

int allocateBooks(vector<int> &a, int n, int m) //O(logN * N) --> Time complexity for the solution
{
    if (m > n) // Edge Case
    {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) //O(n)
    {
        sum += a[i];
    }

    int ans = -1;
    int st = 0, end = sum; // Range in which we will find the answer

    while (st <= end) //O(logN)
    {
        int mid = st + (end - st) / 2;
        if (isValid(a, n, m, mid)) // For Left
        {
            ans = mid;
            end = mid - 1;
        }
        else // For Right
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector <int> a = {2,1,3,4};
    int n = 4, m = 2;

    cout<<allocateBooks(a,n,m)<<endl;
    return 0;
}