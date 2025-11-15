#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool isSwap(string s1, string s2, int len){
    for (int i = 0; i < len; i++)
    {
        swap(s2[0], s2[len-1]);

        if(s1 == s2){
            return true;
        }
        else{
            return false;
        }
    }
    
}

int main() {
    string s1 = "bank";
    string s2 = "kanb";
    int len = s1.length(); // both of same length.

    isSwap(s1, s2, len);
    return 0;
}