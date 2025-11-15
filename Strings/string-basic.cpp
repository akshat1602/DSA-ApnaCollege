#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "hello";
    cout<<str<<endl;

    str = "akshat";
    cout<<str<<endl;

 /*    string st2;
    cin>>st2;//doesnt store elements after space
    cout<<st2<<endl;  */

 /*    string str3;
    getline(cin, str3);
    cout<<str3<<endl; */

    string str4;
    getline(cin, str4, '*');//with delimiter : jaise hi woh likha in input toh uske aage ka kuch bhi display nhi hoga
    cout<<str4<<endl;
    return 0;
}