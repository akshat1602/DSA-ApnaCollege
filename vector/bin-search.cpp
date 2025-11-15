#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector <int> a , int target)
{
    int st = 0, end = a.size() - 1;
    while(st<=end)
    {
        int mid = (st+end)/2;

        if(target < a[mid])
        end = mid-1;
        else if(target > a[mid])
        st = mid+1;
        else
        return mid;
    }
    return -1;
}
int main()
{
    vector <int> a1 = {-1,0,3,4,8,15};//even
    vector <int> a2 = {-1,0,3,4,8,15,19};//odd
    int target;
    cout<<"enter target : "<<endl;
    cin>>target;
    
    cout<<"ans : "<<binarysearch(a2,target)<<endl;


return 0;
}