//FOR SORTED ARRAY/VECTOR
//TS = 0(n) : time complexity, as its linear

#include <iostream>
#include <vector>
using namespace std;

vector <int> pairSum(vector <int> num, int target)
{
    vector <int> ans;
    int n = num.size();

    int st = 0, end = n-1;
    int PS = 0;

    while(st < end) //So that same number do baar add na hojaae
    {
        PS = num[st] + num[end]; //PAIRSUM
        if(PS > target) //sorted hai tabhi it works
        {
            end--;
        }
        else if(PS < target)
        {
            st++;
        }
        else
        {
        ans.push_back(st);
        ans.push_back(end);
        return ans;
        }
    }
}

int main()
{
    vector <int> num = {1,6,9,16};
    int target;
    cout<<"enter target : "<<endl;
    cin>>target;

    vector <int> ans = pairSum(num,target);
    cout<<ans[0]<<","<<ans[1]<<endl;

return 0;
}