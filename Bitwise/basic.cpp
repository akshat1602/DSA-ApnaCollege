//-ve numbers are stored as 2's complement in memory

#include <iostream>
#include <string>
using namespace std;
int main()
{
 int a=6,b=10;
 cout<<(a&b)<<endl;
 cout<<(a|b)<<endl;
 cout<<(a^b)<<endl;

 cout<<(~6)<<endl; // -7
 cout<<(~0)<<endl; // -1 

 cout<<(b<<2)<<endl;
 cout<<(b>>1)<<endl;

return 0;
}