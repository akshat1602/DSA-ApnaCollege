#include <iostream>
#include <vector>

using namespace std;

vector <int> pairSum(vector <int> nums, int target)
{ //as we are returning a vector as answer.

vector <int> ans;
int n = nums.size(); //how many elements does it contain

for (int i = 0; i < n; i++)
{
    for (int j = i+1; j < n ; j++)
    {
        if(nums[i] + nums[j] == target)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }  
}

}
int main()
{
  vector <int> nums = {2,7,11,6,3};

  int target; //target sum
  cout<<"enter target : "<<endl;
  cin>>target;

  vector <int> ans = pairSum(nums,target); //new vector to store the pair
  cout<<ans[0]<<" "<<ans[1]<<endl;
      

return 0;
}