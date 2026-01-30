#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool isDuplicate(string str) //O(n)
{
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        if (ch != ')')
        { // non-closing
            s.push(ch);
        }

        else
        { // closing case
            if (s.top() == '(')
            {
                return true; // duplicate
            }

            while (s.top() != '(') // do pop till u get starting parentheses.
            {
                s.pop();
            }
            s.pop();
        }
    }

    return false;
}

int main()
{
    string str1 = "((a+b))";  // 1
    string str2 = "((a+b) + (c+d))"; // 0

    cout << isDuplicate(str1) << endl;
    cout << isDuplicate(str2) << endl;

    return 0;
}