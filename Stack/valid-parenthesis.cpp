#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool isValid(string str){ //O(n)
    stack <char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        }
        else{ //closing
            if(s.empty()){
                return false; //insufficient open brackets
            }

            //matching case
            int top = s.top();
            if((top == '(' && ch == ')') || (top == '[' && ch == ']') || (top == '{' && ch == '}')){
                s.pop();
            }
            else{
                return false;
            }
        }
    }

    return s.empty(); /* same as : 
                       if(s.empty()) return true;
                       else return false; */
}

int main() {
    string str1 = "([}])";
    string str2 = "([{}])";
    
    cout<<isValid(str1)<<endl; //invalid -> 0
    cout<<isValid(str2)<<endl; //valid -> 1
    return 0;
}