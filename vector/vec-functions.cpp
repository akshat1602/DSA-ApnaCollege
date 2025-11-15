#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector <int> nums;

    nums.push_back(10);
    nums.push_back(16);
    nums.push_back(5);
    
    
    cout<<"size after push_back : "<<nums.size()<<endl;
    cout<<nums.at(1)<<endl;

return 0;
}