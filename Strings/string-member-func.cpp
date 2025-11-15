#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "akshat trivedi hello how are you hello";

    cout<<str.at(4)<<endl;
    cout<<str.substr(0,6)<<endl; //one less chalta last se
    cout<<str.find("hello")<<endl; //gives index of 1st occurence
    cout<<str.find("hello", 16)<<endl; //matlb 15 index ke baad kaha hello aaega woh btaega
    cout<<str.find("hi")<<endl; //-1 or garbage value == -1 only
    
    return 0;
}