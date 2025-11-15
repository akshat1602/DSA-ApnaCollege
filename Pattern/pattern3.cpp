// Square Pattern
#include <iostream>
#include <string>
using namespace std;
int main()
{

for (int i = 0; i < 4; i++)//outer
{
    char ch = 'A';
    for (int j = 0; j < 4; j++)
    {
        cout<<ch;
        ch+=1;
    }
    cout<<endl;
    
}

return 0;
}