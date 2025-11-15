#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector <char> ch = {'a', 'b', 'c','d'}; //initialized with elements
    cout<<ch.size()<<endl;
    cout<<ch.capacity()<<endl;
    for(char val : ch) //for each loop
    {
        cout<<val<<" ";
    }


return 0;
}