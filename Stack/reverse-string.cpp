#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string reverseString(string str){ //O(n)
    string ans;
    stack <char> s;

    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }

    while(!s.empty()){ 
        char top = s.top();
        ans+=top;
        s.pop();
    }
    return ans;
};


int main() {
    string str = "akshat";
    cout<<reverseString(str)<<endl;

    return 0;
}