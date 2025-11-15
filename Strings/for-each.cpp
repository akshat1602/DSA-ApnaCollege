#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "akshat trivedi";

/*  for (int i = 0; i < str.length(); i++)
    { //accessing by 'dot' operator
        cout<<str[i]<<"-";
    }
    cout<<"\n"; 
*/

for(char ch : str){  //By for each loop
    cout<<ch<<",";
}
cout<<endl;
    
    return 0;
}