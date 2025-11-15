#include <iostream>
#include <string>
using namespace std;
int main()
{
    char ch;
    cout << "enter the character" << "\n";
    cin >> ch;

    if (ch >= 65 && ch <= 90)
    {
        cout << "Uppercase alphabet";
    }
    else if (ch >= 97 && ch <= 122)
    {
        cout << "Lowercase alphabet";
    }
    else
    {
        cout << "not a character";
    }
    return 0;
}