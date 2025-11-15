#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> a, int tar, int st, int end)
{
    while(st <= end)
    {
        int mid = st + (end - st) / 2;
        if (tar < a[mid])
        {
            return binarySearch(a, tar, st, mid - 1);
        }
        else if (tar > a[mid])
        {
            return binarySearch(a, tar, mid + 1, end);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {1, 4, 7, 8, 9, 17, 19};
    int st = 0;
    int end = a.size() - 1;
    int target;
    cout << "enter the target : " << endl;
    cin >> target;

    cout << "ans : " << binarySearch(a, target, st, end) << endl;

    return 0;
}